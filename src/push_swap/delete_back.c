/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:30:40 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 01:31:30 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	delete_back_ra(t_deques *deques)
{
	t_content	content;
	t_deque		*commands;

	commands = deques -> commands;
	while (commands -> size)
	{
		content.command = ((t_node *)(commands -> back))-> content.command;
		if (content.command == ra)
		{
			free(popback(commands));
			pushfront(deques -> af, popback(deques -> af));
		}
		else
			break ;
	}
}
