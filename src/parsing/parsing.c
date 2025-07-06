/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:53:28 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/06 13:48:02 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	parsing(int argc, char **argv, t_info *info)
{
	if (!verif_pre_open(argc, argv))
		return (0);
	if (!open_file(argv[1], info))
		return (0);
	if (!file_is_valid(info))
		return (0);
	return (1);
}
