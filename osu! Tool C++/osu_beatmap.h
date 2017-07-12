#pragma once

#include "vector2.h"

#include <string>
#include <vector>

namespace osu
{
	const static vector2 beatmap_playfield(512, 384);

	enum class beatmap_mode
	{
		standard,
		taiko,
		catch_the_beat,
		mania
	};

	struct beatmap_general
	{
		beatmap_mode mode;
		float stack_leniency;
	};

	struct beatmap_difficulty
	{
		float hp_drain_rate;
		float circle_size;
		float overall_difficulty;
		float approach_rate;
		float slider_multiplier;
		float slider_tick_rate;
	};

	struct beatmap_timing_point
	{
		float offset;
		float ms_per_beat;
		int meter;
		float velocity;
	};

	enum hit_object_type
	{
		hit_object_circle = 1,
		hit_object_slider = 2,
		hit_object_spinner = 8
	};

	enum class hit_object_slider_type
	{
		linear = 'L',
		perfect = 'P',
		bezier = 'B',
		catmull = 'C'
	};

	struct beatmap_hit_object
	{
		vector2 coordinates;
		int start_time;
		int end_time;
		int type;
		hit_object_slider_type slider_type;
		std::vector<vector2> slider_coordinates;
		int slider_repeat;
		float slider_pixel_length;

		bool is_circle() const
		{
			return (type & hit_object_circle) == hit_object_circle;
		}

		bool is_slider() const
		{
			return (type & hit_object_slider) == hit_object_slider;
		}

		bool is_spinner() const
		{
			return (type & hit_object_spinner) == hit_object_spinner;
		}
	};

	class beatmap
	{
	public:
		beatmap(const std::string& path, bool ez = false, bool hr = false);

		beatmap_timing_point get_timing_point_from_offset(float offset) const;

		const beatmap_general& get_general() const { return general; }
		const beatmap_difficulty& get_difficulty() const { return difficulty; }
		const std::vector<beatmap_timing_point>& get_timing_points() const { return timing_points; }
		const std::vector<beatmap_hit_object>& get_hit_objects() const { return hit_objects; }
		float get_circle_radius() const { return circle_radius; }

	private:
		void parse_general(const std::string& line);
		void parse_difficulty(const std::string& line, bool ez, bool hr, bool& found_ar);
		void parse_timing_points(const std::string& line, float& last_ms_per_beat);
		void parse_hit_objects(const std::string& line);

		beatmap_general general;
		beatmap_difficulty difficulty;
		std::vector<beatmap_timing_point> timing_points;
		std::vector<beatmap_hit_object> hit_objects;
		float circle_radius;
	};
}
