/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_farest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:57:24 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/20 21:00:11 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		check_ref(t_env *env, int *target, int *tmp_ref, int *ref)
{
	tmp_ref[0] = ref[0] - target[0];
	if (tmp_ref[0] < 0)
		tmp_ref[0] *= -1;
	tmp_ref[1] = ref[1] - target[1];
	if (tmp_ref[1] < 0)
		tmp_ref[1] *= -1;
	if ((tmp_ref[0] + tmp_ref[1]) > env->sum_x_y)
	{
		env->target_x = ref[0];
		env->target_y = ref[1];
		env->sum_x_y = tmp_ref[0] + tmp_ref[1];
	}
}

static int		*ref_target(t_env *env, int *target)
{
	if (env->first_call == 0)
	{
		target[0] = env->player_x;
		target[1] = env->player_y;
	}
	else
	{
		target[0] = env->res_x;
		target[1] = env->res_y;
	}
	return (target);
}

void			find_the_farest(t_env *env)
{
	int			*ref;
	int			*tmp_ref;
	int			*target;

	if (!(tmp_ref = (int *)ft_memalloc(sizeof(int) * 2)))
		exit(-1);
	if (!(ref = (int *)ft_memalloc(sizeof(int) * 2)))
		exit(-1);
	if (!(target = (int *)ft_memalloc(sizeof(int) * 2)))
		exit(-1);
	target = ref_target(env, target);
	tmp_ref[0] = -1;
	tmp_ref[1] = -1;
	ref[0] = -1;
	while (++ref[0] < env->map_x)
	{
		ref[1] = -1;
		while (++ref[1] < env->map_y)
			if (env->mm[ref[0]][ref[1]] == env->full_enemy)
				check_ref(env, target, tmp_ref, ref);
	}
	free(ref);
	free(tmp_ref);
	free(target);
}
