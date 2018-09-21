/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:36:52 by xkubheka          #+#    #+#             */
/*   Updated: 2018/09/09 16:09:53 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		c;
	int		len1;
	int		len2;
	char	*cpy;

	c = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(cpy = (char*)malloc(sizeof(char) * (len1 + len2) + 1)))
		return (NULL);
	while (c < len1 + len2)
	{
		if (c < len1)
			cpy[c] = s1[c];
		else
			cpy[c] = s2[c - len1];
		c++;
	}
	cpy[c] = '\0';
	return (cpy);
}
