/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:10:13 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/02 15:36:35 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>

int		ft_isdigit(int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
#endif