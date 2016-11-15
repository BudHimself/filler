/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_size_and_ref.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:39:18 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 19:22:30 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void			free_piece_map(t_env *env)
{
	int			i;

	i = -1;
	while (++i < env->piece_x)
		ft_strdel(&env->piece_map[i]);
	free(env->piece_map);
}

static void		ref_abs(t_env *env)
{
	int			i;

	i = -1;
	while (++i < env->s_piece)
	{
		if (env->ref_p[i][0] < env->ppt_x)
			env->ppt_x = env->ref_p[i][0];
		if (env->ref_p[i][1] < env->ppt_y)
			env->ppt_y = env->ref_p[i][1];
	}
	if (env->ppt_x != INT_MAX)
	{
		i = -1;
		while (++i < env->s_piece)
			env->ref_p[i][0] -= env->ppt_x;
	}
	if (env->ppt_y != INT_MAX)
	{
		i = -1;
		while (++i < env->s_piece)
			env->ref_p[i][1] -= env->ppt_y;
	}
}

static void		save_ref_forme(t_env *env, int x, int y)
{
	int			**tab;
	int			i;
	int			len;

	i = -1;
	len = env->s_piece;
	if (!(tab = (int **)ft_memalloc(sizeof(int *) * len)))
		exit(-1);
	if (env->ref_p != NULL)
	{
		while (++i < env->s_piece - 1)
			tab[i] = env->ref_p[i];
		free(env->ref_p);
	}
	if (!(tab[env->s_piece - 1] = (int *)ft_memalloc(sizeof(int) * 2)))
		exit(-1);
	tab[env->s_piece - 1][0] = x;
	tab[env->s_piece - 1][1] = y;
	env->ref_p = tab;
}

void			find_size_and_ref(t_env *env)
{
	int			x;
	int			y;

	x = -1;
	while (++x < env->piece_x)
	{
		y = -1;
		while (++y < env->piece_y)
		{
			if (env->piece_map[x][y] == '*')
			{
				env->s_piece++;
				save_ref_forme(env, x, y);
			}
		}
	}
	ref_abs(env);
}
