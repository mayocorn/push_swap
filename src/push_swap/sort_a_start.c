/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:09:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/29 18:25:53 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	sort_until_appear_med(t_div_info *div_info);
static void	set_div_info(t_div_info *div_info);

void	sort_a_start(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t		size;

	div_info = create_div_info(elements, commands);
	size = elements -> size;
	div_info -> large = size - (size + 2) / 3;
	div_info -> small = size / 3 - 1;
	set_div_info(div_info);
	sort_until_appear_med(div_info);
	divide(div_info);
	delete_back_ra(div_info);
	sort_next_division(div_info);
}

static void	sort_until_appear_med(t_div_info *div_info)
{
	int		number;
	t_deque	*elements;

	elements = div_info -> elements;
	while (elements -> size)
	{
		number = (elements -> front)-> content.number;
		if (number <= (div_info -> small))
			popfront_and_pushfront(div_info, div_info -> hold_after, pb);
		else if (number >= (div_info -> large))
			popfront_and_pushback(div_info, div_info -> l_q, ra);
		else
			break ;
	}
}

static void	set_div_info(t_div_info *div_info)
{
	div_info -> hold = div_info -> s_q;
	div_info -> l_command = ra;
	div_info -> m_command = pb;
	div_info -> s_command = pb;
	div_info -> hold_command = rb;
	div_info -> l_push = move_hold_one;
	div_info -> m_push = move_hold_all;
	div_info -> s_push = popfront_and_pushfront;
	div_info -> l_next = sort_a_maxvalue;
	div_info -> m_next = sort_b_front;
	div_info -> s_next = sort_b_minvalue;
}
