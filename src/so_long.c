#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	game;

	int map_width, map_height;
	if (argc == 2)
	{
		parse_map(&game, argv[1], &map_width, &map_height);
		start_game(&game, argv[1], map_width, map_height);
	}
	else
	{
		printf("Usage: %s <map_file>\n", argv[0]);
	}
	return (0);
}
