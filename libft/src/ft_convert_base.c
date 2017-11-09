/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:26:38 by schabaud          #+#    #+#             */
/*   Updated: 2016/08/19 15:53:50 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_power(long long nb, long long pow)
{
	if (pow < 0)
		return (0);
	if (pow == 0)
		return (1);
	if (pow >= 2)
		return (nb * ft_power(nb, pow - 1));
	else
		return (nb);
}

static size_t	ten_base(char *nbr, char *base_from)
{
	long long	v_ten;
	long long	l_nbr;
	int			i;
	int			j;

	l_nbr = ft_strlen(nbr);
	v_ten = 0;
	i = -1;
	while (nbr[++i])
	{
		j = -1;
		while (nbr[i] != base_from[++j])
			;
		v_ten += j * ft_power(ft_strlen(base_from), l_nbr - i - 1);
	}
	return (v_ten);
}

char			*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*txt;
	long long	b_ten;
	long long	len_base;
	long long	i;

	b_ten = ten_base(nbr, base_from);
	len_base = ft_strlen(base_to);
	txt = (char*)malloc(sizeof(char) * (32));
	i = 0;
	if (b_ten != '\0')
		while (b_ten > 0)
		{
			txt[i] = base_to[b_ten % len_base];
			b_ten /= len_base;
			++i;
		}
	else
		txt[i++] = base_to[0];
	txt[i] = '\0';
	return (ft_strrev(txt));
}
