/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:51:15 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/16 18:25:54 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H
# include <stdlib.h>
# include <unistd.h>

int		ft_min(int a, int b);
int		ft_max(int a, int b);
void	*ft_malloc(size_t size);
void	ft_free(void **ptr);
void	ft_exit(int status);
#endif