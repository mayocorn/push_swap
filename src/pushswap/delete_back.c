/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:30:40 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 15:09:16 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

void	delete_back_ra(t_div_info *div_info)
{
	t_deque		*commands;
	t_command	command;

	commands = div_info -> commands;
	while (commands -> size)
	{
		command = commands -> back -> content.command;
		if (command == ra)
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
	t_deque		*commands;
	t_command	command;

	commands = div_info -> commands;
	while (commands -> size)
	{
		command = commands -> back -> content.command;
		if (command == rb)
		{
			free(popback(commands));
			pushfront(div_info -> s_q, popback(div_info -> s_q));
		}
		else
			break ;
	}
}
