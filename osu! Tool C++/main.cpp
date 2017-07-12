#include "play.h"
#include "settings.h"

#include <iostream>
#include <thread>

int main()
{
	try
	{
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
