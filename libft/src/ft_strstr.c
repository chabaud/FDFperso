/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 03:10:33 by schabaud          #+#    #+#             */
/*   Updated: 2016/05/13 12:31:31 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
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
				&& *(s1 + i + j) && *(s2 + j))
			j++;
		if (*(s2 + j) == '\0')
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
