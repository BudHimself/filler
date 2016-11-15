/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:11:28 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/31 15:18:11 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void			save_res(t_env *env, int x, int y)
{
	if (env->top)
	{
		env->res_x = x + env->ref_p[0][0];
		env->res_y = y + env->ref_p[0][1];
	}
	else if (env->bottom)
	{
		env->res_x = x + env->ref_p[env->s_piece - 1][0];
		env->res_y = y + env->ref_p[env->s_piece - 1][1];
	}
}

static void			ft_free_map(t_env *env, char **tab)
{
	int				i;

	i = -1;
	while (++i < env->map_x)
		ft_strdel(&tab[i]);
	free(tab);
}

static void			free_ref_map(t_env *env)
{
	int				i;

	i = -1;
	while (++i < env->s_piece)
		free(env->ref_p[i]);
	free(env->ref_p);
}

void				push_res(t_env *env, int *ref)
{
	char			*x_res;
	char			*y_res;
	char			*res;

	x_res = ft_itoa(ref[0] - env->piece_x_abs_save - env->ppt_x);
	y_res = ft_itoa(ref[1] - env->piece_y_abs_save - env->ppt_y);
	res = ft_strnew(ft_strlen(x_res) + ft_strlen(y_res) + 1);
	res = ft_strcat(res, x_res);
	res = ft_strcat(res, " ");
	res = ft_strcat(res, y_res);
	save_res(env, ft_atoi(x_res), ft_atoi(y_res));
	ft_putendl(res);
	ft_free_map(env, env->mm);
	ft_strdel(&res);
	ft_strdel(&x_res);
	ft_strdel(&y_res);
	free_ref_map(env);
	free_piece_map(env);
}

int					main(void)
{
	t_env			env;
	char			*line;
	int				i;

	env.first_call = 0;
	env.boucle = 1;
	while (env.boucle)
	{
		i = -1;
		init_env(&env);
		while (env.piece != 1)
		{
			get_next_line(0, &line);
			parsing(&env, line);
			ft_strdel(&line);
		}
		while (++i < env.piece_x)
		{
			get_next_line(0, &line);
			parsing(&env, line);
			ft_strdel(&line);
		}
		check_map(&env);
	}
	return (0);
}
