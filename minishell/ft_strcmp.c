/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 22:47:48 by nainhaja          #+#    #+#             */
/*   Updated: 2019/07/16 07:26:21 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_div_mod(const char *str)
{
	int cpt;

	cpt = 0;
	while (*str)
	{
		cpt++;
		str++;
	}
	return (cpt);
}

int	ft_strcmp(const char *str, const char *to_find)
{
	int i;
	int len;
	int cpt;
	int len2;

	i = 0;
	cpt = 0;
	len2 = ft_div_mod(to_find);
	len = ft_div_mod(str);
	if (len < len2)
		return (-1);
	while (i < len)
	{
		cpt = str[i] - to_find[i];
		if (cpt != 0)
			return (cpt);
		i++;
	}
	return (0);
}
