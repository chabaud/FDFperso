/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 03:02:39 by schabaud          #+#    #+#             */
/*   Updated: 2016/05/13 12:20:48 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	tmp = NULL;
	if (s1 && s2)
	{
		if ((tmp = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
			return (NULL);
		tmp = ft_strcpy(tmp, s1);
		tmp = ft_strcat(tmp, s2);
	}
	return (tmp);
}
