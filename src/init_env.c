/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 18:05:30 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 14:50:45 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void		init_env2(t_env *env)
{
	env->cursor_piece_x = 0;
	env->cursor_piece_y = 0;
	env->map = 0;
	env->index_fill_map = 0;
	env->map_x = 0;
	env->map_y = 0;
	env->piece = 0;
	env->index_fill_piece = 0;
	env->piece_x = 0;
	env->piece_y = 0;
	env->piece_x_abs_save = 0;
	env->piece_y_abs_save = 0;
	env->s_piece = 0;
	env->ppt_x = INT_MAX;
	env->ppt_y = INT_MAX;
	env->ref_p = NULL;
	env->mm = NULL;
	env->piece_map = NULL;
}

void			init_env(t_env *env)
{
	if (env->first_call == 0)
	{
		env->empty = '.';
		env->f_p = '\0';
		env->full_enemy = '\0';
		env->player = 0;
		env->enemy = 0;
		env->res_x = 0;
		env->res_y = 0;
	}
	env->player_x = 0;
	env->player_y = 0;
	env->target_x = 0;
	env->target_y = 0;
	env->sum_x_y = 0;
	env->right = 0;
	env->left = 0;
	env->top = 0;
	env->bottom = 0;
	init_env2(env);
}
