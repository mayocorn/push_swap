/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_maxvalue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 06:23:53 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_a_maxvalue(t_deque *elements, t_deque *commands)
{
	t_div_info	*div_info;
	size_t		max_cnt;
	int			min_element;

	if (elements -> size <= 1)
		return (delete_deque(elements));
	div_info = create_div_info(elements, commands);
	max_cnt = 0;
	min_element = get_minelement(elements);
	check_div_afbfbb(div_info, &max_cnt, min_element);
	check_div_afbbbf(div_info, &max_cnt, min_element);
	divide(div_info);
	delete_back_ra(div_info);
	sort_next_division(div_info);
}
