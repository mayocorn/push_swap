/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 06:37:16 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/25 16:49:54 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_a_front(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t 		max_cnt;
	int			min_element;

	if (elements -> size <= 1)
	{
		delete_deque(elements);
		return	;
	}
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
