/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hold.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:59:17 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 15:21:41 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	move_hold_all(t_div_info *div_info, t_deque *after, t_command command)
{
	t_node	*node;
	t_deque	*hold;

	hold = div_info -> hold;
	while (hold -> size)
	{
		node = popfront(hold);
		pushback(div_info -> hold_after, node);
		pushback(div_info -> commands, \
					create_command_node(div_info -> hold_command));
	}
	if (div_info -> elements -> size)
	{
		node = popfront(div_info -> elements);
		pushfront(after, node);
		pushback(div_info -> commands, create_command_node(command));
	}
}

void	move_hold_one(t_div_info *div_info, t_deque *after, t_command command)
{
	t_node	*node;

	if (div_info -> hold -> size)
	{
		node = popfront(div_info -> hold);
		pushback(div_info -> hold_after, node);
		pushback(div_info -> commands, \
					create_command_node(div_info -> hold_command));
	}
	node = popfront(div_info -> elements);
	pushback(after, node);
	pushback(div_info -> commands, create_command_node(command));
}

void	swap_hold(t_div_info *div_info)
{
	if (div_info -> s_q == div_info -> hold)
		div_info -> s_q = div_info -> hold_after;
	else if (div_info -> m_q == div_info -> hold)
		div_info -> m_q = div_info -> hold_after;
	else if (div_info -> l_q == div_info -> hold)
		div_info -> l_q = div_info -> hold_after;
	delete_deque(div_info -> hold);
}
