/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:47:14 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/23 19:19:42 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H
# include <stdlib.h>
# include "command.h"
# include "utils.h"

typedef struct s_deque
{
	size_t	size;
	void	*front;
	void	*back;
}	t_deque;

typedef struct s_deques
{
	int		large;
	int		small;
	t_deque	*commands;
	t_deque	*elements;
	t_deque	*af;
	t_deque	*ab;
	t_deque	*bf;
	t_deque	*bb;
}	t_deques;

typedef union u_content
{
	int			number;
	t_command	command;
} t_content;

typedef struct s_node
{
	t_content	content;
	void	*prev;
	void	*next;
}	t_node;

t_deque	*create_deque(void);
void	pushback(t_deque *deque, t_node *ptr);
void	pushfront(t_deque *deque, t_node *ptr);
t_node	*popback(t_deque *deque);
t_node	*popfront(t_deque *deque);
t_node	*create_node(void);
t_node	*create_command_node(t_command command);
t_node	*create_number_node(int number);
void	disjoint_node(t_deque *deque, t_node *ptr);
void	delete_deque(t_deque *deque);
t_deques	*create_deques(t_deque *elements, t_deque *commands);
void	popfront_and_pushfront(t_deques *deques, \
								t_deque *after, t_command command);
void	popfront_and_pushback(t_deques *deques, \
								t_deque *after, t_command command);
void	popback_and_pushfront(t_deques *deques, \
								t_deque *after, t_command command);
void	popback_and_pushback(t_deques *deques, \
								t_deque *after, t_command command);
#endif