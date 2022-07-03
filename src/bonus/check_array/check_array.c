/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 06:34:58 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 06:36:34 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	check_array(size_t size, int *array)
{
	int	*sorted;

	sorted = duplicate_int_array(size, array);
	ft_mergesort(size, sorted);
	check_unique(size, sorted);
	free(sorted);
}
