#include "../includes/so_long.h"

int on_keypress(int keysym, t_data *game) {

	static int i = 0;
	if (keysym == 119) i++; //W
	if (keysym == 97) i++; //A
	if (keysym == 115) i++; //S
	if (keysym == 100) i++; //D

    if (keysym == 119 || keysym == 97 || keysym == 115 || keysym == 100)
		printf("You moved %d Times\n", i);
    return (0);
}


void	run_game(t_data *game, char *map_file, int map_width, int map_height)
{
	mlx_hook(game->win, KeyPress, KeyPressMask,  &on_keypress, &game);
}
