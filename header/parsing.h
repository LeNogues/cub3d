/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:02:14 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/06 13:46:35 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "structure.h"

//  --- verif_pre_open.c --- //
int	verif_pre_open(int argc, char **argv);
int	nb_arg(int nb);
int	end_with_cub(char *argv);
//  ---verif_pre_open.c --- //

//  --- open_file.c --- //
int	open_file(char *path, t_info *info);
//  --- open_file.c --- //

//  --- file_is_valid.c --- //
int	file_is_valid(t_info *info);
//  --- file_is_valid.c --- //

//  --- line_is_valid.c --- //
int	first_line_valid(t_info *info);
//  --- line_is_valid.c --- //

int	parsing(int argc, char **argv, t_info *info);

#endif
