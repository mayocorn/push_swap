/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_each_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:20:14 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:38:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "optimize.h"

void	optimize_each_command(t_deque *commands)
{
	t_node	*now;

	now = commands->front;
	while (now != NULL)
	{
		if (now->content.command == pa)
			optimize_pa(commands, &now);
		else if (now->content.command == pb)
			optimize_pb(commands, &now);
		else if (now->content.command == ra)
			optimize_ra(commands, &now);
		else if (now->content.command == rb)
			optimize_rb(commands, &now);
		else if (now->content.command == rra)
			optimize_rra(commands, &now);
		else if (now->content.command == rrb)
			optimize_rrb(commands, &now);
		else
			now = now->next;
	}
}
