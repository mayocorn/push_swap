/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:36:00 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/29 19:04:49 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	divide_b_back(t_div_info *div_info);
static void	move_large_all(t_div_info *div_info);
static void	move_larger(t_div_info *div_info);

void	sort_b_back(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t		size;
	int			min_element;

	if (elements -> size < 1)
	{
		delete_deque(elements);
		return ;
	}
	div_info = create_div_info(elements, commands);
	size = elements -> size;
	min_element = get_minelement(elements);
	div_info -> large = size - (size + 1) / 2 + min_element;
	div_info -> hold = div_info -> l_q;
	divide_b_back(div_info);
	delete_deque(div_info -> m_q);
	sort_a_front(div_info -> l_q, div_info -> commands);
	sort_b_front(div_info -> s_q, div_info -> commands);
}

static void	divide_b_back(t_div_info *div_info)
{
	t_deque	*elements;
	t_deque	*hold;
	int		number;

	elements = div_info -> elements;
	hold = div_info -> hold;
	while (elements -> size)
	{
		number = elements -> back -> content.number;
		if (number >= div_info -> large)
		{
			move_larger(div_info);
			popback_and_pushfront(div_info, hold, rrb);
		}
		else
		{
			move_large_all(div_info);
			popback_and_pushfront(div_info, div_info -> s_q, rrb);
		}
	}
	move_large_all(div_info);
	delete_deque(div_info -> elements);
	swap_hold(div_info);
}

static void	move_large_all(t_div_info *div_info)
{
	t_deque	*hold;
	t_deque	*hold_after;
	t_deque	*commands;

	hold = div_info -> hold;
	hold_after = div_info -> hold_after;
	commands = div_info -> commands;
	while (hold -> size)
	{
		pushfront(hold_after, popfront(hold));
		pushback(commands, create_command_node(pa));
	}
}

static void	move_larger(t_div_info *div_info)
{
	t_deque	*hold;
	t_deque	*hold_after;
	t_deque	*commands;
	int		number;

	hold = div_info -> hold;
	hold_after = div_info -> hold_after;
	commands = div_info -> commands;
	number = div_info -> elements -> back -> content.number;
	while (hold -> size)
	{
		if (number > hold -> front -> content.number)
			break ;
		pushfront(hold_after, popfront(hold));
		pushback(commands, create_command_node(pa));
	}
}
