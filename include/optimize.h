/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:15:23 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 17:00:07 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZE_H
# define OPTIMIZE_H
# include "command.h"
# include "deque.h"

void	optimize(t_deque *commands);
void	optimize_each_command(t_deque *commands);
void	optimize_sametime_command(t_deque *commands);
void	optimize_pa(t_deque *commands, t_node **node);
void	optimize_pa_sub(t_deque *commands, t_node **node);
void	optimize_pb(t_deque *commands, t_node **node);
void	optimize_pb_sub(t_deque *commands, t_node **node);
void	optimize_ra(t_deque *commands, t_node **node);
void	optimize_rb(t_deque *commands, t_node **node);
void	optimize_rra(t_deque *commands, t_node **node);
void	optimize_rra_sub(t_deque *commands, t_node **node);
void	optimize_rrb(t_deque *commands, t_node **node);
void	optimize_rrb_sub(t_deque *commands, t_node **node);

#endif