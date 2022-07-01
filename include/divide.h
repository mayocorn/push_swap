/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 07:23:58 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 05:11:42 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIVIDE_H
# define DIVIDE_H
# include "deque.h"
# include "pushswap.h"

t_div_info	*create_div_info(t_deque *elements, t_deque *commands);
void		divide(t_div_info *div_info);
void		check_div_abbbbf(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
void		check_div_abbfbb(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
void		check_div_afabbb(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
void		check_div_afbbab(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
void		check_div_afbbbf(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
void		check_div_afbfbb(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
void		check_div_bbabbf(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
void		check_div_bbbfab(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
void		check_div_bfabbb(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
void		check_div_bfbbab(t_div_info *div_info, \
								size_t *max_cnt, int min_element);
#endif
