/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 03:08:55 by schabaud          #+#    #+#             */
/*   Updated: 2016/05/13 12:23:12 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	pos;
	size_t	found;

	pos = 0;
	found = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char)c)
		{
			found++;
			pos = i;
		}
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	if (found)
		return ((char *)s + pos);
	return (NULL);
}
