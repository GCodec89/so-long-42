/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:25:05 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/17 14:23:02 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_title(t_game *game, char *path, int x, int y)
{
	void	*new_img_ptr;

	new_img_ptr = mlx_xpm_file_to_image(game->mlx, path,
			&game->img->title_pos.x, &game->img->title_pos.y);
	if (new_img_ptr)
	{
		if (game->img->img_ptr)
		{
			mlx_destroy_image(game->mlx, game->img->img_ptr);
			game->img->img_ptr = NULL;
		}
		game->img->img_ptr = new_img_ptr;
		mlx_put_image_to_window(game->mlx, game->window, game->img->img_ptr,
			x, y);
	}
	else
	{
		ft_printf(ERROR_IMG_LOAD, path);
		free_structs(game);
		exit(EXIT_FAILURE);
	}
}

void	render(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->col)
	{
		y = 0;
		while (y < game->map->row)
		{
			if (game->map->matrix[y][x] == '0')
				put_title(game, "./img/0.xpm", (x * PIXEL), (y * PIXEL));
			else if (game->map->matrix[y][x] == '1')
				put_title(game, "./img/1.xpm", (x * PIXEL), (y * PIXEL));
			else if (game->map->matrix[y][x] == 'C')
				put_title(game, "./img/C.xpm", (x * PIXEL), (y * PIXEL));
			else if (game->map->matrix[y][x] == 'E')
				put_title(game, "./img/E.xpm", (x * PIXEL), (y * PIXEL));
			else if (game->map->matrix[y][x] == 'P')
				put_title(game, "./img/P.xpm", (x * PIXEL), (y * PIXEL));
			y++;
		}
		x++;
	}
}
