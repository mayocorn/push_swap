/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:30:40 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:38:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	delete_back_ra(t_div_info *div_info)
{
	t_node		*now;
	t_node		*prev;
	t_command	command;

	now = div_info->commands->back;
	while (now != NULL)
	{
		command = now->content.command;
		prev = now->prev;
		if (command == ra)
		{
			disjoint_node(div_info->commands, now);
			pushfront(div_info->l_q, popback(div_info->l_q));
		}
		else if (command == pb)
			break ;
		now = prev;
	}
}

void	delete_back_rb(t_div_info *div_info)
{
	t_node		*now;
	t_node		*prev;
	t_command	command;

	now = div_info->commands->back;
	while (now != NULL)
	{
		command = now->content.command;
		prev = now->prev;
		if (command == rb)
		{
			disjoint_node(div_info->commands, now);
			pushfront(div_info->s_q, popback(div_info->s_q));
		}
		else if (command == pa)
			break ;
		now = prev;
	}
}
