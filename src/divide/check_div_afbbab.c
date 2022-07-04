/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_div_afbbab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:33:58 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "divide.h"

static size_t	cnt_rr(t_div_info *div_info, int large, int small);
static void		set_div_info(t_div_info *div_info, int large, int small);

void	check_div_afbbab(t_div_info *div_info, size_t *max_cnt, int min_element)
{
	size_t	cnt;
	size_t	size;
	int		large;
	int		small;

	size = div_info -> elements -> size;
	large = size - (size + 2) / 3 + min_element;
	small = size / 3 - 1 + min_element;
	cnt = cnt_rr(div_info, large, small);
	if (cnt >= *max_cnt)
	{
		*max_cnt = cnt;
		set_div_info(div_info, large, small);
	}
}

static size_t	cnt_rr(t_div_info *div_info, int large, int small)
{
	size_t	cnt;
	size_t	hold_cnt;
	t_node	*node;

	cnt = 0;
	hold_cnt = 0;
	node = div_info -> elements -> front;
	while (node != NULL)
	{
		if (node -> content.number >= large)
			hold_cnt = 0;
		if (node -> content.number <= small)
			hold_cnt++;
		if (node -> content.number > small && \
				node -> content.number < large && hold_cnt)
		{
			hold_cnt--;
			cnt++;
		}
		node = node -> next;
	}
	return (cnt);
}

static void	set_div_info(t_div_info *div_info, int large, int small)
{
	div_info -> large = large;
	div_info -> small = small;
	div_info -> hold = div_info -> s_q;
	div_info -> l_command = pa;
	div_info -> m_command = rb;
	div_info -> s_command = pa;
	div_info -> hold_command = ra;
	div_info -> l_push = move_hold_all;
	div_info -> m_push = move_hold_one;
	div_info -> s_push = popfront_and_pushfront;
	div_info -> l_next = sort_a_front;
	div_info -> m_next = sort_b_back;
	div_info -> s_next = sort_a_back;
}
