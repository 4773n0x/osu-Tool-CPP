#include "play.h"
#include "settings.h"
#include "config.h"

#include <iostream>
#include <thread>

void load_settings()
{
	using namespace settings;

	cfg::config c("Settings.txt", "=");

	c.set_key("program_window_title", program_window_title);
	c.set_key("osu_window_title", osu_window_title);
	c.set_key("relax_primary_key", relax_primary_key);
	c.set_key("relax_secondary_key", relax_secondary_key);
	c.set_key("relax_tapping_style", relax_tapping_style);
	c.set_key("relax_offset", relax_offset);
	c.set_key("relax_hit_scan", relax_hit_scan);
	c.set_key("relax_hit_scan_circle_offset", relax_hit_scan_circle_offset);

	c.load();
}

int main()
{
	try
	{
		load_settings();
		SetConsoleTitle(settings::program_window_title.c_str());
		cheat c;

		while (true)
		{
			if (c.is_map_playing())
			{
				play p;
				p.run(c, osu::beatmap(c.get_current_song_path()), *c.get_osu_window());
			}

			std::this_thread::sleep_for(std::chrono::milliseconds(1));
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << '.' << std::endl;
		std::cout << "Press any key to exit...";
		std::getchar();
	}
}
