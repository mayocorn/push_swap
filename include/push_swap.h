/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:46:59 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 01:31:49 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "utils.h"
# include "deque.h"
# include "division.h"

typedef struct s_hold_info{
	t_deque		*hold;
	t_deque		*hold_after;
	t_deque		*elements;
	t_deque		*elements_after;
	t_deque		*commands;
	t_command	command_hold;
	t_command	command_elements;
}	t_hold_info;

t_deque	*push_swap(size_t size, int **array);
void	sort_a_start(t_deque *element_list, t_deque *command_list);

// void	sort_a_maxvalue(t_deque *element_list, t_deque *command_list, int min_element);
void	delete_back_ra(t_deques *deques);
void	move_hold_all(t_deque *hold, t_deque *after, t_deque *commands, t_command command);
void	move_hold_one(t_hold_info args);
#endif