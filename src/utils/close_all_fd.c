/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:36:05 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 12:10:49 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	close_fd(int *fd)
{
	if (fd)
	{
		close(*fd);
		*fd = -1;
	}
}

void	close_all_fd(t_info *info)
{
	if (info->fd_map != -1)
		close_fd(&info->fd_map);
}
