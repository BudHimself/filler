/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 20:04:38 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 20:04:39 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/include/printf.h"

# define MAP 1
# define PIECE 2
# define PLAYER 1
# define ENEMY 2
# define FIRST 1
# define TOP_RIGHT 1
# define TOP_LEFT 2
# define BOTTOM_RIGHT 3
# define BOTTOM_LEFT 4

typedef struct	s_env
{
	char		empty;
	char		f_p;
	char		full_enemy;
	int			boucle;
	int			player;
	int			p_found;
	int			player_x;
	int			player_y;
	int			enemy;
	int			target_x;
	int			target_y;
	int			sum_x_y;
	int			right;
	int			left;
	int			top;
	int			bottom;
	int			cursor_piece_x;
	int			cursor_piece_y;
	int			first_call;
	int			map;
	int			index_fill_map;
	int			map_x;
	int			map_y;
	int			piece;
	int			index_fill_piece;
	int			piece_x;
	int			piece_y;
	int			piece_x_abs_save;
	int			piece_y_abs_save;
	int			s_piece;
	int			num_res;
	int			**tmp_res;
	int			res_x;
	int			res_y;
	int			ppt_x;
	int			ppt_y;
	int			**ref_p;
	char		**mm;
	char		**piece_map;
}				t_env;

void			print_map(t_env *env);

void			parsing(t_env *env, char *line);
void			find_size_and_ref(t_env *env);
void			find_position(t_env *env);
void			check_map(t_env *env);
void			push_res(t_env *env, int *ret);
int				*place_forme_bottom_left(t_env *env, int *ref);
int				*place_forme_bottom_right(t_env *env, int *ref);
int				*place_forme_top_left(t_env *env, int *ref);
int				*place_forme_top_right(t_env *env, int *ref);
void			farest_point(t_env *env);
void			end_while(t_env *env, int *ret);
void			find_the_farest(t_env *env);
void			ft_free_tab(char **tab);
void			find_first_position(t_env *env);
int				check_every_place(t_env *env, int *ref, int index);
void			init_env(t_env *env);
void			free_piece_map(t_env *env);

#endif
