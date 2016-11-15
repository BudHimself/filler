/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/14 17:39:07 by fhenry            #+#    #+#             */
/*   Updated: 2016/09/30 22:07:55 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	return (ft_strnstr(s1, s2, ft_strlen(s1)));
}