/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:02:33 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/08 12:08:30 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	convert_rgb_to_int(int *color, char *str)
{
	(void)color;
	int i;

	i = 0;
	while(str[i] == ' ')
		i++;
	if (str[i] == '\n')
		return (error_message("need a color for floor or ceilling\n"));
	return (1);
}

int	get_color(t_info *info, char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while(str[i] == ' ')
		i++;
	if (str[i] == 'F')
		result = convert_rgb_to_int(&info->color_floor, &str[i + 1]);
	else if (str[i] == 'C')
		result = convert_rgb_to_int(&info->color_ceilling, &str[i + 1]);
	return (result);
}

int	setup_valid(t_info *info)
{
	char	*str;
	int		result;
	
	while(1)
	{
		result = 0;
		str = get_next_line(info->fd_map);
		if (!str)
			return (close_all_fd(info), 0);
		if (str[0] == 'N' && str[1] == 'O')
			result = open_fd(&info->fd_north, str + 2);
		else if (str[0] == 'S' && str[1] == 'O')
			result = open_fd(&info->fd_south, str + 2);
		else if (str[0] == 'W' && str[1] == 'E')
			result = open_fd(&info->fd_west, str + 2);
		else if (str[0] == 'E' && str[1] == 'A')
			result = open_fd(&info->fd_east, str + 2);
		else 
			result = get_color(info, str);
		if (result == 0 && str[0] != '\n')
		{
			printf("%s\n", str);
			return (close_all_fd(info), 0);
		}
		free(str);
	}
	return (1);
}
