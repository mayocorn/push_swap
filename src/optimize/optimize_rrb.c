/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:11:53 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/27 16:21:59 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	optimize_rbpbrrb(t_deque *commands, t_node **node);
static void optimize_rbparrb(t_deque *commands, t_node **node);
static void	optimize_pbrbsbrrb(t_deque *commands, t_node **node);
static void	optimize_rbrrb(t_deque *commands, t_node **node);

void	optimize_rrb(t_deque *commands, t_node **node)
{
	t_node	*prev;

	prev = (*node) -> prev;
	if (prev == NULL)
		*node = (*node) -> next;
	else if (prev -> content.command == pb)
		return (optimize_rbpbrrb(commands, node));
	else if (prev -> content.command == pa)
		return (optimize_rbparrb(commands, node));
	else if (prev -> content.command == sb)
		return (optimize_pbrbsbrrb(commands, node));
	else
		return (optimize_rbrrb(commands, node));
}

static void	optimize_rbpbrrb(t_deque *commands, t_node **node)
{
	t_node	*pb_node;
	t_node	*rb_node;

	pb_node = (*node) -> prev;
	rb_node = pb_node -> prev;
	if (rb_node != NULL && rb_node -> content.command == rb)
	{
		disjoint_node(commands, rb_node);
		(*node) -> content.command = sb;
		*node = pb_node;
	}
	else
		*node = (*node) -> next;
}

static void optimize_rbparrb(t_deque *commands, t_node **node)
{
	t_node	*pa_node;
	t_node	*rb_node;

	pa_node = (*node) -> prev;
	rb_node = pa_node -> prev;
	if (rb_node != NULL && rb_node -> content.command == rb)
	{
		disjoint_node(commands, *node);
		rb_node -> content.command = sb;
		*node = rb_node;
	}
	else
		*node = (*node) -> next;
}

static void	optimize_pbrbsbrrb(t_deque *commands, t_node **node)
{
	t_node	*sb_node;
	t_node	*rb_node;
	t_node	*pb_node;

	sb_node = (*node) -> prev;
	rb_node = sb_node -> prev;
	if (rb_node != NULL && rb_node -> content.command == rb)
	{
		pb_node = rb_node -> prev;
		if (pb_node != NULL && pb_node -> content.command == pb)
		{
			disjoint_node(commands, pb_node);
			disjoint_node(commands, rb_node);
			(*node) -> content.command = pb;
			*node = sb_node;
			return ;
		}
	}
	*node = (*node) -> next;
}

static void	optimize_rbrrb(t_deque *commands, t_node **node)
{
	t_node		*prev;
	t_node		*next;
	t_command	command;

	prev = (*node) -> prev;
	while (prev != NULL)
	{
		command = prev -> content.command;
		if (command == rb)
		{
			next = prev -> next;
			if (next == *node)
				next = next -> next;
			disjoint_node(commands, prev);
			disjoint_node(commands, *node);
			*node = next;
			return ;
		}
		if (command == sb || command == pb || command == pa || command == rrb)
			break ;
		prev = prev -> prev;
	}
	*node = (*node) -> next;
}
