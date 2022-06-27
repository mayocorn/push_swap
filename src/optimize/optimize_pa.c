/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_pa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:26:02 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/27 15:57:40 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	optimize_pbrapa(t_deque *commands, t_node **node);
static void	optimize_pbrrapa(t_deque *commands, t_node **node);
static void optimize_rrapbsapa(t_deque *commands, t_node **node);
static void	optimize_sbpapa(t_deque *commands, t_node **node);

void	optimize_pa(t_deque *commands, t_node **node)
{
	t_node	*prev;
	t_node	*next;

	prev = (*node) -> prev;
	next = (*node) -> next;
	if (prev == NULL)
		*node = next;
	else if (prev -> content.command == pb)
	{
		disjoint_node(commands, prev);
		disjoint_node(commands, *node);
		*node = next;
	}
	else if (prev -> content.command == ra)
		return(optimize_pbrapa(commands, node));
	else if (prev -> content.command == rra)
		return(optimize_pbrrapa(commands, node));
	else if (prev -> content.command == sa)
		return(optimize_rrapbsapa(commands, node));
	else if (prev -> content.command == pa)
		return(optimize_sbpapa(commands, node));
	else
		*node = next;
}

static void	optimize_pbrapa(t_deque *commands, t_node **node)
{
	t_node	*ra_node;
	t_node	*pb_node;

	ra_node = (*node) -> prev;
	pb_node = ra_node -> prev;
	if (pb_node != NULL && pb_node -> content.command == pb)
	{
		pb_node -> content.command = sa;
		disjoint_node(commands, *node);
		*node = ra_node;
	}
	else
		*node = (*node) -> next;
}

static void	optimize_pbrrapa(t_deque *commands, t_node **node)
{
	t_node	*rra_node;
	t_node	*pb_node;

	rra_node = (*node) -> prev;
	pb_node = rra_node -> prev;
	if (pb_node != NULL && pb_node -> content.command == pb)
	{
		disjoint_node(commands, pb_node);
		(*node) -> content.command = sa;
		*node = rra_node;
	}
	else
		*node = (*node) -> next;
}

static void optimize_rrapbsapa(t_deque *commands, t_node **node)
{
	t_node *sa_node;
	t_node *pb_node;
	t_node *rra_node;

	sa_node = (*node) -> prev;
	pb_node = sa_node -> prev;
	if (pb_node != NULL && pb_node -> content.command == pb)
	{
		rra_node = pb_node -> prev;
		if (rra_node != NULL && rra_node -> content.command == rra)
		{
			disjoint_node(commands, rra_node);
			disjoint_node(commands, pb_node);
			(*node) -> content.command = rra;
			*node = sa_node;
			return ;
		}
	}
	*node = (*node) -> next;
}

static void	optimize_sbpapa(t_deque *commands, t_node **node)
{
	t_node	*pa_node;
	t_node	*sb_node;

	pa_node = (*node) -> prev;
	sb_node = pa_node -> prev;
	if (sb_node != NULL && sb_node -> content.command == sb)
	{
		sb_node -> content.command = pa;
		(*node) -> content.command = sa;
		*node = sb_node;
	}
	else
		*node = (*node) -> next;
}
