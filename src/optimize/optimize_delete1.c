/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_delete1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:29:17 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/25 18:50:04 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

void	optimize_delete(t_deque *commands)
{
	t_node	*now;
	t_node	*next;

	now = commands -> front;
	while (now != NULL)
	{
		next = now -> next;
		if (now -> content.command == pa)
			delete_pbpa(commands, now);
		else if (now -> content.command == pb)
			delete_papb(commands, now);
		else if (now -> content.command == ra)
			delete_rrara(commands, now);
		else if (now -> content.command == rra)
			delete_rarra(commands, now);
		else if (now -> content.command == rb)
			delete_rrbrb(commands, now);
		else if (now -> content.command == rrb)
			delete_rbrrb(commands, now);
		now = next;
	}
}

void	delete_pbpa(t_deque *commands, t_node *pa_node)
{
	t_node	*pb_node;

	pb_node = pa_node -> prev;
	if (pb_node != NULL && pb_node -> content.command == pb)
	{
		disjoint_node(commands, pa_node);
		disjoint_node(commands, pb_node);
	}
}

void	delete_papb(t_deque *commands, t_node *pb_node)
{
	t_node	*pa_node;

	pa_node = pb_node -> prev;
	if (pa_node != NULL && pa_node -> content.command == pa)
	{
		disjoint_node(commands, pa_node);
		disjoint_node(commands, pb_node);
	}
}
