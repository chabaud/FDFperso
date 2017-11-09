/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 02:58:13 by schabaud          #+#    #+#             */
/*   Updated: 2016/05/13 12:16:57 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*(s1 + i) != '\0')
		i++;
	while ((s1[i + j] = s2[j]) != '\0')
		j++;
	return (s1);
}
