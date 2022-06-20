/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:23:31 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/20 20:04:38 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mergesort.h"

static void	merge_array(size_t a_size, size_t b_size, \
						int *array_a, int *array_b);

void	mergesort(size_t	array_size, int	*array)
{
	int		*array_a;
	int		*array_b;
	size_t	a_size;
	size_t	b_size;

	if (array_size <= 1)
		return ;
	a_size = array_size / 2;
	b_size = array_size - a_size;
	array_a = array;
	array_b = array + a_size;
	mergesort(a_size, array_a);
	mergesort(b_size, array_b);
	merge_array(a_size, b_size, array_a, array_b);
}

static void	merge_array(size_t a_size, size_t b_size, \
						int *array_a, int *array_b)
{
	int		*array;
	int		*tmp;
	size_t	array_size;

	array = array_a;
	tmp = malloc_and_checknull(array_size * sizeof(int));
	array_size = a_size + b_size;
	while (a_size || b_size)
	{
		if (b_size == 0 || (a_size != 0 && *array_a < *array_b))
		{
			*(tmp++) = *(array_a++);
			a_size--;
		}
		else
		{
			*(tmp++) = *(array_b++);
			b_size--;
		}
	}
	tmp -= array_size;
	ft_memmove(array, tmp, array_size * sizeof(int));
	free_and_setnull(&tmp);
}
