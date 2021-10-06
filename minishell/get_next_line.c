/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:17:13 by nainhaja          #+#    #+#             */
/*   Updated: 2019/11/07 00:41:50 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 40



int			get_boucle(char **test, int *i, int fds)
{
	int		j;
	char	*temp;
	char	*buff;

	while (1)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		j = read(fds, buff, BUFFER_SIZE);
		if (j == 0)
		{
			free(buff);
			return (0);
		}
		buff[j] = '\0';
		temp = *test;
		*test = ft_strjoin(*test, buff);
		free(temp);
		while (test[0][*i] != '\n' && test[0][*i] != '\0')
			*i = *i + 1;
		free(buff);
		if (test[0][*i] == '\n')
			break ;
	}
	return (1);
}

int			get_lastline(char **line, char **test)
{
	line[0] = ft_strdup(*test);
	free(*test);
	*test = NULL;
	return (0);
}

int			get_next_line(int fds, char **line)
{
	char		*temp;
	static char	*test;
	int			i;

	
	if (fds < 0 || read(fds, NULL, 0) != 0)
		return (-1);
	i = 0;
	if (!test)
		test = ft_strdup("");
	if (ft_strchr(test, '\n') == 0 && get_boucle(&test, &i, fds) == 0)
		return (get_lastline(line, &test));
	else
		while (test[i] != '\n')
			i++;
	line[0] = ft_substr(test, 0, i);
	temp = test;
	test = ft_strchr(test, '\n');
	if (*test == '\n')
	{
		test = ft_substr(test, 1, ft_strlen(test) - 1);
		free(temp);
	}
	return (1);
}
