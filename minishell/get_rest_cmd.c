#include "get_next_line.h"

int get_only_char(char *str, int i, char **res)
{
    int start;

    start = i;
    while (str[i] != ' ' && str[i]  != '\'' && str[i]  != '"' && str[i] != '\0')
        i++;
    *res = ft_strjoin(*res, ft_substr(str, start, i - start));
    return i;
}

int     skip_onlyspaces(int i, char *str, char **res)
{
    int flag;

    flag = 0;
    while (str[i] == ' ' && str[i]  != '\'' && str[i]  != '"' && str[i] != '\0')
    {
        i++;
        flag = 1;
    }
    if (flag == 1)
        *res = ft_strjoin(*res, ft_strdup(" "));
    return i;
}

int    skip_quotes(int i, char c, char *str)
{
    while (str[i] != c && str[i] != '\0')
        i++;
    return i+1;
}

int     skip_spaces(int i, char *str)
{
    while((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
    {
        if(str[i]  == '\'' || str[i]  == '"')
            i = skip_quotes(i, str[i],str);
        else
            i++;
    }
    return i;
}
char    *remove_spaces(char *str)
{
    int i;
    int start;
    char    *res;
    int     flag;

    res= ft_strdup("");
    i = 0;
    flag=0;
    start = 0;
    while (str[i] != '\0')
    {
        while(str[i]  == '\'' || str[i]  == '"')
        {
            start = i;
            i = skip_quotes(i + 1, str[i], str);
            res = ft_strjoin(res, ft_substr(str, start, i - start));
        }
        i = skip_onlyspaces(i, str, &res);
        i = get_only_char(str, i, &res);
    }
    return res;
    
}

void    get_rest_command(t_list *shell)
{
    int i;
    int len;

    i = skip_spaces(0, shell->buffer);
    len = ft_strlen(shell->buffer);
    shell->rest = ft_substr(shell->buffer, i, len - i);
    shell->rest = remove_spaces(shell->rest);
    shell->rest = remove_quotes(shell->rest, shell);
}

void    get_rest_command_pipe(t_list *shell , int c)
{
    int i;
    int len;
    printf("segf = %s\n",shell->tab[c]);
    i = skip_spaces(0, shell->tab[c]);
    len = ft_strlen(shell->tab[c]);
    shell->rest = ft_substr(shell->tab[c], i, len - i);
    shell->rest = remove_spaces(shell->rest);
    shell->rest = remove_quotes(shell->rest, shell);
    dprintf(2,"rest == |%s|\n",shell->rest);
}