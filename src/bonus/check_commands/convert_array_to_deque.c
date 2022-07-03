/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_array_to_deque.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:19:35 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 06:13:04 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

t_deque	*convert_array_to_deque(size_t size, int *array)
{
	t_deque	*deque;

	deque = create_deque();
	while (size--)
	{
		pushback(deque, create_number_node(*array));
		array++;
	}
	return (deque);
}
