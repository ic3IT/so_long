#include "../includes/so_long.h"

int	on_keypress(int keysym, t_data *game)
{
	int			x;
	int			y;
	static int	i = 0;

	x = game->char_x;
	y = game->char_y;
	if (valid_move) {
		update_graphics(keysym, game, x, y);
		if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
			printf("You moved %d Times\n", i);
	}
	return (0);
}

void	run_game(t_data *game, char *map_file)
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
