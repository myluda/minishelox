/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:40:32 by nainhaja          #+#    #+#             */
/*   Updated: 2019/10/23 00:42:54 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		**ft_remplir(const char *s, char c, char **t, int i)
{
	size_t	cpt;
	int		j;

	cpt = 0;
	while (s[cpt])
	{
		j = 0;
		while (s[cpt] == c && s[cpt] != '\0')
			cpt++;
		if (s[cpt] == '\0')
			break ;
		while (s[cpt] != c && s[cpt] != '\0')
		{
			t[i][j] = s[cpt];
			cpt++;
			j++;
		}
		t[i][j] = '\0';
		i++;
		cpt++;
		if (cpt > ft_strlen(((char*)s)))
			break ;
	}
	t[i] = 0;
	return (t);
}

static int		ft_word_count(const char *s, char c)
{
	int cpt;
	int i;

	i = 0;
	cpt = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (cpt);
		cpt++;
		while (s[i] != c)
		{
			i++;
			if (s[i] == '\0')
				return (cpt);
		}
	}
	return (cpt);
}

static int		ft_letter_count(char const *s, char c, int *j)
{
	int cpt;

	cpt = 0;
	while (s[*j] == c)
		*j = *j + 1;
	if (s[*j] == '\0')
		return (cpt);
	while (s[*j] != c)
	{
		if (s[*j] == '\0')
			return (cpt);
		*j = *j + 1;
		cpt++;
	}
	return (cpt);
}

static char		**ft_freemem(char **t, int r)
{
	while (r != 0)
	{
		free(t[r]);
		r--;
	}
	free(t[r]);
	free(t);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	int		cpt;
	int		wc;
	int		*j;
	int		r;
	char	**t;

	cpt = 0;
	r = 0;
	wc = ft_word_count(s, c);
	j = &cpt;
	t = (char **)malloc(sizeof(char*) * (wc + 1));
	if (t == 0)
		return (0);
	while (r < wc)
	{
		t[r] = (char *)malloc(sizeof(char) * (ft_letter_count(s, c, j) + 1));
		if (t[r] == 0)
			return (ft_freemem(t, r));
		r++;
	}
	cpt = 0;
	r = 0;
	t = ft_remplir(s, c, t, r);
	return (t);
}
