/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_pb_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:15:48 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimize.h"

static void	optimize_parrbpb(t_deque *commands, t_node **node);
static void	optimize_rrbpasbpb(t_deque *commands, t_node **node);

void	optimize_pb_sub(t_deque *commands, t_node **node)
{
	t_node	*prev;

	prev = (*node)->prev;
	if (prev -> content.command == rrb)
		return (optimize_parrbpb(commands, node));
	else if (prev -> content.command == sb)
		return (optimize_rrbpasbpb(commands, node));
	else
		*node = (*node)->next;
}

static void	optimize_parrbpb(t_deque *commands, t_node **node)
{
	t_node	*rrb_node;
	t_node	*pa_node;

	rrb_node = (*node)->prev;
	pa_node = rrb_node -> prev;
	if (pa_node != NULL && pa_node -> content.command == pa)
	{
		disjoint_node(commands, pa_node);
		(*node)->content.command = sb;
		*node = rrb_node;
	}
	else
		*node = (*node)->next;
}

static void	optimize_rrbpasbpb(t_deque *commands, t_node **node)
{
	t_node	*sb_node;
	t_node	*pa_node;
	t_node	*rrb_node;

	sb_node = (*node)->prev;
	pa_node = sb_node -> prev;
	if (pa_node != NULL && pa_node -> content.command == pa)
	{
		rrb_node = pa_node -> prev;
		if (rrb_node != NULL && rrb_node -> content.command == rrb)
		{
			disjoint_node(commands, rrb_node);
			disjoint_node(commands, pa_node);
			(*node)->content.command = rrb;
			*node = sb_node;
			return ;
		}
	}
	*node = (*node)->next;
}
