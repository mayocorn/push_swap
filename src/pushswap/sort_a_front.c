/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 06:37:16 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	sort_a_front_half(t_deque *elements, t_deque *commands);

void	sort_a_front(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t		max_cnt;
	int			min_element;

	if (elements -> size <= 1)
		return (delete_deque(elements));
	if (elements -> size <= 5)
		return (sort_a_front_half(elements, commands));
	div_info = create_div_info(elements, commands);
	max_cnt = 0;
	min_element = get_minelement(elements);
	check_div_abbfbb(div_info, &max_cnt, min_element);
	check_div_abbbbf(div_info, &max_cnt, min_element);
	check_div_bfabbb(div_info, &max_cnt, min_element);
	check_div_bfbbab(div_info, &max_cnt, min_element);
	check_div_bbabbf(div_info, &max_cnt, min_element);
	check_div_bbbfab(div_info, &max_cnt, min_element);
	divide(div_info);
	sort_next_division(div_info);
}

static void	sort_a_front_half(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t		size;
	int			min_element;
	t_node		*node;

	div_info = create_div_info(elements, commands);
	delete_deque(div_info -> m_q);
	delete_deque(div_info -> hold_after);
	size = elements -> size;
	min_element = get_minelement(elements);
	div_info -> large = size - size / 2 + min_element;
	while (elements -> size)
	{
		node = elements -> front;
		if (node -> content.number >= div_info -> large)
			popfront_and_pushfront(div_info, div_info -> l_q, pb);
		else
			popfront_and_pushback(div_info, div_info -> s_q, ra);
	}
	free_and_setnull((void **)&elements);
	sort_b_front(div_info -> l_q, div_info -> commands);
	sort_a_back(div_info -> s_q, div_info -> commands);
	free(div_info);
}
