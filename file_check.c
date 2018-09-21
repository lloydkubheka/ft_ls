/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 16:28:29 by xkubheka          #+#    #+#             */
/*   Updated: 2018/09/10 13:38:16 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_ls(t_env *e)
{
	t_dir	*xp;

	xp = e->list;
	while (xp != NULL)
	{
		make_ls(xp->dir, e);
		xp = xp->next;
	}
}

void		make_ls(char *dir, t_env *e)
{
	t_dir	*list;
	t_dir	*xp;

	list = NULL;
	if ((e->dirp = opendir(dir)) != NULL)
	{
		while ((e->dp = readdir(e->dirp)) != NULL)
		{
			if (e->dp->d_name[0] != '.' || e->a == 1)
			{
				xp = (t_dir *)malloc(sizeof(t_dir));
				xp->dir = e->dp->d_name;
				xp->full_path = ft_strjoin(ft_strjoin(dir, "/"), e->dp->d_name);
				lstat(xp->full_path, &e->sb);
				xp->time = e->sb.st_mtime;
				(S_ISDIR(e->sb.st_mode) == 1) ? xp->is_dir = 1 : 0;
				xp->next = list;
				list = xp;
			}
		}
		swap_lists(&list, compare_str, 0);
		ft_print_ls(list, e, dir);
		return ;
	}
	ft_file_checker(e);
}
