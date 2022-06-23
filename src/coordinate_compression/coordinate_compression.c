/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:20:08 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/23 20:18:27 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/coordinate_compression.h"

static size_t	get_index(size_t size, int *sorted, int x);

int	*coordinate_compression(size_t size, int **original, int **sorted)
{
	int		*res;
	size_t	i;

	res = malloc_and_checknull(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		res[i] = get_index(size, *sorted, (*original)[i]);
		i++;
	}
	free_and_setnull((void**)sorted);
	free_and_setnull((void**)original);
	return (res);
}

static size_t	get_index(size_t size, int *sorted, int x)
{
	size_t	begin;
	size_t	end;
	size_t	mid;

	begin = 0;
	end = size;
	while (end - begin > 1)
	{
		mid = (begin + end) / 2;
		if (sorted[mid] == x)
			return (mid);
		if (sorted[mid] < x)
			begin = mid + 1;
		if (sorted[mid] > x)
			end = mid;
	}
	return (begin);
}
