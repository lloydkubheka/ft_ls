/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:33:57 by xkubheka          #+#    #+#             */
/*   Updated: 2018/09/09 16:08:55 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*s;
	int				size;
	unsigned int	n_cpy;

	size = ft_int_len(n);
	n_cpy = n;
	if (n < 0)
	{
		n_cpy = -n;
		size++;
	}
	if (!(s = ft_strnew(size)))
		return (NULL);
	s[--size] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		s[--size] = n_cpy % 10 + '0';
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}
