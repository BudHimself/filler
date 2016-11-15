/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farest_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:51:45 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 19:37:31 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		choose_the_way(t_env *env)
{
	int			*ret;

	if (!(ret = (int *)ft_memalloc(sizeof(int) * 2)))
		exit(-1);
	if (env->right && env->top)
		ret = place_forme_top_right(env, ret);
	else if (env->left && env->top)
		ret = place_forme_top_left(env, ret);
	else if (env->right && env->bottom)
		ret = place_forme_bottom_right(env, ret);
	else if (env->left && env->bottom)
		ret = place_forme_bottom_left(env, ret);
	push_res(env, ret);
	end_while(env, ret);
	free(ret);
}

static void		find_the_way(t_env *env, int position)
{
	int				x;
	int				y;

	if (position == FIRST)
	{
		x = env->player_x;
		y = env->player_y;
	}
	else
	{
		x = env->res_x;
		y = env->res_y;
	}
	if (y <= env->target_y)
		env->right = 1;
	else if (y > env->target_y)
		env->left = 1;
	if (x <= env->target_x)
		env->bottom = 1;
	else if (x > env->target_x)
		env->top = 1;
	choose_the_way(env);
}

void			farest_point(t_env *env)
{
	if (env->first_call == 0)
	{
		find_first_position(env);
		find_the_farest(env);
		find_the_way(env, FIRST);
		return ;
	}
	find_the_farest(env);
	find_the_way(env, 2);
}
