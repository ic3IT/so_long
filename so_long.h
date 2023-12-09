#ifndef SO_LONG_H
	#define SO_LONG_H

#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <math.h>

#define WINDOW_WIDTH 960	
#define WINDOW_HEIGHT 640
#define TILE_SIZE 64

char	*get_next_line(int fd);
int		ft_newline(char *s);

#endif
