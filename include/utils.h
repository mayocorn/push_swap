/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:51:15 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:46:19 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>

void	*malloc_and_checknull(size_t size);
void	free_and_setnull(void **ptr);
void	ft_exit(int status);
int		ft_min(int a, int b);
#endif