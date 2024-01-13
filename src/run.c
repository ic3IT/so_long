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
		if (keysym == 65307)
			on_destroy(game);
		if (all_collectables_collected_exit(keysym, game, x, y) == 2)
			return 0;
		update_graphics(keysym, game, x, y);
		update_collectables(game);
		if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
			printf("You moved %d Times\n", i);
		// printf("%d", game->character_count);

	}
	return (0);
}

void	run_game(t_data *game, char *map_file)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, &on_keypress, game);

	mlx_loop(game->mlx);
}

