/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_start1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:09:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/22 19:26:49 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_until_appear_med(t_deque *element_list, t_deque *command_list, t_deques *deques);
static void	delete_back_ra(t_deque *command_list, t_deques *deques);

#include <stdio.h>

void	sort_a_start(t_deque *element_list, t_deque *command_list)
{
	t_deques	*deques;
	size_t		size;
	
	deques = create_deques();
	size = element_list -> size;
	deques -> large = size - (size + 2) / 3;
	deques -> small = (size - 1) / 3;
	printf("%d\n", deques -> large);
	printf("%d\n", deques -> small);
	sort_until_appear_med(element_list, command_list, deques);
	divide_a_start(element_list, command_list, deques);
	delete_back_ra(command_list, deques);
	// sort_a_maxvalue(deques -> large_q, command_list, deques -> large, size - 1);
	// sort_b_front(deques -> med_q, command_list, deques -> small + 1, deques -> large - 1);
	// sort_b_minvalue(deques -> small_q, command_list, 0, deques -> small);
	free(deques);
}

static void	sort_until_appear_med(t_deque *element_list, t_deque *command_list, t_deques *deques)
{
	int		number;

	while (element_list -> size)
	{
		number = ((t_node*)(element_list -> front)) -> content.number;
		if (number <= (deques -> small))
		{
			pushfront(deques -> small_q, popfront(element_list));
			pushback(command_list, create_command_node(pb));
		}
		else if (number >= (deques -> large))
		{
			pushback(deques -> large_q, popfront(element_list));
			pushback(command_list, create_command_node(ra));
		}
		else
			break;
	}
}

static void	delete_back_ra(t_deque *command_list, t_deques *deques)
{
	t_content	content;

	while (command_list -> size)
	{
		content.command = ((t_node*)(command_list -> back)) -> content.command;
		if (content.command == ra)
		{
			free(popback(command_list));
			pushfront(deques -> large_q, popback(deques -> large_q));
		}
		else
			break;
	}
}
