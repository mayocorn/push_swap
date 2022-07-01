/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_minvalue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:45:02 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/02 04:15:29 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

static void		set_div_info(t_div_info *div_info);

void	sort_b_minvalue(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t		size;

	if (elements -> size < 1)
		return (delete_deque(elements));
	div_info = create_div_info(elements, commands);
	size = elements -> size;
	div_info -> large = size - (size + 2) / 3;
	div_info -> small = (size + 1) / 3 - 1;
	set_div_info(div_info);
	divide(div_info);
	delete_back_rb(div_info);
	sort_next_division(div_info);
}

static void	set_div_info(t_div_info *div_info)
{
	div_info -> hold = div_info -> m_q;
	div_info -> l_command = pa;
	div_info -> m_command = pa;
	div_info -> s_command = rb;
	div_info -> hold_command = ra;
	div_info -> l_push = move_hold_all;
	div_info -> m_push = popfront_and_pushfront;
	div_info -> s_push = move_hold_one;
	div_info -> l_next = sort_a_front;
	div_info -> m_next = sort_a_back;
	div_info -> s_next = sort_b_minvalue;
}
