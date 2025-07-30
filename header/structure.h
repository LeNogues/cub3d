/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:45:32 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/30 11:58:46 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_text
{
	int		img_width;
	int		img_height;
	void	*img_ptr;
}					t_text;

typedef struct s_map
{
	size_t		map_width;
	size_t		map_height;
	char		**map;
}					t_map;

typedef struct s_link_map
{
	int			x;
	int			y;
	char		*value;
	struct s_link_map	*next;
}					t_link_map;

typedef struct s_info
{
	t_text	*north;
	t_text	*south;
	t_text	*east;
	t_text	*west;
	t_map	*map;
	int		fd_map;
	int		color_floor;
	int		color_ceilling;
	void	*mlx;
	void	*win;
	void	*img;
	void	*buffer;
	char	*str;
	double	px;
	double	py;
}					t_info;




#endif