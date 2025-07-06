/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:01:15 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/06 14:27:43 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_floor_color(t_info *info)
{
	char	*str;
	int		i;
	
	i = 0;
	str = get_next_line(info->fd_map);
	if (!str)
		return (0);
	if (str[0] != 'F' || str[1] != ' ')
		return (error_message("wrong syntax for floor color"));

}

int	get_color(t_info *info)
{
	char *str;

	str = get_next_line(info->fd_map);
	if (!str)
		return (0);
	if (str[0] != '\n')
		return (error_message("need empty line after text_path\n"));
	free(str);
	if (!get_floor_color(info))
		return (0);
	return (1);
}

int	file_is_valid(t_info *info)
{
	if (!first_line_valid(info))
	{
		close(info->fd_map);
		return (0);
	}
	if (!get_color(info))
	{
		close_all_fd(info);
		return (0);
	}
	return (1);
}
