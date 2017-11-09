/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 14:42:17 by schabaud          #+#    #+#             */
/*   Updated: 2016/08/11 14:46:05 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		lenght;
	char	tmp;

	if (str)
	{
		i = 0;
		lenght = ft_strlen(str);
		while (i < lenght / 2)
		{
			tmp = str[i];
			str[i] = str[lenght - i - 1];
			str[lenght - i - 1] = tmp;
			i++;
		}
	}
	return (str);
}
