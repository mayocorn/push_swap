/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:47:14 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 05:33:14 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include <stdlib.h>
# include <limits.h>
# include "command.h"
# include "utils.h"

typedef union u_content
{
	int			number;
	t_command	command;
}	t_content;

typedef struct s_node
{
	t_content		content;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	size_t	size;
	t_node	*front;
	t_node	*back;
}	t_deque;

typedef struct s_div_info
{
	int			large;
	int			small;
	t_deque		*commands;
	t_deque		*elements;
	t_deque		*l_q;
	t_deque		*m_q;
	t_deque		*s_q;
	t_deque		*hold;
	t_deque		*hold_after;
	t_command	l_command;
	t_command	m_command;
	t_command	s_command;
	t_command	hold_command;
	void		(*l_push)(struct s_div_info*, t_deque*, t_command);
	void		(*m_push)(struct s_div_info*, t_deque*, t_command);
	void		(*s_push)(struct s_div_info*, t_deque*, t_command);
	void		(*l_next)(t_deque*, t_deque*);
	void		(*m_next)(t_deque*, t_deque*);
	void		(*s_next)(t_deque*, t_deque*);
}	t_div_info;

t_deque	*create_deque(void);
t_node	*create_node(void);
t_node	*create_command_node(t_command command);
t_node	*create_number_node(int number);
void	delete_deque(t_deque *deque);
void	disjoint_node(t_deque *deque, t_node *ptr);
int		get_minelement(t_deque *deque);
t_node	*popback(t_deque *deque);
t_node	*popfront(t_deque *deque);
void	pushback(t_deque *deque, t_node *ptr);
void	pushfront(t_deque *deque, t_node *ptr);
void	popfront_and_pushfront(t_div_info *div_info, \
								t_deque *after, t_command command);
void	popfront_and_pushback(t_div_info *div_info, \
								t_deque *after, t_command command);
void	popback_and_pushfront(t_div_info *div_info, \
								t_deque *after, t_command command);
void	popback_and_pushback(t_div_info *div_info, \
								t_deque *after, t_command command);
#endif
