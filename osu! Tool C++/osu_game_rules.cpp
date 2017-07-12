#include "osu_game_rules.h"

#include <cmath>

namespace osu
{
	float game_rules::map_difficulty_range(float scaled_diff, float min, float mid, float max)
	{
		if (scaled_diff > 5.0f)
			return mid + (max - mid) * (scaled_diff - 5.0f) / 5.0f;

		if (scaled_diff < 5.0f)
			return mid - (mid - min) * (5.0f - scaled_diff) / 5.0f;

		return mid;
	}

	float game_rules::get_hit_window_300(float overall_difficulty)
	{
		return map_difficulty_range(overall_difficulty, 80, 50, 20);
	}

	float game_rules::get_hit_window_100(float overall_difficulty)
	{
		return map_difficulty_range(overall_difficulty, 140, 100, 60);
	}

	float game_rules::get_hit_window_50(float overall_difficulty)
	{
		return map_difficulty_range(overall_difficulty, 200, 150, 100);
	}

	float game_rules::get_hit_window_miss()
	{
		return 400;
	}

	score::hit game_rules::get_hit_result(float delta, float overall_difficulty)
	{
		delta = std::abs(delta);

		score::hit result = score::hit::null;

		if (delta <= get_hit_window_300(overall_difficulty))
			result = score::hit::hit_300;
		else if (delta <= get_hit_window_100(overall_difficulty))
			result = score::hit::hit_100;
		else if (delta <= get_hit_window_50(overall_difficulty))
			result = score::hit::hit_50;
		else if (delta <= get_hit_window_miss())
			result = score::hit::miss;

		return result;
	}
}
