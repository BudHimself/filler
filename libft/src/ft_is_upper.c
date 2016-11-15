/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_upper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 21:02:08 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/21 21:04:30 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int			ft_is_upper(char *str, int index)
{
	if (str[index] > 64 && str[index] < 91)
		return (1);
	else
		return (0);
}
