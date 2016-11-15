/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:38:50 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/20 18:59:57 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void				check_map(t_env *env)
{
	int				x;
	int				y;

	x = -1;
	while (++x < env->map_x)
	{
		y = -1;
		while (++y < env->map_y)
		{
			if (env->mm[x][y] == 'o' || env->mm[x][y] == 'x')
				env->mm[x][y] -= 32;
		}
	}
	find_size_and_ref(env);
	farest_point(env);
	env->first_call = 1;
}
