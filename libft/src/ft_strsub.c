/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2100/01/01 00:00:00 by schabaud          #+#    #+#             */
/*   Updated: 2016/08/19 15:55:17 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	if (ft_strlen(s) < start)
		return (NULL);
	if ((tmp = (char*)malloc(sizeof(tmp) * len + 1)) == NULL)
		return (NULL);
	while (i < len && s[start])
		tmp[i++] = s[start++];
	tmp[i] = '\0';
	return (tmp);
}
