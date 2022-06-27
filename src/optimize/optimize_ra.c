/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_ra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:34:59 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/27 15:05:09 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

void	optimize_ra(t_deque *commands, t_node **node)
{
	t_node		*prev;
	t_node		*next;
	t_command	command;

	prev = (*node) -> prev;
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
