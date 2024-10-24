/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_inits_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:44:07 by gonolive          #+#    #+#             */
/*   Updated: 2024/10/16 13:45:46 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_so_long.h"

static int	check_array(char *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] == '\n' && array[i + 1] == '\n')
			return (ft_printf(ERROR_EMPTY_LINE), 0);
		if (array[i] != '1' && array[i] != '0' && array[i] != 'C'
			&& array[i] != 'E' && array[i] != 'P' && array[i] != 'R'
			&& array[i] != '\n')
			return (ft_printf(ERROR_CHARS), 0);
		i++;
	}
	return (1);
}

char	**get_matrix(int fd)
{
	char	*line;
	char	*map_array;
	char	*tmp;
	char	**matrix;

	line = get_next_line(fd);
	map_array = NULL;
	while (line)
	{
		tmp = ft_strjoin(map_array, line);
		free(line);
		free(map_array);
		line = get_next_line(fd);
		map_array = tmp;
	}
	if (!map_array)
		return (ft_printf(ERROR_EMPTY_LINE), NULL);
	if (!check_array(map_array))
		return (free(map_array), NULL);
	matrix = ft_split(map_array, '\n');
	free(map_array);
	if (!matrix)
		return (ft_printf(ERROR_MALLOC), NULL);
	return (matrix);
}

int	count_rows(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		i++;
	}
	return (i);
}

t_point	char_position(char **matrix, char c)
{
	int		i;
	int		j;
	t_point	point;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
			{
				point.x = i;
				point.y = j;
				return (point);
			}
			j++;
		}
		i++;
	}
	point.x = -1;
	point.y = -1;
	return (point);
}

int	count_stuff(char **matrix, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == c)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}
