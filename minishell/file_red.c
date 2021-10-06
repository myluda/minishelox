#include "get_next_line.h"

int    remove_sqfile(char *str,int i, t_list *shell)
{
    int start_sq;

    shell->g_red_buff = ft_strjoin(shell->g_red_buff,ft_substr(str,g_red_start,i - g_red_start));
    start_sq = i + 1;
    while (str[i] != '\'' && str[i] != '\0')
        i++;
    shell->g_red_buff = ft_strjoin(shell->g_red_buff,ft_substr(str,start_sq,i - start_sq));
    i++;
    g_red_start = i;
    return i;
}

int    remove_dqfile(char *str, int i, t_list *shell)
{
    int start_dq;

    shell->g_red_buff = ft_strjoin(shell->g_red_buff,ft_substr(str,g_red_start,i - g_red_start));
    start_dq = i + 1;          
    while (str[i] != '"' && str[i] != '\0')
        i = i + 1;
    shell->g_red_buff = ft_strjoin(shell->g_red_buff,ft_substr(str,start_dq,i - start_dq));
    i++;
    g_red_start = i;
    return i;
}

int ft_remove_quotes_file(char *str,int i, t_list *shell)
{
    while(str[i] != ' ' && str[i] != '>' && str[i] != '<' && str[i])
    {
        if(str[i] == '\'')
            i = remove_sqfile(str, i, shell);
        else if(str[i] == '"')
            i = remove_dqfile(str, i, shell);
        else if(str[i] != '\0')    
            i++;         
    }
    if (g_red_start != ft_strlen(str))
        shell->g_red_buff  = ft_strjoin(shell->g_red_buff,ft_substr(str,g_red_start,i - g_red_start));  
    return i;
}