/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_maxvalue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 06:23:53 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 18:12:47 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	cnt_a_maxvalue(t_deque *elements, t_deque *commands, int min_element);

void	sort_a_maxvalue(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t		max_cnt;
	int			min_element;

	if (elements -> size <= 1)
	{
		delete_deque(elements);
		return ;
	}
	div_info = create_div_info(elements, commands);
	max_cnt = 0;
	min_element = get_minelement(elements);
	check_div_afbfbb(div_info, &max_cnt, min_element);
	check_div_afbbbf(div_info, &max_cnt, min_element);
	divide(div_info);
	delete_back_ra(div_info);
	//分岐
}
