/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_out.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:43:06 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 00:46:19 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_OUT_H
# define CONSOLE_OUT_H
# include "deque.h"
# include "command.h"

void	print_commands(t_deque *commands);
#endif