/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:00:01 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:38:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	divide_a_back(t_div_info *div_info);
static void	move_small_all(t_div_info *div_info);
static void	move_smaller(t_div_info *div_info);

void	sort_a_back(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t		size;
	int			min_element;

	if (elements->size < 1)
		return (delete_deque(elements));
	div_info = create_div_info(elements, commands);
	delete_deque(div_info->m_q);
	div_info->hold = div_info->s_q;
	size = elements->size;
	min_element = get_minelement(elements);
	div_info->large = size - (size + 1) / 2 + min_element;
	divide_a_back(div_info);
	sort_a_front(div_info->l_q, div_info->commands);
	sort_b_front(div_info->s_q, div_info->commands);
	free(div_info);
}

static void	divide_a_back(t_div_info *div_info)
{
	t_deque	*elements;
	t_deque	*hold;
	int		number;

	elements = div_info->elements;
	hold = div_info->hold;
	while (elements->size)
	{
		number = elements->back->content.number;
		if (number >= div_info->large)
		{
			move_small_all(div_info);
			popback_and_pushfront(div_info, div_info->l_q, rra);
		}
		else
		{
			move_smaller(div_info);
			popback_and_pushfront(div_info, hold, rra);
		}
	}
	move_small_all(div_info);
	delete_deque(div_info->elements);
	swap_hold(div_info);
}

static void	move_small_all(t_div_info *div_info)
{
	t_deque	*hold;
	t_deque	*hold_after;
	t_deque	*commands;

	hold = div_info->hold;
	hold_after = div_info->hold_after;
	commands = div_info->commands;
	while (hold->size)
	{
		pushfront(hold_after, popfront(hold));
		pushback(commands, create_command_node(pb));
	}
}

static void	move_smaller(t_div_info *div_info)
{
	t_deque	*hold;
	t_deque	*hold_after;
	t_deque	*commands;
	int		number;

	hold = div_info->hold;
	hold_after = div_info->hold_after;
	commands = div_info->commands;
	number = div_info->elements->back->content.number;
	while (hold->size)
	{
		if (number < hold->front->content.number)
			break ;
		pushfront(hold_after, popfront(hold));
		pushback(commands, create_command_node(pb));
	}
}
