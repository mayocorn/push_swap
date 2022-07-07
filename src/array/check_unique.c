/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unique.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:27:58 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:46:50 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.h"

void	check_unique(size_t size, int *array)
{
	while (size > 1)
	{
		if (*array == *(array + 1))
			ft_exit(EXIT_FAILURE);
		array++;
		size--;
	}
}
