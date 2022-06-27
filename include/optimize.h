/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:15:23 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/28 00:19:09 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZE_H
# define OPTIMIZE_H
# include "command.h"
# include "deque.h"
void	optimize(t_deque *commands);
void	optimize_each_command(t_deque *commands);
void	optimize_pa(t_deque *commands, t_node **node);
void	optimize_pb(t_deque *commands, t_node **node);
void	optimize_ra(t_deque *commands, t_node **node);
void	optimize_rb(t_deque *commands, t_node **node);
void	optimize_rra(t_deque *commands, t_node **node);
void	optimize_rrb(t_deque *commands, t_node **node);
void	optimize_sametime_command(t_deque *commands);
// void	optimize_delete(t_deque *commands);
// void	delete_pbpa(t_deque *commands, t_node *pa_node);
// void	delete_papb(t_deque *commands, t_node *pb_node);
// void	delete_rrara(t_deque *commands, t_node *ra_node);
// void	delete_rarra(t_deque *commands, t_node *rra_node);
// void	delete_rrbrb(t_deque *commands, t_node *rb_node);
// void	delete_rbrrb(t_deque *commands, t_node *rrb_node);

#endif