/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:35:52 by xkubheka          #+#    #+#             */
/*   Updated: 2018/09/09 15:46:15 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		c;
	char		*dest;
	const char	*srcc;

	c = 0;
	srcc = (const char*)src;
	dest = (char*)dst;
	while (c < n)
	{
		dest[c] = srcc[c];
		c++;
	}
	return (dest);
}
