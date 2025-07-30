/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:13:02 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 12:10:20 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	open_fd(int *fd, char *str)
{
	int	i;

	i = 0;
	if (*fd != -1)
		return (error_message("fd already open\n"));
	while (str[i] == ' ')
		i++;
	str[ft_strlen(str) - 1] = 0;
	*fd = open(&str[i], O_RDONLY);
	if (*fd == -1)
		return (error_message_bis("can't open fd : \n", str));
	return (1);
}

int	init_mlx(t_info *info)
{
	info->map->map = NULL;
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		return (0);
	info->win = mlx_new_window(info->mlx, 1000, 800, "cub3d null");
	if (info->win == NULL)
		return (free(info->mlx), 0);
	return (1);
}

int	init_info(t_info *info)
{
	info->fd_map = -1;
	info->color_ceilling = -1;
	info->color_floor = -1;
	info->map = malloc(sizeof(t_map));
	if (!info->map)
		return (0);
	info->map->map_height = 0;
	info->map->map_width = 0;
	info->north = malloc(sizeof(t_text));
	info->south = malloc(sizeof(t_text));
	info->east = malloc(sizeof(t_text));
	info->west = malloc(sizeof(t_text));
	if (!info->north | !info->south | !info->west | !info->east)
	{
		free_texture(info);
		free(info->map);
		return (error_message("problem during texture initialisation\n"));
	}
	info->north->img_ptr = NULL;
	info->south->img_ptr = NULL;
	info->east->img_ptr = NULL;
	info->west->img_ptr = NULL;
	if (!init_mlx(info))
		return (error_message("problem during mlx initialisation\n"));
	return (1);
}

int	init_text(t_text *side, void *mlx, char *str)
{
	int		i;
	char	*str_final;

	i = skip_white(str, 0);
	str_final = ft_strdup(str + i);
	if (!str_final)
		return (-1);
	str_final[ft_strlen(str_final) - 1] = 0;
	side->img_ptr = mlx_xpm_file_to_image(mlx, str_final, &side->img_width,
			&side->img_height);
	if (!side->img_ptr)
		return (free(str_final), -1);
	free(str_final);
	return (1);
}
