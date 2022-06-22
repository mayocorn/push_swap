/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:45:42 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/22 19:10:29 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	create_initial_deque(size_t size, int *array, t_deque *element_list);

t_deque	*push_swap(size_t size, int *array)
{
	t_deque	*command_list;
	t_deque	*element_list;

	command_list = create_deque();
	element_list = create_deque();
	create_initial_deque(size, array, element_list);
	sort_a_start(element_list, command_list);
	return (command_list);
}

static void	create_initial_deque(size_t size, int *array, t_deque *element_list)
{
	while(size--)
	{
		pushback(element_list, create_number_node(*array));
		array++;
	}
}

