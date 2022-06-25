/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_next_division.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:41:57 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/25 17:07:16 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdio.h>
void	sort_next_division(t_div_info *div_info)
{
	div_info -> l_next(div_info -> l_q, div_info -> commands);
	div_info -> m_next(div_info -> m_q, div_info -> commands);
	div_info -> s_next(div_info -> s_q, div_info -> commands);
	free(div_info);
}
