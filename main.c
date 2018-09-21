/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:20:33 by xkubheka          #+#    #+#             */
/*   Updated: 2018/09/10 14:36:53 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			av_add(t_env *en, char *args)
{
	int c;

	c = 1;
	while (args[c] != '\0')
	{
		if (args[c] == 'l')
			en->l = 1;
		else if (args[c] == 'a')
			en->a = 1;
		else if (args[c] == 'r')
			en->r = 1;
		else if (args[c] == 't')
			en->t = 1;
		else if (args[c] == 'R')
			en->rr = 1;
		else
		{
			ft_putstr(args);
			ft_putendl(": Invalid argument");
			return (0);
		}
		c++;
	}
	return (1);
}

int			compare_str(t_dir d1, t_dir d2)
{
	return (ft_strcmp(d1.dir, d2.dir));
}

int			compare_time(t_dir d1, t_dir d2)
{
	if (d1.time < d2.time)
		return (1);
	else
		return (0);
}

void		swap_lists(t_dir **head, int (*cmp)(t_dir, t_dir), int done)
{
	t_dir	**src;
	t_dir	*tmp;
	t_dir	*next;

	while (!done && *head != NULL && (*head)->next != NULL)
	{
		src = head;
		tmp = *head;
		next = (*head)->next;
		done = 1;
		while (next)
		{
			if (cmp(*tmp, *next) > 0)
			{
				tmp->next = next->next;
				next->next = tmp;
				*src = next;
				done = 0;
			}
			src = &tmp->next;
			tmp = next;
			next = next->next;
		}
	}
}

int			main(int ac, char **av)
{
	int		c;
	t_env	en;
	t_dir	*tmp;

	c = 1;
	en.list = NULL;
	while (c < ac)
	{
		if (av[c][0] != '-' && (tmp = (t_dir *)malloc(sizeof(t_dir))))
		{
			tmp->dir = av[c];
			tmp->next = en.list;
			en.list = tmp;
		}
		else if (av_add(&en, av[c]) == 0)
			return (0);
		c++;
	}
	if (en.list == NULL)
		make_list(&en);
	ft_ls(&en);
}
