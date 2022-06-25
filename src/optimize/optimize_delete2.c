/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_delete2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:49:34 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/25 19:04:51 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

void	delete_rrara(t_deque *commands, t_node *ra_node)
{
	t_node		*rra_node;
	t_command	command;

	rra_node = ra_node -> prev;
	while (rra_node != NULL)
	{
		command = rra_node -> content.command;
		if (command == rra)
		{
			disjoint_node(commands, ra_node);
			disjoint_node(commands, rra_node);
			return ;
		}
		else if (command == pa || command == pb || command == ra)
			return ;
		rra_node = rra_node -> prev;
	}
}

void	delete_rarra(t_deque *commands, t_node *rra_node)
{
	t_node		*ra_node;
	t_command	command;

	ra_node = rra_node -> prev;
	while (ra_node != NULL)
	{
		command = ra_node -> content.command;
		if (command == ra)
		{
			disjoint_node(commands, ra_node);
			disjoint_node(commands, rra_node);
			return ;
		}
		else if (command == pa || command == pb || command == rra)
			return ;
		ra_node = ra_node -> prev;
	}
}

void	delete_rrbrb(t_deque *commands, t_node *rb_node)
{
	t_node		*rrb_node;
	t_command	command;

	rrb_node = rb_node -> prev;
	while (rrb_node != NULL)
	{
		command = rrb_node -> content.command;
		if (command == rrb)
		{
			disjoint_node(commands, rb_node);
			disjoint_node(commands, rrb_node);
			return ;
		}
		else if (command == pa || command == pb || command == rb)
			return ;
		rrb_node = rrb_node -> prev;
	}
}

void	delete_rbrrb(t_deque *commands, t_node *rrb_node)
{
	t_node		*rb_node;
	t_command	command;

	rb_node = rrb_node -> prev;
	while (rb_node != NULL)
	{
		command = rb_node -> content.command;
		if (command == rb)
		{
			disjoint_node(commands, rb_node);
			disjoint_node(commands, rrb_node);
			return ;
		}
		else if (command == pa || command == pb || command == rrb)
			return ;
		rb_node = rb_node -> prev;
	}
}
