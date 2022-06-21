/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:27:58 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/21 15:22:05 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/array.h"

int	*duplicate_int_array(size_t size, int *src)
{
	int	*dest;

	dest = malloc_and_checknull(size * sizeof(int));
	ft_memmove(dest, src, size * sizeof(int));
	return (dest);
}

void check_unique(size_t size, int *array)
{
	while(size > 1)
	{
		if (*array == *(array + 1))
			ft_exit(ERROR);
		array++;
		size--;
	}
}