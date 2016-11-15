/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:06:39 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 11:47:22 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static char		**malloc_map(int size)
{
	char		**tmp;

	tmp = NULL;
	if (!(tmp = (char **)ft_memalloc(sizeof(char *) * size)))
		exit(-1);
	return (tmp);
}

static void		parse_map(t_env *env, char *line, int choice)
{
	char		**split;

	if (ft_strstr(line, "    ") || ft_strstr(line, "\t"))
		return ;
	split = ft_strsplit(line, ' ');
	if (choice == MAP)
	{
		if (!env->mm)
			env->mm = malloc_map(env->map_x);
		env->mm[env->index_fill_map++] = ft_strdup(split[1]);
		ft_free_tab(split);
		return ;
	}
	if (!env->piece_map)
		env->piece_map = malloc_map(env->piece_x);
	env->piece_map[env->index_fill_piece++] = ft_strdup(line);
	ft_free_tab(split);
}

static void		parse_dimension(t_env *env, char *line, int choice)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	if (choice == 1)
	{
		env->map_x = ft_atoi(split[1]);
		env->map_y = ft_atoi(split[2]);
		env->map = 1;
	}
	else
	{
		env->piece_x = ft_atoi(split[1]);
		env->piece_y = ft_atoi(split[2]);
		env->piece = 1;
	}
	ft_free_tab(split);
}

static void		parse_player(t_env *env, char *line)
{
	char		**split;

	split = ft_strsplit(line, ' ');
	if (ft_strequ(split[2], "p1"))
	{
		env->player = 1;
		env->f_p = 'O';
		env->enemy = 2;
		env->full_enemy = 'X';
	}
	else if (ft_strequ(split[2], "p2"))
	{
		env->player = 2;
		env->f_p = 'X';
		env->enemy = 1;
		env->full_enemy = 'O';
	}
	ft_free_tab(split);
}

void			parsing(t_env *env, char *line)
{
	if (env->first_call == 0 && ft_strstr(line, "$$$"))
		parse_player(env, line);
	else if (ft_strstr(line, "Plateau"))
		parse_dimension(env, line, MAP);
	else if (ft_strstr(line, "Piece"))
		parse_dimension(env, line, PIECE);
	else if (env->map && !env->piece)
		parse_map(env, line, MAP);
	else if (env->map && env->piece)
		parse_map(env, line, PIECE);
}
