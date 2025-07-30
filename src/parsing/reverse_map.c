/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 13:50:22 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 12:08:53 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	reverse_map(t_map *map, char **map_patern)
{
	int		i;
	int		row_bis;
	int		row;
	char	tmp;

	row = 0;
	row_bis = map->map_height - 1;
	while (row <= (int)map->map_height / 2)
	{
		i = 0;
		while (map_patern[row][i])
		{
			tmp = map_patern[row][i];
			map_patern[row][i] = map_patern[row_bis][i];
			map_patern[row_bis][i] = tmp;
			i++;
		}
		row++;
		row_bis--;
	}
	return (1);
}
