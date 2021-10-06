#include "get_next_line.h"

char *ft_BeforeEq(char *k)
{
    int i=0;
    int j=0;
    char *str;
    str = malloc(sizeof(char)*strlen(k));

    while(k[i])
    {
        if(k[i] == '=')
        {
            str[i] = 0;
            break;
        }
        str[i] = k[i];
        i++;
    }
    return str;
}

void    stock_path(t_list *shell, char *str)
{
    int i;
    char *path;

    i = 0;
    if(strstr(str,"PATH") != NULL)
    {
        path = strstr(str,"PATH");
        shell->path = ft_split(&path[5],':');
        while(shell->path[i])
        {
            shell->path[i] = ft_strjoin(shell->path[i],"/");
            i++;
        }
    }
}

char *ft_AfterEq(char *k, t_list *shell)
{
    int i=0;
    int j = 0;
    char *str;
    str = malloc(sizeof(char)*strlen(k));

    stock_path(shell, k);
    i = 0;
    while(k[i])
    {
        if(k[i] == '=')
        {
            i++;
             while(k[i] == ' ')
                 i++;
            break;
        }
        i++;
    }
    str = k+i;
    return str;

}