/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:36:30 by fhenry            #+#    #+#             */
/*   Updated: 2016/06/14 17:36:33 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int			ft_atoi(const char *nptr)
{
	int		res;
	int		cup;

	res = 0;
	if (nptr == NULL || nptr == 0 || nptr[0] == '\0')
		return (res);
	while (nptr[0] == '\n' || nptr[0] == '\v' || nptr[0] == '\t'
			|| nptr[0] == ' ' || nptr[0] == '\f' || nptr[0] == '\r')
		nptr++;
	cup = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		cup = (*nptr == '-') ? -cup : cup;
		nptr++;
	}
	while (*nptr && *nptr >= 48 && *nptr <= 57)
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * cup);
}
