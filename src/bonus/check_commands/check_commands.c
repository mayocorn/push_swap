/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:55:23 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 16:15:04 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	check_commands(size_t array_size, int *array)
{
	t_deque	*commands;
	t_deque	*stack_a;
	t_deque	*stack_b;

	commands = create_deque();
	read_commands(commands);
	stack_a = convert_array_to_deque(array_size, array);
	free_and_setnull((void **)&array);
	stack_b = create_deque();
	pushswap_by_commands(commands, stack_a, stack_b);
	check_sorted(stack_a, stack_b);
	delete_deque(commands);
	delete_deque(stack_a);
	delete_deque(stack_b);
}
