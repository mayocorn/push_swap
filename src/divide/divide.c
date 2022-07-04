/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 08:35:34 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "divide.h"

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
