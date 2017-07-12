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

		const static int hit_window_300_min = 80;
		const static int hit_window_300_mid = 50;
		const static int hit_window_300_max = 20;
		const static int hit_window_100_min = 140;
		const static int hit_window_100_mid = 100;
		const static int hit_window_100_max = 60;
		const static int hit_window_50_min = 200;
		const static int hit_window_50_mid = 150;
		const static int hit_window_50_max = 100;
		const static int hit_window_miss = 400;
	};
}
