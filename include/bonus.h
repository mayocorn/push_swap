/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:03:28 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 06:30:39 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include <stdbool.h>
# include "array.h"
# include "command.h"
# include "deque.h"
# include "get_next_line.h"
# include "libft.h"
# include "mergesort.h"
# include "utils.h"

void	check_array(size_t size, int *array);
void	check_commands(size_t array_size, int *array);
void	read_commands(t_deque *commands);
t_deque	*convert_array_to_deque(size_t size, int *array);
void	pushswap_by_commands(t_deque *commands, \
								t_deque *stack_a, t_deque *stack_b);
void	execute_command(t_command command, t_deque *stack_a, t_deque *stack_b);
void	execute_pa(t_deque *stack_a, t_deque *stack_b);
void	execute_pb(t_deque *stack_a, t_deque *stack_b);
void	execute_ra(t_deque *stack_a);
void	execute_rb(t_deque *stack_b);
void	execute_rr(t_deque *stack_a, t_deque *stack_b);
void	execute_rra(t_deque *stack_a);
void	execute_rrb(t_deque *stack_b);
void	execute_rrr(t_deque *stack_a, t_deque *stack_b);
void	execute_sa(t_deque *stack_a);
void	execute_sb(t_deque *stack_b);
void	execute_ss(t_deque *stack_a, t_deque *stack_b);
void	check_sorted(t_deque *stack_a, t_deque *stack_b);
#endif