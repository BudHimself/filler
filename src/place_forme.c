/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_forme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:32:31 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 20:00:08 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	cor_coor(t_env *env, int coor, int x_y)
{
	while (coor < 0)
		coor++;
	while ((x_y == 1 && coor > env->map_x) || (x_y == 2 && coor > env->map_y))
		coor--;
	return (coor);
}

int			*place_forme_top_left(t_env *env, int *ref)
{
	int		i;

	i = 0;
	env->p_found = 0;
	ref[0] = cor_coor(env, env->ref_p[0][0], 1) - 1;
	while (++ref[0] < env->map_x)
	{
		ref[1] = cor_coor(env, env->ref_p[0][1], 2) - 1;
		env->p_found = 0;
		while (++ref[1] < env->map_y)
		{
			i = check_every_place(env, ref, i);
			if (i == env->s_piece && env->p_found == 0)
				i = 0;
			else if (i == env->s_piece && env->p_found == 1)
				break ;
			i = 0;
			env->p_found = 0;
		}
		if (i == env->s_piece && env->p_found == 1)
			break ;
	}
	return (ref);
}

int			*place_forme_top_right(t_env *env, int *ref)
{
	int		i;

	i = 0;
	env->p_found = 0;
	ref[0] = cor_coor(env, env->ref_p[0][0], 1) - 1;
	while (++ref[0] < env->map_x)
	{
		ref[1] = env->map_y - cor_coor(env, env->ref_p[0][1], 2);
		env->p_found = 0;
		while (--ref[1] > -1)
		{
			i = check_every_place(env, ref, i);
			if (i == env->s_piece && env->p_found == 0)
				i = 0;
			else if (i == env->s_piece && env->p_found == 1)
				break ;
			i = 0;
			env->p_found = 0;
		}
		if (i == env->s_piece && env->p_found == 1)
			break ;
	}
	return (ref);
}

int			*place_forme_bottom_right(t_env *env, int *ref)
{
	int		i;

	i = 0;
	env->p_found = 0;
	ref[0] = env->map_x - cor_coor(env, env->ref_p[env->s_piece - 1][0], 1);
	while (--ref[0] > -1)
	{
		ref[1] = env->map_y - cor_coor(env, env->ref_p[env->s_piece - 1][1], 2);
		env->p_found = 0;
		while (--ref[1] > -1)
		{
			i = check_every_place(env, ref, i);
			if (i == env->s_piece && env->p_found == 0)
				i = 0;
			else if (i == env->s_piece && env->p_found == 1)
				break ;
			i = 0;
			env->p_found = 0;
		}
		if (i == env->s_piece && env->p_found == 1)
			break ;
	}
	return (ref);
}

int			*place_forme_bottom_left(t_env *env, int *ref)
{
	int		i;

	i = 0;
	env->p_found = 0;
	ref[0] = env->map_x - cor_coor(env, env->ref_p[env->s_piece - 1][0], 1);
	while (--ref[0] > -1)
	{
		ref[1] = cor_coor(env, env->ref_p[env->s_piece - 1][1], 2) - 1;
		env->p_found = 0;
		while (++ref[1] < env->map_y)
		{
			i = check_every_place(env, ref, i);
			if (i == env->s_piece && env->p_found == 0)
				i = 0;
			else if (i == env->s_piece && env->p_found == 1)
				break ;
			i = 0;
			env->p_found = 0;
		}
		if (i == env->s_piece && env->p_found == 1)
			break ;
	}
	return (ref);
}
