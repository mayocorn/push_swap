/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:45:42 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 14:25:23 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	create_initial_deque(size_t size, int *array, t_deque *elements);

t_deque	*push_swap(size_t size, int **array)
{
	t_deque	*commands;
	t_deque	*elements;

	commands = create_deque();
	elements = create_deque();
	create_initial_deque(size, *array, elements);
	free_and_setnull((void **)array);
	sort_a_start(elements, commands);
	return (commands);
}

static void	create_initial_deque(size_t size, int *array, t_deque *elements)
{
	while (size--)
	{
		pushback(elements, create_number_node(*array));
		array++;
	}
}
