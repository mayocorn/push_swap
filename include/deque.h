/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:47:14 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/22 16:04:55 by mayocorn         ###   ########.fr       */
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
	t_deque	*large_q;
	t_deque	*med_q;
	t_deque	*small_q;
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
t_deques	*create_deques(void);

#endif