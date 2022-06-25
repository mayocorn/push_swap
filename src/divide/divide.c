/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 08:35:34 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/25 15:22:24 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/divide.h"

t_div_info	*create_div_info(t_deque *elements, t_deque *commands)
{
	t_div_info	*res;

	res = malloc_and_checknull(sizeof(t_div_info));
	res -> elements = elements;
	res -> commands = commands;
	res -> l_q = create_deque();
	res -> m_q = create_deque();
	res -> s_q = create_deque();
	res -> hold_after = create_deque();
	return (res);
}

void	divide(t_div_info *div_info)
{
	t_deque	*elements;
	int		number;

	elements = div_info -> elements;
	while (elements -> size)
	{
		number = elements -> front -> content.number;
		if (number <= (div_info -> small))
			div_info -> \
				s_push(div_info, div_info -> s_q, div_info -> s_command);
		else if (number >= (div_info -> large))
			div_info -> \
				l_push(div_info, div_info -> l_q, div_info -> l_command);
		else
			div_info -> \
				m_push(div_info, div_info -> m_q, div_info -> m_command);
	}
	move_hold_all(div_info, NULL, 0);
	delete_deque(elements);
	swap_hold(div_info);
}
