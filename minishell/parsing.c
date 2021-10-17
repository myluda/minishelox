#include "get_next_line.h"

char    *inside_squotes(char *str, int *i)
{
    int start;
    char    c;
    char    *res;

    start = *i + 1;
    c = str[*i];
    *i = *i + 1;
    while (str[*i] != '\0')
    {
        if (str[*i] == c)
        {
            res = ft_substr(str, start, *i - start);
            *i = *i + 1;
            return res;
        } 
        *i = *i + 1;
    }
    return 0;
}

char    *inside_dquotes(char *str, int *i, t_list *shell)
{
    int start;
    char    c;
    char    *res;

    c = str[*i];
    *i = *i + 1;
    start = *i;
    res = ft_strdup("");
    while (str[*i] != '\0')
    {
        if (str[*i] == c)
        {
            res =ft_strjoin(res, ft_substr(str, start, *i - start));
            *i = *i + 1;
            return res;
        }
        if(str[*i] == '$')
        {
            res = ft_strjoin(res, ft_substr(str, start, *i - start));
            res = expand_variable(shell, str, i, res);
            start = *i;
        }
        else
            *i = *i + 1;
    }
    return 0;
}

int     contunie_parsing(int i, t_list *shell, char *str, char **res)
{
    int start;

    start = i;
    while(str[i] != '\'' && str[i] != '"' && str[i] != '\0' && str[i] != '$')
        i++;
    if (str[i] == '$')
    {
        *res = ft_strjoin(*res, ft_substr(str, start, i - start));
        *res = expand_variable(shell, str, &i, *res);
        start = i;
    }
    else
        *res = ft_strjoin(*res, ft_substr(str, start, i - start));
    return i;    
}

char    *remove_quotes(char *str, t_list *shell)
{
    int     start;
    int     i;
    char    *res;

    start = 0;
    i = 0;
    res = ft_strdup("");
    while (str[i])
    {
        if(str[i] == '\'')
            res = ft_strjoin(res, inside_squotes(str, &i));
        else if(str[i] == '"')
            res = ft_strjoin(res, inside_dquotes(str, &i, shell));
        i = contunie_parsing(i, shell, str, &res);
    }
    return res;
}

void    get_first_command(t_list *shell)
{
    int i;
    int start;
    int len;

    i = skip_spaces(0, shell->buffer);
    len = ft_strlen(shell->buffer);
    start = i;
    while(shell->buffer[i] != ' ' && shell->buffer[i]  != '\t' && shell->buffer[i]  != '\0')
    {
        while(shell->buffer[i]  == '\'' || shell->buffer[i]  == '"')
            i = skip_quotes(i + 1, shell->buffer[i],shell->buffer);
        if (shell->buffer[i] != ' ')
            i++;
    }
    shell->f_cmd = ft_substr(shell->buffer ,start,i - start);
    shell->f_cmd = remove_quotes(shell->f_cmd, shell);
    shell->buffer = ft_substr(shell->buffer, i, len - i);
}

void    get_first_command_pipe(t_list *shell, int c)
{
    int i;
    int start;
    int len;

    i = skip_spaces(0, shell->tab[c]);
    len = ft_strlen(shell->tab[c]);
    start = i;
    while(shell->tab[c][i] != ' ' && shell->tab[c][i]  != '\t' && shell->tab[c][i]  != '\0')
    {
        while(shell->tab[c][i]  == '\'' || shell->tab[c][i]  == '"')
            i = skip_quotes(i + 1, shell->tab[c][i],shell->tab[c]);
        if (shell->tab[c][i] != ' ')
            i++;
    }
    shell->f_cmd = ft_substr(shell->tab[c] ,start,i - start);
    shell->f_cmd = remove_quotes(shell->f_cmd, shell);
    shell->tab[c] = ft_substr(shell->tab[c], i, len - i);
    dprintf(2,"f_cmd == |%s|\n",shell->f_cmd);


}