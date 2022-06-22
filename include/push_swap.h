/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:46:59 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/22 18:49:44 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "utils.h"
# include "deque.h"

t_deque	*push_swap(size_t size, int *array);
void	sort_a_start(t_deque *element_list, t_deque *command_list);
void	divide_a_start(t_deque *element_list, t_deque *command_list, t_deques *deques);
#endif