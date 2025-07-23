/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:02:33 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/16 21:36:41 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static int	skip_white(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

static int	parse_one_value(char *str, int *i, int *value)
{
	*i = skip_white(str, *i);
	if (str[*i] < '0' || str[*i] > '9')
		return (error_message("Bad syntax for color\n"));
	*value = ft_atoi(&str[*i]);
	if (*value < 0 || *value > 255)
		return (error_message("Bad value for color, interval is [0, 255]\n"));
	while (str[*i] >= '0' && str[*i] <= '9')
		(*i)++;
	return (1);
}

static void	apply_color_shift(int *color, int value, int passage)
{
	if (passage == 0)
		*color |= (value << 16);
	else if (passage == 1)
		*color |= (value << 8);
	else
		*color |= value;
}

static int	check_separator(char *str, int *i, int passage)
{
	if (passage < 2)
	{
		*i = skip_white(str, *i);
		if (str[*i] != ',')
			return (error_message("Expected a comma separator\n"));
		(*i)++;
	}
	return (1);
}

int	convert_rgb_to_int(int *color, char *str)
{
	int i;
	int value;
	int passage;

	i = 0;
	passage = 0;
	*color = 0;
	while (passage < 3)
	{
		if (!parse_one_value(str, &i, &value))
			return (0);
		apply_color_shift(color, value, passage);
		if (!check_separator(str, &i, passage))
			return (0);
		passage++;
	}
	i = skip_white(str, i);
	if (str[i] != '\0' && str[i] != '\n')
		return (error_message("Extra characters after RGB color\n"));
	return (1);
}

int	get_color(t_info *info, char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	if (info->color_ceilling != -1 && info->color_floor != -1)
		return (2);
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
			return (close_all_fd(info), 0);
		else if (result == 2)
			return (1);
		free(str);
	}
	return (1);
}
