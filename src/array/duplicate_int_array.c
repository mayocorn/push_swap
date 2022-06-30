/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_int_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 03:52:08 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 03:52:49 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/array.h"

int	*duplicate_int_array(size_t size, int *src)
{
	int	*dest;

	dest = malloc_and_checknull(size * sizeof(int));
	ft_memmove(dest, src, size * sizeof(int));
	return (dest);
}
