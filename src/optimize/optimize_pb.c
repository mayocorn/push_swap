/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:17:49 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/27 16:04:53 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	optimize_parbpb(t_deque *commands, t_node **node);
static void	optimize_parrbpb(t_deque *commands, t_node **node);
static void optimize_rrbpasbpb(t_deque *commands, t_node **node);
static void	optimize_sapbpb(t_deque *commands, t_node **node);

void	optimize_pb(t_deque *commands, t_node **node)
{
	t_node	*prev;
	t_node	*next;

	prev = (*node) -> prev;
	next = (*node) -> next;
	if (prev == NULL)
		*node = next;
	else if (prev -> content.command == pa)
	{
		disjoint_node(commands, prev);
		disjoint_node(commands, *node);
		*node = next;
	}
	else if (prev -> content.command == rb)
		return(optimize_parbpb(commands, node));
	else if (prev -> content.command == rrb)
		return(optimize_parrbpb(commands, node));
	else if (prev -> content.command == sb)
		return(optimize_rrbpasbpb(commands, node));
	else if (prev -> content.command == pb)
		return(optimize_sapbpb(commands, node));
	else
		*node = next;
}

static void	optimize_parbpb(t_deque *commands, t_node **node)
{
	t_node	*rb_node;
	t_node	*pa_node;

	rb_node = (*node) -> prev;
	pa_node = rb_node -> prev;
	if (pa_node != NULL && pa_node -> content.command == pa)
	{
		pa_node -> content.command = sb;
		disjoint_node(commands, *node);
		*node = rb_node;
	}
	else
		*node = (*node) -> next;
}

static void	optimize_parrbpb(t_deque *commands, t_node **node)
{
	t_node	*rrb_node;
	t_node	*pa_node;

	rrb_node = (*node) -> prev;
	pa_node = rrb_node -> prev;
	if (pa_node != NULL && pa_node -> content.command == pa)
	{
		disjoint_node(commands, pa_node);
		(*node) -> content.command = sb;
		*node = rrb_node;
	}
	else
		*node = (*node) -> next;
}

static void optimize_rrbpasbpb(t_deque *commands, t_node **node)
{
	t_node *sb_node;
	t_node *pa_node;
	t_node *rrb_node;

	sb_node = (*node) -> prev;
	pa_node = sb_node -> prev;
	if (pa_node != NULL && pa_node -> content.command == pa)
	{
		rrb_node = pa_node -> prev;
		if (rrb_node != NULL && rrb_node -> content.command == rrb)
		{
			disjoint_node(commands, rrb_node);
			disjoint_node(commands, pa_node);
			(*node) -> content.command = rrb;
			*node = sb_node;
			return ;
		}
	}
	*node = (*node) -> next;
}

static void	optimize_sapbpb(t_deque *commands, t_node **node)
{
	t_node	*pb_node;
	t_node	*sa_node;

	pb_node = (*node) -> prev;
	sa_node = pb_node -> prev;
	if (sa_node != NULL && sa_node -> content.command == sa)
	{
		sa_node -> content.command = pb;
		(*node) -> content.command = sb;
		*node = sa_node;
	}
	else
		*node = (*node) -> next;
}
