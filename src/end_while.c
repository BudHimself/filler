/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_while.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:59:31 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 19:27:54 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		end_while(t_env *env, int *ret)
{
	if (ret[0] >= env->map_x && ret[1] >= -1)
		env->boucle = 0;
	else if (ret[0] >= env->map_x && ret[1] >= env->map_y)
		env->boucle = 0;
	else if (ret[0] <= -1 && ret[1] <= -1)
		env->boucle = 0;
	else if (ret[0] >= -1 && ret[1] >= env->map_y)
		env->boucle = 0;
}
