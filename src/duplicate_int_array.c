/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_int_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:27:58 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/20 20:39:31 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/duplicate_int_array.h"

int	*duplicate_int_array(size_t size, int *src)
{
	int	*dest;

	dest = malloc_and_checknull(size * sizeof(int));
	ft_memmove(dest, src, size * sizeof(int));
	return (dest);
}