/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:30:40 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 18:23:21 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	delete_back_ra(t_div_info *div_info)
{
	t_content	content;
	t_deque		*commands;

	commands = div_info -> commands;
	while (commands -> size)
	{
		content.command = commands -> back -> content.command;
		if (content.command == ra)
		{
			free(popback(commands));
			pushfront(div_info -> l_q, popback(div_info -> l_q));
		}
		else
			break ;
	}
}

void	delete_back_rb(t_div_info *div_info)
{
	t_content	content;
	t_deque		*commands;

	commands = div_info -> commands;
	while (commands -> size)
	{
		content.command = commands -> back -> content.command;
		if (content.command == rb)
		{
			free(popback(commands));
			pushfront(div_info -> s_q, popback(div_info -> s_q));
		}
		else
			break ;
	}
}
