/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 02:54:32 by schabaud          #+#    #+#             */
/*   Updated: 2016/05/13 12:24:41 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 3;
	if (src <= dst && src + len >= dst)
		i = 1;
	d = (i == 1) ? d + len - 1 : d;
	s = (i == 1) ? s + len - 1 : s;
	while (len--)
	{
		*d = *s;
		d += i - 2;
		s += i - 2;
	}
	return (dst);
}
