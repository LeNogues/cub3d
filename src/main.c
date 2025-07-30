/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:48:42 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 12:38:35 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_info	*info;
	int		i;

	i = 0;
	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	if (!init_info(info))
		return (free(info), 0);
	if (!parsing(argc, argv, info))
		return (free_clean(info), 0);
	while (info->map->map[i])
	{
		printf("%s", info->map->map[i]);
		i++;
	}
	free_clean(info);
	return (1);
}
