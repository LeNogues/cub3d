/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:45:32 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/07 14:31:06 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_info
{
	int	fd_north;
	int	fd_east;
	int	fd_south;
	int	fd_west;
	int	fd_map;
	int	color_floor;
	int	color_ceilling;
}					t_info;

#endif