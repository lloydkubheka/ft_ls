/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:34:40 by xkubheka          #+#    #+#             */
/*   Updated: 2018/09/09 15:42:10 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	unsigned int c;

	c = 0;
	if (s)
	{
		while (s[c] != '\0')
		{
			write(1, &s[c], 1);
			c++;
		}
		write(1, "\n", 1);
	}
}
