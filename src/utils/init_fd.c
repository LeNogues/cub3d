/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:13:02 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/08 11:43:02 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	open_fd(int *fd, char *str)
{
	int i;

	i = 0;
	if (*fd != -1)
		return(error_message("fd already open\n"));
	while(str[i] == ' ')
		i++;
	str[ft_strlen(str) - 1] = 0;
	*fd = open(&str[i], O_RDONLY);
	if (*fd == -1)
		return (error_message_bis("can't open fd : \n", str));
	return (1);
}

void	init_info(t_info *info)
{
	info->fd_north = -1;
	info->fd_south = -1;
	info->fd_west = -1;
	info->fd_east = -1;
	info->fd_map = -1;
	info->color_ceilling = -1;
	info->color_floor = -1;
}
