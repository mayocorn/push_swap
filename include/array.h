/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:29:57 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 04:48:55 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <stdlib.h>
# include <limits.h>
# include "utils.h"
# include "libft.h"
# define POSITIVE 1
# define NEGATIVE -1

int		*convert_array_str_to_int(size_t array_size, char **src);
int		*duplicate_int_array(size_t size, int *src);
void	check_unique(size_t size, int *array);
#endif