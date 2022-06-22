/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_start2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:37:49 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/22 19:26:25 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	move_small(t_deque *element_list, t_deque *command_list, t_deques *deques, t_deque *b_back);
static void	move_large(t_deque *element_list, t_deque *command_list, t_deques *deques, t_deque *b_back);
static void	move_med(t_deque *element_list, t_deque *command_list, t_deques *deques, t_deque *b_back);

void	divide_a_start(t_deque *element_list, t_deque *command_list, t_deques *deques)
{
	t_deque	*b_back;
	int		number;

	b_back = create_deque();
	while (element_list -> size)
	{
		number = ((t_node*)(element_list -> front)) -> content.number;
		if (number <= (deques -> small))
			move_small(element_list, command_list, deques, b_back);
		else if (number >= (deques -> large))
			move_large(element_list, command_list, deques, b_back);
		else
			move_med(element_list, command_list, deques, b_back);
	}
	free(element_list);
	free(b_back);
}

static void	move_small(t_deque *element_list, t_deque *command_list, t_deques *deques, t_deque *b_back)
{
	pushfront(b_back, popfront(element_list));
	pushback(command_list, create_command_node(pb));
}

static void	move_large(t_deque *element_list, t_deque *command_list, t_deques *deques, t_deque *b_back)
{
	pushback(deques -> large_q, popfront(element_list));
	pushback(command_list, create_command_node(ra));
	if (b_back -> size)
	{
		pushback(deques -> small_q, popfront(b_back));
		pushback(command_list, create_command_node(rb));
	}
}

static void	move_med(t_deque *element_list, t_deque *command_list, t_deques *deques, t_deque *b_back)
{
	while (b_back -> size)
	{
		pushback(deques -> small_q, popfront(b_back));
		pushback(command_list, create_command_node(rb));
	}
	pushfront(deques -> med_q, popfront(element_list));
	pushback(command_list, create_command_node(pb));
}
