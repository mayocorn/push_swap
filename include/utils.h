/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:51:15 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/21 08:54:43 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# define SUCCESS 0
# define ERROR 1

int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	*malloc_and_checknull(size_t size);
void	free_and_setnull(void **ptr);
void	ft_exit(int status);
#endif