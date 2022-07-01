/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_div_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:49:18 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 15:49:29 by mayocorn         ###   ########.fr       */
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
