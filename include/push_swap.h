/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:46:59 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/25 16:48:34 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "utils.h"
# include "deque.h"
# include "divide.h"

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
void	sort_a_start(t_deque *elements, t_deque *commands);
void	sort_a_front(t_deque *elements, t_deque *commands);
void	sort_a_back(t_deque *elements, t_deque *commands);
void	sort_b_front(t_deque *elements, t_deque *commands);
void	sort_b_back(t_deque *elements, t_deque *commands);
void	sort_a_maxvalue(t_deque *elements, t_deque *commands);
void	sort_b_minvalue(t_deque *elements, t_deque *commands);

void	sort_next_division(t_div_info *div_info);

void	delete_back_ra(t_div_info *div_info);
void	delete_back_rb(t_div_info *div_info);

void	move_hold_all(t_div_info *div_info, t_deque *after, t_command command);
void	move_hold_one(t_div_info *div_info, t_deque *after, t_command command);
void	swap_hold(t_div_info *div_info);
#endif