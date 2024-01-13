#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	game = {0}; // Initialize all fields of game to 0

	int map_width = 0, map_height = 0; // Initialize map dimensions

	if (argc == 2)
	{
		parse_map(&game, argv[1], &map_width, &map_height);
		start_game(&game, map_width, map_height);
		run_game(&game, argv[1]);
	}
	else
	{
		printf("Usage: %s <map_file>\n", argv[0]);
	}
	return (0);
}
