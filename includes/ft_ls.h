/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:37:58 by xkubheka          #+#    #+#             */
/*   Updated: 2018/09/11 13:18:01 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/dir.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <time.h>

typedef struct		s_dir
{
	char			*dir;
	char			*full_path;
	time_t			time;
	int				is_dir;
	struct s_dir	*next;
}					t_dir;

typedef struct		s_env
{
	int				l;
	int				a;
	int				r;
	int				t;
	int				rr;
	char			*path;
	DIR				*dirp;
	struct dirent	*dp;
	struct stat		sb;
	t_dir			*list;
}					t_env;

void				ft_ls(t_env *e);
void				make_ls(char *dir, t_env *e);
int					compare_time(t_dir d1, t_dir d2);
int					compare_str(t_dir d1, t_dir d2);
void				swap_lists(t_dir **head, int (*cmp)
					(t_dir, t_dir), int done);
void				make_list(t_env *e);
void				disp_l(t_dir *list);
void				ft_print_ls(t_dir *list, t_env *v, char *path);
int					ft_file_checker(t_env *e);

#endif
