/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-nogu <sle-nogu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:17:57 by sle-nogu          #+#    #+#             */
/*   Updated: 2025/07/08 11:44:07 by sle-nogu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structure.h"

//  --- error_mesage.c --- //
int		error_message(char *str);
int		error_message_bis(char *str, char *str2);
//  --- error_mesage.c --- //

//	---close_all_fd.c --- //
void	close_all_fd(t_info *info);
void	close_fd(int *fd);
//	---close_all_fd.c --- //

//	---init_fd.c --- ///
void	init_info(t_info *info);
int	    open_fd(int *fd, char *str);
//	---init_fd.c --- ///

#endif
