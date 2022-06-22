/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:45:42 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/22 12:15:21 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_deque	*push_swap(size_t size, int *array)
{
	t_deque	*command_list;
	t_deque	*element_list;

	command_list = create_deque();
	element_list = create_deque();
	push_swap_start();
	
	return (command_list);
}