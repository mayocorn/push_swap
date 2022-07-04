/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:12:32 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 07:14:42 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

static t_command	read_command(char *str);

void	read_commands(t_deque *commands)
{
	t_command	command;
	char		*str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			break ;
		command = read_command(str);
		if (command == error)
			ft_exit(ERROR);
		pushback(commands, create_command_node(command));
	}
}

static t_command	read_command(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (sa);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (sb);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (ss);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (pa);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (pb);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (ra);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (rb);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (rr);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (rra);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (rrb);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (rrr);
	else
		return (error);
}
