/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 03:08:21 by schabaud          #+#    #+#             */
/*   Updated: 2016/05/13 12:24:21 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*(s1 + i))
	{
		j = 0;
		while (*(s1 + i + j) == *(s2 + j)
				&& *(s1 + i + j) && *(s2 + j) && i + j < n)
			j++;
		if (*(s2 + j) == '\0')
			return ((char *)s1 + i);
		if (i + j == n)
			return (NULL);
		i++;
	}
	return (NULL);
}
