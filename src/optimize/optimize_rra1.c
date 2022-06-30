/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rra1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:29:23 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/30 01:10:57 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	optimize_parasarra(t_deque *commands, t_node **node);

void	optimize_rra(t_deque *commands, t_node **node)
{
	t_node	*prev;

	prev = (*node) -> prev;
	if (prev == NULL)
		*node = (*node) -> next;
	else if (prev -> content.command == sa)
		return (optimize_parasarra(commands, node));
	else
		return (optimize_ra_rra(commands, node));
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
