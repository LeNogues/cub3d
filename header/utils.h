/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:17:57 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/06 13:46:23 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structure.h"

//  --- error_mesage.c --- //
int		error_message(char *str);
//  --- error_mesage.c --- //

//	---close_all_fd.c --- //
void	close_all_fd(t_info *info);
//	---close_all_fd.c --- //

//	---init_fd.c --- ///
void	init_fd(t_info *info);
//	---init_fd.c --- ///

#endif
