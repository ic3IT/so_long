/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yipzhang <yipzhang@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/13 19:33:49 by yipzhang      #+#    #+#                 */
/*   Updated: 2024/01/13 20:24:26 by yipzhang      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_move(int keysym, t_data *game, int x, int y)
{
	if (keysym == 119)
	{
		if (game->map[y - 1][x] == '1')
			return (0);
	}
	if (keysym == 97)
	{
		if (game->map[y][x - 1] == '1')
			return (0);
	}
	if (keysym == 115)
	{
		if (game->map[y + 1][x] == '1')
			return (0);
	}
	if (keysym == 100)
	{
		if (game->map[y][x + 1] == '1')
			return (0);
	}
	return (1);
}

void	update_graphics(int keysym, t_data *game, int x, int y)
{
	if (keysym == 119)
	{
		draw_tile(game->mlx, game->win, game->img_blackTile, x, y);
		y -= 1;
		draw_tile(game->mlx, game->win, game->img_character, x, y);
	}
	if (keysym == 97)
	{
		draw_tile(game->mlx, game->win, game->img_blackTile, x, y);
		x -= 1;
		draw_tile(game->mlx, game->win, game->img_character, x, y);
	}
	if (keysym == 115)
	{
		draw_tile(game->mlx, game->win, game->img_blackTile, x, y);
		y += 1;
		draw_tile(game->mlx, game->win, game->img_character, x, y);
	}
	if (keysym == 100)
	{
		draw_tile(game->mlx, game->win, game->img_blackTile, x, y);
		x += 1;
		draw_tile(game->mlx, game->win, game->img_character, x, y);
	}
	game->char_x = x;
	game->char_y = y;
}

int	update_collectables(t_data *game)
{
	int	y;
	int	x;

	y = game->char_y;
	x = game->char_x;
	if (game->map[y][x] == 'C')
	{
		game->collectables += 1;
		game->map[y][x] = '0';
		return (0);
	}
}

int	all_collectables_collected_exit(int keysym, t_data *game, int x, int y)
{
	int	valid;

	valid = 0;
	if (keysym == 119)
	{
		if (game->map[y - 1][x] == 'E')
			valid = 1;
	}
	if (keysym == 97)
	{
		if (game->map[y][x - 1] == 'E')
			valid = 1;
	}
	if (keysym == 115)
	{
		if (game->map[y + 1][x] == 'E')
			valid = 1;
	}
	if (keysym == 100)
	{
		if (game->map[y][x + 1] == 'E')
			valid = 1;
	}
	if (game->collectables == game->all_collectables && valid == 1)
	{
		printf("You Collected %d Gems\n", game->collectables);
		on_destroy(game);
	}
	else if (valid == 1)
	{
		valid = 2;
	}
	return (valid);
}

int	on_destroy(t_data *game)
{
	int	row;

	if (game->img_background)
		mlx_destroy_image(game->mlx, game->img_background);
	if (game->img_character)
		mlx_destroy_image(game->mlx, game->img_character);
	if (game->img_blackTile)
		mlx_destroy_image(game->mlx, game->img_blackTile);
	if (game->img_collectable)
		mlx_destroy_image(game->mlx, game->img_collectable);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_tile)
		mlx_destroy_image(game->mlx, game->img_tile);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	row = 0;
	if (game->map)
	{
		while (game->map[row])
		{
			free(game->map[row]);
			row++;
		}
		free(game->map);
	}
	exit(0);
}
