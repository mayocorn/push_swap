/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:34:59 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/29 19:33:18 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	optimize_sapbra(t_deque *commands, t_node **node);

void	optimize_ra(t_deque *commands, t_node **node)
{
	t_node		*prev;
	t_node		*next;
	t_command	command;

	prev = (*node) -> prev;
	if (prev != NULL && prev -> content.command == pb)
		return (optimize_sapbra(commands, node));
	while (prev != NULL)
	{
		command = prev -> content.command;
		if (command == rra)
		{
			next = prev -> next;
			if (next == *node)
				next = next -> next;
			disjoint_node(commands, prev);
			disjoint_node(commands, *node);
			*node = next;
			return ;
		}
		if (command == sa || command == pb || command == pa || command == ra)
			break ;
		prev = prev -> prev;
	}
	*node = (*node) -> next;
}

static void	optimize_sapbra(t_deque *commands, t_node **node)
{
	t_node	*pb_node;
	t_node	*sa_node;

	pb_node = (*node) -> prev;
	sa_node = pb_node -> prev;
	if (sa_node != NULL && sa_node -> content.command == sa)
	{
		sa_node -> content.command = ra;
		disjoint_node(commands, *node);
		*node = sa_node;
	}
	else
		*node = (*node) -> next;
}
