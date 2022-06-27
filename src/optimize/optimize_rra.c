/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:29:23 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/27 16:19:04 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	optimize_raparra(t_deque *commands, t_node **node);
static void optimize_rapbrra(t_deque *commands, t_node **node);
static void	optimize_parasarra(t_deque *commands, t_node **node);
static void	optimize_rarra(t_deque *commands, t_node **node);

void	optimize_rra(t_deque *commands, t_node **node)
{
	t_node	*prev;

	prev = (*node) -> prev;
	if (prev == NULL)
		*node = (*node) -> next;
	else if (prev -> content.command == pa)
		return (optimize_raparra(commands, node));
	else if (prev -> content.command == pb)
		return (optimize_rapbrra(commands, node));
	else if (prev -> content.command == sa)
		return (optimize_parasarra(commands, node));
	else
		return (optimize_rarra(commands, node));
}

static void	optimize_raparra(t_deque *commands, t_node **node)
{
	t_node	*pa_node;
	t_node	*ra_node;

	pa_node = (*node) -> prev;
	ra_node = pa_node -> prev;
	if (ra_node != NULL && ra_node -> content.command == ra)
	{
		disjoint_node(commands, ra_node);
		(*node) -> content.command = sa;
		*node = pa_node;
	}
	else
		*node = (*node) -> next;
}

static void optimize_rapbrra(t_deque *commands, t_node **node)
{
	t_node	*pb_node;
	t_node	*ra_node;

	pb_node = (*node) -> prev;
	ra_node = pb_node -> prev;
	if (ra_node != NULL && ra_node -> content.command == ra)
	{
		disjoint_node(commands, *node);
		ra_node -> content.command = sa;
		*node = ra_node;
	}
	else
		*node = (*node) -> next;
}

static void	optimize_parasarra(t_deque *commands, t_node **node)
{
	t_node	*sa_node;
	t_node	*ra_node;
	t_node	*pa_node;

	sa_node = (*node) -> prev;
	ra_node = sa_node -> prev;
	if (ra_node != NULL && ra_node -> content.command == ra)
	{
		pa_node = ra_node -> prev;
		if (pa_node != NULL && pa_node -> content.command == pa)
		{
			disjoint_node(commands, pa_node);
			disjoint_node(commands, ra_node);
			(*node) -> content.command = pa;
			*node = sa_node;
			return ;
		}
	}
	*node = (*node) -> next;
}

static void	optimize_rarra(t_deque *commands, t_node **node)
{
	t_node		*prev;
	t_node		*next;
	t_command	command;

	prev = (*node) -> prev;
	while (prev != NULL)
	{
		command = prev -> content.command;
		if (command == ra)
		{
			next = prev -> next;
			if (next == *node)
				next = next -> next;
			disjoint_node(commands, prev);
			disjoint_node(commands, *node);
			*node = next;
			return ;
		}
		if (command == sa || command == pb || command == pa || command == rra)
			break ;
		prev = prev -> prev;
	}
	*node = (*node) -> next;
}
