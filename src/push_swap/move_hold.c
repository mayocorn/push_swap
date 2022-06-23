/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hold.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:59:17 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 00:31:49 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	move_hold_all(t_deque *hold, t_deque *after, t_deque *commands, t_command command)
{
	t_node	*node;

	while (hold -> size)
	{
		node = popfront(hold);
		pushback(after, node);
		pushback(commands, create_command_node(command));
	}
}

void	move_hold_one(t_hold_info args)
{
	t_node	*node;

	if ((args.hold) -> size)
	{
		node = popfront(args.hold);
		pushback(args.hold_after, node);
		pushback(args.commands, create_command_node(args.command_hold));
	}
	node = popfront(args.elements);
	pushback(args.elements_after, node);
	pushback(args.commands, create_command_node(args.command_elements));
}
