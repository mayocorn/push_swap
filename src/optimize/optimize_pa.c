/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_pa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:26:02 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimize.h"

static void	optimize_sbpapa(t_node **node);
static void	optimize_pbpa(t_deque *commands, t_node **node);
static void	optimize_pbrapa(t_deque *commands, t_node **node);
static void	optimize_sbrbpa(t_deque *commands, t_node **node);

void	optimize_pa(t_deque *commands, t_node **node)
{
	t_node	*prev;

	prev = (*node)->prev;
	if (prev == NULL)
		*node = (*node)->next;
	else if (prev -> content.command == pa)
		return (optimize_sbpapa(node));
	else if (prev -> content.command == pb)
		return (optimize_pbpa(commands, node));
	else if (prev -> content.command == ra)
		return (optimize_pbrapa(commands, node));
	else if (prev -> content.command == rb)
		return (optimize_sbrbpa(commands, node));
	else
		return (optimize_pa_sub(commands, node));
}

static void	optimize_sbpapa(t_node **node)
{
	t_node	*pa_node;
	t_node	*sb_node;

	pa_node = (*node)->prev;
	sb_node = pa_node -> prev;
	if (sb_node != NULL && sb_node -> content.command == sb)
	{
		sb_node -> content.command = pa;
		(*node)->content.command = sa;
		*node = sb_node;
	}
	else
		*node = (*node)->next;
}

static void	optimize_pbpa(t_deque *commands, t_node **node)
{
	t_node	*next;

	next = (*node)->next;
	disjoint_node(commands, (*node)->prev);
	disjoint_node(commands, *node);
	*node = next;
}

static void	optimize_pbrapa(t_deque *commands, t_node **node)
{
	t_node	*ra_node;
	t_node	*pb_node;

	ra_node = (*node)->prev;
	pb_node = ra_node -> prev;
	if (pb_node != NULL && pb_node -> content.command == pb)
	{
		pb_node -> content.command = sa;
		disjoint_node(commands, *node);
		*node = pb_node;
	}
	else
		*node = (*node)->next;
}

void	optimize_sbrbpa(t_deque *commands, t_node **node)
{
	t_node	*rb_node;
	t_node	*sb_node;

	rb_node = (*node)->prev;
	sb_node = rb_node -> prev;
	if (sb_node != NULL && sb_node -> content.command == sb)
	{
		sb_node -> content.command = pa;
		disjoint_node(commands, *node);
		*node = sb_node;
	}
	else
		*node = (*node)->next;
}
