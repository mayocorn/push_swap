/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:52:28 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/27 15:05:24 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

void	optimize_rb(t_deque *commands, t_node **node)
{
	t_node		*prev;
	t_node		*next;
	t_command	command;

	prev = (*node) -> prev;
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
	*node = (*node) -> next;
}
