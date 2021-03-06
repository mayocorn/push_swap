/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_pa_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:36:42 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:38:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimize.h"

static void	optimize_pbrrapa(t_deque *commands, t_node **node);
static void	optimize_rrapbsapa(t_deque *commands, t_node **node);

void	optimize_pa_sub(t_deque *commands, t_node **node)
{
	t_node	*prev;

	prev = (*node)->prev;
	if (prev->content.command == rra)
		return (optimize_pbrrapa(commands, node));
	else if (prev->content.command == sa)
		return (optimize_rrapbsapa(commands, node));
	else
		*node = (*node)->next;
}

static void	optimize_pbrrapa(t_deque *commands, t_node **node)
{
	t_node	*rra_node;
	t_node	*pb_node;

	rra_node = (*node)->prev;
	pb_node = rra_node->prev;
	if (pb_node != NULL && pb_node->content.command == pb)
	{
		disjoint_node(commands, pb_node);
		(*node)->content.command = sa;
		*node = rra_node;
	}
	else
		*node = (*node)->next;
}

static void	optimize_rrapbsapa(t_deque *commands, t_node **node)
{
	t_node	*sa_node;
	t_node	*pb_node;
	t_node	*rra_node;

	sa_node = (*node)->prev;
	pb_node = sa_node->prev;
	if (pb_node != NULL && pb_node->content.command == pb)
	{
		rra_node = pb_node->prev;
		if (rra_node != NULL && rra_node->content.command == rra)
		{
			disjoint_node(commands, rra_node);
			disjoint_node(commands, pb_node);
			(*node)->content.command = rra;
			*node = sa_node;
			return ;
		}
	}
	*node = (*node)->next;
}
