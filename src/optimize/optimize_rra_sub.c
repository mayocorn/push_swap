/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rra_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:00:10 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimize.h"

static void	optimize_ra_rra(t_deque *commands, t_node **node, \
									t_node *ra_node, t_node *pab_node);
static void	optimize_rarra(t_deque *commands, t_node **node, t_node *ra_node);
static void	optimize_raparra(t_deque *commands, t_node **node, t_node *ra_node);
static void	optimize_rapbrra(t_deque *commands, t_node **node, t_node *ra_node);

void	optimize_rra_sub(t_deque *commands, t_node **node)
{
	t_command	command;
	t_node		*now;
	t_node		*pab_node;

	now = (*node)->prev;
	pab_node = NULL;
	while (now != NULL)
	{
		command = now -> content.command;
		if (command == ra)
			return (optimize_ra_rra(commands, node, now, pab_node));
		else if (pab_node == NULL && (command == pa || command == pb))
			pab_node = now;
		else if (command == sa || command == pa || \
					command == pb || command == rra)
			break ;
		now = now -> prev;
	}
	*node = (*node)->next;
}

static void	optimize_ra_rra(t_deque *commands, t_node **node, \
									t_node *ra_node, t_node *pab_node)
{
	if (pab_node == NULL)
		optimize_rarra(commands, node, ra_node);
	else if (pab_node -> content.command == pa)
		optimize_raparra(commands, node, ra_node);
	else
		optimize_rapbrra(commands, node, ra_node);
}

static void	optimize_rarra(t_deque *commands, t_node **node, t_node *ra_node)
{
	t_node	*next;

	next = ra_node -> next;
	if (next == *node)
		next = next -> next;
	disjoint_node(commands, ra_node);
	disjoint_node(commands, *node);
	*node = next;
}

static void	optimize_raparra(t_deque *commands, t_node **node, t_node *ra_node)
{
	t_node	*next;

	next = ra_node -> next;
	disjoint_node(commands, ra_node);
	(*node)->content.command = sa;
	*node = next;
}

static void	optimize_rapbrra(t_deque *commands, t_node **node, t_node *ra_node)
{
	disjoint_node(commands, *node);
	ra_node -> content.command = sa;
	*node = ra_node;
}
