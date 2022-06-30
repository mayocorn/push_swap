/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:51:15 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 04:55:01 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <stdlib.h>
# include <unistd.h>
# define SUCCESS 0
# define ERROR 1

void	*malloc_and_checknull(size_t size);
void	free_and_setnull(void **ptr);
void	ft_exit(int status);
#endif