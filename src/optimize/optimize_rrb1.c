/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rrb1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:11:53 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/29 16:51:28 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	optimize_pbrbsbrrb(t_deque *commands, t_node **node);

void	optimize_rrb(t_deque *commands, t_node **node)
{
	t_node	*prev;

	prev = (*node) -> prev;
	if (prev == NULL)
		*node = (*node) -> next;
	else if (prev -> content.command == sb)
		return (optimize_pbrbsbrrb(commands, node));
	else
		return (optimize_rb_rrb(commands, node));
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
