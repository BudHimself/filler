/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:50:16 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/20 18:33:18 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	save_pos(t_env *env, int player, char *forme_x_s, char forme_x_c)
{
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (++x < env->map_x)
		if (ft_strstr(env->mm[x], forme_x_s))
			break ;
	while (env->mm[x][y] != forme_x_c)
		y++;
	if (player == 1)
	{
		env->player_x = x;
		env->player_y = y;
	}
	else
	{
		env->target_x = x;
		env->target_y = y;
	}
}

void		find_first_position(t_env *env)
{
	if (env->player == 1)
	{
		save_pos(env, PLAYER, "O", 'O');
		save_pos(env, ENEMY, "X", 'X');
	}
	else
	{
		save_pos(env, PLAYER, "X", 'X');
		save_pos(env, ENEMY, "O", 'O');
	}
}
