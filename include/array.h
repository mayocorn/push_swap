/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_int_array.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:29:57 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/21 09:08:48 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <stdlib.h>
# include "../include/utils.h"
# include "../include/libft.h"

int	*duplicate_int_array(size_t size, int *src);
void check_unique(size_t size, int *array);
#endif