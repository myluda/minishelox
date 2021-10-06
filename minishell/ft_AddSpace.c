#include "get_next_line.h"

char *ft_AddSpace(char *s,int i)
{
	if (i != 0)
		return ft_strjoin(s," ");
	else
		return s;
	
}