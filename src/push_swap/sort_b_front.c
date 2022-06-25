/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:12:18 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/25 17:01:38 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_b_front(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t 		max_cnt;
	int			min_element;

	if (elements -> size < 1)
	{
		delete_deque(elements);
		return	;
	}
	div_info = create_div_info(elements, commands);
	max_cnt = 0;
	min_element = get_minelement(elements);
	check_div_afabbb(div_info, &max_cnt, min_element);
	check_div_afbbab(div_info, &max_cnt, min_element);
	divide(div_info);
	sort_next_division(div_info);
}