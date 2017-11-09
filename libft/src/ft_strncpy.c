/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 03:06:24 by schabaud          #+#    #+#             */
/*   Updated: 2016/05/13 12:17:47 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0 && *(src + i) != '\0')
	{
		*(dst + i) = *(src + i);
		n--;
		i++;
	}
	while (n > 0)
	{
		*(dst + i) = '\0';
		i++;
		n--;
	}
	return (dst);
}
