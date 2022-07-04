/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_next_division.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:41:57 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_next_division(t_div_info *div_info)
{
	div_info -> l_next(div_info -> l_q, div_info -> commands);
	div_info -> m_next(div_info -> m_q, div_info -> commands);
	div_info -> s_next(div_info -> s_q, div_info -> commands);
	free(div_info);
}
