/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:43:47 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_cp;
	const char	*src_cp;

	dest_cp = (char *)dest;
	src_cp = (const char *)src;
	if (dest == src)
		return (dest);
	while (n--)
	{
		if (dest < src)
			*(dest_cp++) = *(src_cp++);
		else
			*(dest_cp + n) = *(src_cp + n);
	}
	return (dest);
}
