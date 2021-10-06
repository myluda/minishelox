#include "get_next_line.h"

char *ft_RmSpace(char *s,int c)
{
    char **k = ft_split((const char*)s,' ');
    char *ss = "";
	int j = 0;
	int i=0;
    int p=2;
    while(k[j])
    {
        if(!k[j+1] && c == 0)
            p = 0;
        ss = ft_strjoin(ss,ft_AddSpace(k[j],p));
        j++;
    }
    return ss;
}