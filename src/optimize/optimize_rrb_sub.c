/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rrb_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:12:16 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:38:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimize.h"

static void	optimize_rb_rrb(t_deque *commands, t_node **node, \
									t_node *rb_node, t_node *pab_node);
static void	optimize_rbrrb(t_deque *commands, t_node **node, t_node *rb_node);
static void	optimize_rbparrb(t_deque *commands, t_node **node, t_node *rb_node);
static void	optimize_rbpbrrb(t_deque *commands, t_node **node, t_node *rb_node);

void	optimize_rrb_sub(t_deque *commands, t_node **node)
{
	t_command	command;
	t_node		*now;
	t_node		*pab_node;

	now = (*node)->prev;
	pab_node = NULL;
	while (now != NULL)
	{
		command = now->content.command;
		if (command == rb)
			return (optimize_rb_rrb(commands, node, now, pab_node));
		else if (pab_node == NULL && (command == pa || command == pb))
			pab_node = now;
		else if (command == sb || command == pa || \
					command == pb || command == rrb)
			break ;
		now = now->prev;
	}
	*node = (*node)->next;
}

static void	optimize_rb_rrb(t_deque *commands, t_node **node, \
									t_node *rb_node, t_node *pab_node)
{
	if (pab_node == NULL)
		optimize_rbrrb(commands, node, rb_node);
	else if (pab_node->content.command == pa)
		optimize_rbparrb(commands, node, rb_node);
	else
		optimize_rbpbrrb(commands, node, rb_node);
}

static void	optimize_rbrrb(t_deque *commands, t_node **node, t_node *rb_node)
{
	t_node	*next;

	next = rb_node->next;
	if (next == *node)
		next = next->next;
	disjoint_node(commands, rb_node);
	disjoint_node(commands, *node);
	*node = next;
}

static void	optimize_rbparrb(t_deque *commands, t_node **node, t_node *rb_node)
{
	disjoint_node(commands, *node);
	rb_node->content.command = sb;
	*node = rb_node;
}

static void	optimize_rbpbrrb(t_deque *commands, t_node **node, t_node *rb_node)
{
	t_node	*next;

	next = rb_node->next;
	disjoint_node(commands, rb_node);
	(*node)->content.command = sb;
	*node = next;
}
