#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

static int		ft_strlen_ok(char *s)
{
	int i;
	
	i = 0;
	while(s[i])
		i++;
	return i;
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	int		k;
	int		i;
	int		j;
	char	*tab;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || start > ft_strlen_ok(s))
	{
		tab = malloc(1 * sizeof(char));
		tab[0] = '\0';
		return (tab);
	}
	i = 0;
	j = len + start;
	k = start;
	tab = (char *)malloc((len + 1) * sizeof(char));
	while (s[start] != '\0' && k++ < j)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}