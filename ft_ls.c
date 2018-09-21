/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:18:55 by xkubheka          #+#    #+#             */
/*   Updated: 2018/09/10 14:47:21 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_rev_list(t_dir **head_ref)
{
	t_dir	*prev;
	t_dir	*current;
	t_dir	*next;

	current = *head_ref;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void		cap_r(t_dir *list, t_env *e)
{
	t_dir *tmp;

	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->is_dir == 1 && tmp->dir[0] != '.')
			make_ls(tmp->full_path, e);
		tmp = tmp->next;
	}
}

void		ft_print_ls(t_dir *list, t_env *v, char *path)
{
	t_dir	*tmp;

	if (v->t == 1)
		swap_lists(&list, compare_time, 0);
	if (v->r == 1)
		ft_rev_list(&list);
	if (v->rr == 1)
		ft_putstr(ft_strjoin(path, ":\n"));
	if (v->l == 1)
		disp_l(list);
	else
	{
		tmp = list;
		while (tmp != NULL)
		{
			ft_putstr(tmp->dir);
			tmp = tmp->next;
			if (tmp != NULL)
				ft_putchar('\n');
		}
	}
	ft_putchar('\n');
	if (v->rr == 1)
		cap_r(list, v);
}

int			ft_file_checker(t_env *e)
{
	if ((e->dirp = opendir(".")) != NULL)
	{
		while ((e->dp = readdir(e->dirp)) != NULL)
		{
			lstat(e->dp->d_name, &e->sb);
			if (S_ISREG(e->sb.st_mode) &&
					ft_strcmp(e->dp->d_name, e->list->dir) == 0)
			{
				ft_putendl(e->dp->d_name);
				return (1);
			}
			else if (!ft_strcmp(e->dp->d_name, e->list->dir))
			{
				ft_putstr("ft_ls: ");
				ft_putstr(e->list->dir);
				ft_putendl(": Permission denied");
				return (-1);
			}
		}
		ft_putstr("ft_ls: ");
		ft_putstr(e->list->dir);
		ft_putendl(": No such file or directory");
		return (-1);
	}
	return (0);
}
