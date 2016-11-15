/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_captalizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:26:45 by fhenry            #+#    #+#             */
/*   Updated: 2016/10/22 18:13:00 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void		ft_str_capitalizer(char **str)
{
	int		i;

	i = -1;
	while (str[0][++i])
	{
		if (ft_islower(str[0][i]))
			str[0][i] += 'A' - 'a';
	}
}
