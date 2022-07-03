/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:12:32 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 06:04:32 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../..//include/bonus.h"

static t_command	*read_command(char *str);

void	read_commands(t_deque *commands)
{
	t_command	*command;
	char		*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		command = read_command(str);
		if (command == -1)
			ft_exit(ERROR);
		pushback(commands, create_command_node(command));
	}
}

static t_command	*read_command(char *str)
{
	if (ft_strcmp(str, "sa\n"))
		return (sa);
	else if (ft_strcmp(str, "sb\n"))
		return (sb);
	else if (ft_strcmp(str, "ss\n"))
		return (ss);
	else if (ft_strcmp(str, "pa\n"))
		return (pa);
	else if (ft_strcmp(str, "pb\n"))
		return (pb);
	else if (ft_strcmp(str, "ra\n"))
		return (ra);
	else if (ft_strcmp(str, "rb\n"))
		return (rb);
	else if (ft_strcmp(str, "rr\n"))
		return (rr);
	else if (ft_strcmp(str, "rra\n"))
		return (rra);
	else if (ft_strcmp(str, "rrb\n"))
		return (rrb);
	else if (ft_strcmp(str, "rrr\n"))
		return (rrr);
	else
		return (-1);
}
