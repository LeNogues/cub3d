/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:36:05 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/06 13:48:09 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	close_all_fd(t_info *info)
{
	if (info->fd_north != -1)
		close(info->fd_north);
	if (info->fd_south != -1)
		close(info->fd_south);
	if (info->fd_east != -1)
		close(info->fd_east);
	if (info->fd_west != -1)
		close(info->fd_west);
	if (info->fd_map != -1)
		close(info->fd_map);
}