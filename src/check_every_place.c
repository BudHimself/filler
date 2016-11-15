/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_every_place.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:47:52 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 21:16:55 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			*f_norme(t_env *env, int *ref, int *ref_n)
{
	while (ref_n[3] < env->s_piece)
	{
		ref_n[0] = env->ref_p[ref_n[3]][0] + ref[0];
		ref_n[1] = env->ref_p[ref_n[3]][1] + ref[1];
		if (ref_n[0] >= env->map_x || ref_n[1] >= env->map_y ||
			ref_n[0] < 0 || ref_n[1] < 0)
			break ;
		else if (env->p_found < 1 && env->mm[ref_n[0]][ref_n[1]] == env->f_p)
		{
			ref_n[3]++;
			env->p_found++;
		}
		else if (env->mm[ref_n[0]][ref_n[1]] == env->empty)
		{
			ref_n[2]++;
			ref_n[3]++;
		}
		else
		{
			env->p_found = 0;
			ref_n[3] = 0;
			break ;
		}
	}
	return (ref_n);
}

int			check_every_place(t_env *env, int *ref, int index)
{
	int		*ref_n;
	int		i;

	if (!(ref_n = (int *)ft_memalloc(sizeof(int) * 4)))
		exit(-1);
	ref_n[0] = 0;
	ref_n[1] = 0;
	ref_n[2] = 0;
	ref_n[3] = index;
	ref_n = f_norme(env, ref, ref_n);
	if (ref_n[2] == env->s_piece)
	{
		ref_n[3] = 0;
		env->p_found = 0;
	}
	i = ref_n[3];
	free(ref_n);
	return (i);
}
