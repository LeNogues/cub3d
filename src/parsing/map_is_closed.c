/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:39:32 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 12:38:02 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	side(char c, int nb_pos)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (nb_pos != 0)
			return (-1);
		return (1);
	}
	return (0);
}

static int	border(char **map, int x, int y)
{
	if (y == 0 || x == 0)
		return (0);
	if (map[y + 1] == NULL)
		return (0);
	if ((int)ft_strlen(map[y - 1]) <= x || map[y - 1][x] == ' ')
		return (0);
	if ((int)ft_strlen(map[y + 1]) <= x || map[y + 1][x] == ' ')
		return (0);
	if (map[y][x - 1] == ' ' || map[y][x - 1] == '\0')
		return (0);
	if (map[y][x + 1] == ' ' || map[y][x + 1] == '\0')
		return (0);
	return (1);
}

int	map_is_closed(char **map)
{
	int	i;
	int	j;
	int	nb_pos;

	j = 0;
	nb_pos = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (side(map[j][i], nb_pos))
				nb_pos++;
			else if (side(map[j][i], nb_pos) == -1)
				return (0);
			if ((map[j][i] == '0' || side(map[j][i], 0)) && !border(map, i, j))
				return (0);
			i++;
		}
		j++;
	}
	if (nb_pos != 1)
		return (0);
	return (1);
}
