/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_is_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:02:33 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/06 13:50:26 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	forth_line_valid(t_info *info)
{
	char	*str;
	int		length;

	str = get_next_line(info->fd_map);
	if (!str)
		return (0);
	if (str[0] != 'E' || str[1] != 'A')
		return (free(str), error_message("[ERROR SYNTAX] forth line"));
	str = str + 3;
	length = ft_strlen(str);
	str[length - 1] = 0;
	info->fd_east = open(str, O_RDONLY);
	if (info->fd_east == -1)
		return (free(str - 3), error_message("couldn't open east texture\n"));
	free(str - 3);
	return (1);
}

static int	third_line_valid(t_info *info)
{
	char	*str;
	int		length;

	str = get_next_line(info->fd_map);
	if (!str)
		return (0);
	if (str[0] != 'W' || str[1] != 'E')
		return (free(str), error_message("[ERROR SYNTAX] third line"));
	str = str + 3;
	length = ft_strlen(str);
	str[length - 1] = 0;
	info->fd_west = open(str, O_RDONLY);
	if (info->fd_west == -1)
		return (free(str - 3), error_message("couldn't open west texture\n"));
	free(str - 3);
	if (!forth_line_valid(info))
	{
		close(info->fd_west);
		return (0);
	}
	return (1);
}

static int	second_line_valid(t_info *info)
{
	char	*str;
	int		length;

	str = get_next_line(info->fd_map);
	if (!str)
		return (0);
	if (str[0] != 'S' || str[1] != 'O')
		return (free(str), error_message("[ERROR SYNTAX] second line"));
	str = str + 3;
	length = ft_strlen(str);
	str[length - 1] = 0;
	info->fd_south = open(str, O_RDONLY);
	if (info->fd_south == -1)
		return (free(str - 3), error_message("couldn't open south texture\n"));
	free(str - 3);
	if (!third_line_valid(info))
	{
		close(info->fd_south);
		return (0);
	}
	return (1);
}

int	first_line_valid(t_info *info)
{
	char	*str;
	int		length;

	str = get_next_line(info->fd_map);
	if (!str)
		return (0);
	if (str[0] != 'N' || str[1] != 'O')
		return (free(str), error_message("[ERROR SYNTAX] first line"));
	str = str + 3;
	length = ft_strlen(str);
	str[length - 1] = 0;
	info->fd_north = open(str, O_RDONLY);
	if (info->fd_north == -1)
		return (free(str - 3), error_message("couldn't open north texture\n"));
	free(str - 3);
	if (!second_line_valid(info))
	{
		close(info->fd_north);
		return (0);
	}
	return (1);
}
