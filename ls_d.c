/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:31:03 by xkubheka          #+#    #+#             */
/*   Updated: 2018/09/10 14:11:02 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_time(struct stat fstat, t_dir *temp)
{
	char	buff[13];
	char	*s;
	char	buf[64];
	size_t	size;

	(void)fstat;
	s = ctime(&temp->time);
	ft_memcpy(buff, &s[4], 12);
	buff[12] = '\0';
	ft_putstr(buff);
	ft_putstr(" ");
	ft_putstr(temp->dir);
	if (S_ISLNK(fstat.st_mode))
	{
		ft_putstr(" -> ");
		size = readlink(temp->full_path, buf, 64);
		buf[size] = '\0';
		ft_putstr(buf);
	}
}

void		make_list(t_env *e)
{
	e->list = (t_dir *)malloc(sizeof(t_dir));
	e->list->dir = ".";
	e->list->next = NULL;
}

char		*ret_user(struct stat fstat)
{
	char			*s;
	struct passwd	*pwd;
	struct group	*gr;

	pwd = getpwuid(fstat.st_uid);
	gr = getgrgid(fstat.st_gid);
	s = ft_strjoin(ft_strjoin(pwd->pw_name, "  "), gr->gr_name);
	return (ft_strjoin(s, "  "));
}

void		ret_permissions(t_dir *temp, struct stat fstat)
{
	if (temp->is_dir)
		ft_putchar('d');
	else
	{
		ft_putchar((S_ISLNK(fstat.st_mode)) ? 'l' : '-');
		ft_putchar((fstat.st_mode & S_IRUSR) ? 'r' : '-');
		ft_putchar((fstat.st_mode & S_IWUSR) ? 'w' : '-');
		ft_putchar((fstat.st_mode & S_IXUSR) ? 'x' : '-');
		ft_putchar((fstat.st_mode & S_IRGRP) ? 'r' : '-');
		ft_putchar((fstat.st_mode & S_IWGRP) ? 'w' : '-');
		ft_putchar((fstat.st_mode & S_IXGRP) ? 'x' : '-');
		ft_putchar((fstat.st_mode & S_IROTH) ? 'r' : '-');
		ft_putchar((fstat.st_mode & S_IWOTH) ? 'w' : '-');
		ft_putchar((fstat.st_mode & S_IXOTH) ? 'x' : '-');
		ft_putstr("  ");
	}
}

void		disp_l(t_dir *list)
{
	t_dir		*tmp;
	struct stat	fstat;
	char		*bytes;
	int			size;
	int			c;

	tmp = list;
	while (tmp != NULL)
	{
		lstat(tmp->full_path, &fstat);
		ret_permissions(tmp, fstat);
		ft_putnbr(fstat.st_nlink);
		ft_putstr(" ");
		ft_putstr(ret_user(fstat));
		c = 5;
		bytes = ft_itoa(fstat.st_size);
		size = ft_strlen(bytes);
		while (c-- > size)
			ft_putchar(' ');
		ft_putstr(ft_strjoin(bytes, "  "));
		get_time(fstat, tmp);
		tmp = tmp->next;
		if (tmp != NULL)
			ft_putchar('\n');
	}
}
