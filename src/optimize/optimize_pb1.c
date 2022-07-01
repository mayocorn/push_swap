/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_pb1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:17:49 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 16:39:01 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	optimize_papb(t_deque *commands, t_node **node);
static void	optimize_sapbpb(t_deque *commands, t_node **node);
static void	optimize_sarapb(t_deque *commands, t_node **node);
static void	optimize_parbpb(t_deque *commands, t_node **node);

void	optimize_pb(t_deque *commands, t_node **node)
{
	t_node	*prev;

	prev = (*node)->prev;
	if (prev == NULL)
		*node = (*node)->next;
	else if (prev -> content.command == pa)
		return (optimize_papb(commands, node));
	else if (prev -> content.command == pb)
		return (optimize_sapbpb(commands, node));
	else if (prev -> content.command == ra)
		return (optimize_sarapb(commands, node));
	else if (prev -> content.command == rb)
		return (optimize_parbpb(commands, node));
	else
		return (optimize_pb_sub(commands, node));
}

static void	optimize_papb(t_deque *commands, t_node **node)
{
	t_node	*next;

	next = (*node)->next;
	disjoint_node(commands, (*node)->prev);
	disjoint_node(commands, *node);
	*node = next;
}

static void	optimize_sapbpb(t_deque *commands, t_node **node)
{
	t_node	*pb_node;
	t_node	*sa_node;

	pb_node = (*node)->prev;
	sa_node = pb_node -> prev;
	if (sa_node != NULL && sa_node -> content.command == sa)
	{
		sa_node -> content.command = pb;
		(*node)->content.command = sb;
		*node = sa_node;
	}
	else
		*node = (*node)->next;
}

static void	optimize_sarapb(t_deque *commands, t_node **node)
{
	t_node	*ra_node;
	t_node	*sa_node;

	ra_node = (*node)->prev;
	sa_node = ra_node -> prev;
	if (sa_node != NULL && sa_node -> content.command == sa)
	{
		sa_node -> content.command = pb;
		disjoint_node(commands, *node);
		*node = sa_node;
	}
	else
		*node = (*node)->next;
}

static void	optimize_parbpb(t_deque *commands, t_node **node)
{
	t_node	*rb_node;
	t_node	*pa_node;

	rb_node = (*node)->prev;
	pa_node = rb_node -> prev;
	if (pa_node != NULL && pa_node -> content.command == pa)
	{
		pa_node -> content.command = sb;
		disjoint_node(commands, *node);
		*node = rb_node;
	}
	else
		*node = (*node)->next;
}
