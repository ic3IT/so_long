#include "../includes/so_long.h"

int	on_keypress(int keysym, t_data *game)
{
	int			x;
	int			y;
	static int	i = 0;

	x = game->char_x;
	y = game->char_y;
	if (valid_move(keysym, game, x, y)) {
		i++;
		// update_collectables_and_exit(game);
		// all_collectables_collected_exit(keysym, game, x, y);
		if (all_collectables_collected_exit(keysym, game, x, y) == 2)
			return 0;
		update_graphics(keysym, game, x, y);
		update_collectables(game);
		if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
			printf("You moved %d Times\n", i);
		// update_collectables(game);

	}
	return (0);
}

void	run_game(t_data *game, char *map_file, int map_width, int map_height)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &on_keypress, game);
	mlx_loop(game->mlx);
}


// void update_map(t_data *game, int keysym) {
// 	static int i = 0;

// 	if (keysym == 119) {
// 		draw_tile(game->mlx, game->win, game->img_character, x, y - 1);
// 		draw_tile(game->mlx, game->win, game->img_blackTile, x, y);
// 		i++;
// 	// printf("%d", keysym);
// 	} //W
// 	if (keysym == 97) i++; //A
// 	if (keysym == 115) i++; //S
// 	if (keysym == 100) i++; //D
// }
