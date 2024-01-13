#include "../includes/so_long.h"

int valid_map(t_data *game, int *map_height) {
	int i = 1;
	int current_len;
	int previous_len = ft_strlen(game->map[0]);

	while (game->map[i]) {
		current_len = ft_strlen(game->map[i]);
		if (current_len != previous_len)
			return 0;
		i++;
	}
	int row = 0;
while (row < (*map_height - 1)) {
    int row_length = ft_strlen(game->map[row]);
    if (game->map[row][0] != '1' || game->map[row][row_length - 1] != '1')
        return 0;
    row++;
}

	i = 0;
	while (game->map[0][i]) {
		if (game->map[0][i] != '1')
			return 0;
		i++;
	}
	i = 0;
	i = 0;  // Reset i to 0
while (game->map[*map_height - 1][i] != '\0') {  // Iterate through the last row
    if (game->map[*map_height - 1][i] != '1')
        return 0;
    i++;
}
return 1;

}


