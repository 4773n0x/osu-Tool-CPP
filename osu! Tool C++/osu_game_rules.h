#pragma once

#include "osu_score.h"

namespace osu
{
	class game_rules
	{
	public:
		static float get_hit_window_300(float overall_difficulty);
		static float get_hit_window_100(float overall_difficulty);
		static float get_hit_window_50(float overall_difficulty);
		static float get_hit_window_miss();
		static score::hit get_hit_result(float delta, float overall_difficulty);

	private:
		static float map_difficulty_range(float scaled_diff, float min, float mid, float max);
	};
}
