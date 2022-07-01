/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:52:28 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 16:48:45 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	optimize_sbparb(t_deque *commands, t_node **node);

void	optimize_rb(t_deque *commands, t_node **node)
{
	t_node		*prev;
	t_node		*next;
	t_command	command;

	prev = (*node)->prev;
	if (prev != NULL && prev -> content.command == pa)
		return (optimize_sbparb(commands, node));
	while (prev != NULL)
	{
		command = prev -> content.command;
		if (command == rrb)
		{
			next = prev -> next;
			if (next == *node)
				next = next -> next;
			disjoint_node(commands, prev);
			disjoint_node(commands, *node);
			*node = next;
			return ;
		}
		if (command == sb || command == pa || command == pb || command == rb)
			break ;
		prev = prev -> prev;
	}
	*node = (*node)->next;
}

static void	optimize_sbparb(t_deque *commands, t_node **node)
{
	t_node	*pa_node;
	t_node	*sb_node;

	pa_node = (*node)->prev;
	sb_node = pa_node -> prev;
	if (sb_node != NULL && sb_node -> content.command == sb)
	{
		sb_node -> content.command = rb;
		disjoint_node(commands, *node);
		*node = sb_node;
	}
	else
		*node = (*node)->next;
}
