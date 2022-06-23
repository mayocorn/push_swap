/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:09:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 00:37:43 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_until_appear_med(t_deques *deques);
static void	divide_a_start(t_deques *deques);
static void	delete_back_ra(t_deques *deques);

void	sort_a_start(t_deque *elements, t_deque *commands)
{
	t_deques	*deques;
	size_t		size;
	
	deques = create_deques(elements, commands);
	free_and_setnull((void **)&(deques -> ab));
	size = elements -> size;
	deques -> large = size - (size + 2) / 3;
	deques -> small = (size + 1) / 3 - 1;
	sort_until_appear_med(deques);
	divide_a_start(deques);
	delete_back_ra(deques);
	// sort_a_maxvalue(deques -> large_q, commands, deques -> large);
	// sort_b_front(deques -> med_q, commands, deques -> small + 1, deques -> large - 1);
	// sort_b_minvalue(deques -> small_q, commands, 0, deques -> small);
	free(deques);
}

static void	sort_until_appear_med(t_deques *deques)
{
	int		number;
	t_deque	*elements;

	elements = deques -> elements;
	while (elements -> size)
	{
		number = ((t_node *)(elements -> front))-> content.number;
		if (number <= (deques -> small))
			popfront_and_pushfront(deques, deques -> bb, pb);
		else if (number >= (deques -> large))
			popfront_and_pushback(deques, deques -> af, ra);
		else
			break ;
	}
}

static void	divide_a_start(t_deques *deques)
{
	t_deque	*hold;
	t_deque	*elements;
	int		number;

	hold = create_deque();
	elements = deques -> elements;
	while (elements -> size)
	{
		number = ((t_node *)(elements -> front)) -> content.number;
		if (number <= (deques -> small))
			popfront_and_pushfront(deques, hold, pb);
		else if (number >= (deques -> large))
			move_hold_one((t_hold_info){hold, deques -> bb, elements, \
									deques -> af, deques -> commands, rb, ra});
		else
		{
			move_hold_all(hold, deques -> bb, deques -> commands, rb);
			popfront_and_pushfront(deques, deques -> bf, pb);
		}
	}
	delete_deque(elements);
	move_hold_all(hold, deques -> bb, deques -> commands, rb);
	delete_deque(hold);
}

static void	delete_back_ra(t_deques *deques)
{
	t_content	content;
	t_deque		*commands;

	commands = deques -> commands;
	while (commands -> size)
	{
		content.command = ((t_node *)(commands -> back))-> content.command;
		if (content.command == ra)
		{
			free(popback(commands));
			pushfront(deques -> af, popback(deques -> af));
		}
		else
			break ;
	}
}
