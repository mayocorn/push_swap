/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_array_stoi.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:00:58 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/21 09:28:13 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_ARRAY_STOI_H
# define CONVERT_ARRAY_STOI_H
# include <stdlib.h>
# include <limits.h>
# include "utils.h"
# include "libft.h"
# define POSITIVE 1
# define NEGATIVE -1

int	*convert_array_str_to_int(size_t array_size, char **src);
#endif