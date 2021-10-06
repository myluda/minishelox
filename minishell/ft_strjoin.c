#include "get_next_line.h"

static char	*ft_remplir(char *s1, char *s2, char *ret)
{
	int i;
	int j;
	int k;

	k = 0;
	j = 0;
	i = 0;
	while (s1[i])
	{
		ret[k] = s1[i];
		k++;
		i++;
	}
	while (s2[j])
	{
		ret[k] = s2[j];
		j++;
		k++;
	}
	ret[k] = '\0';
	return (ret);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char *ret;

	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ret)
	{
		ret = ft_remplir(s1, s2, ret);
		return (ret);
	}
	else
		return (0);
}