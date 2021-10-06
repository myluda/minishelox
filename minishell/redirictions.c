#include "get_next_line.h"

void    init_var(int *i, int *start, t_list *shell)
{
    shell->g_red_buff = ft_strdup("");
    dup2(shell->g_fd,1);
    *start = *i;
}

int double_redr(t_list *shell, char **ptr, int *start, int i)
{
    *ptr =ft_strjoin(*ptr,ft_substr(shell->buffer,*start,i - *start));
    i = i + 2;
    while(shell->buffer[i] == ' ' && shell->buffer[i])
        i++;
    g_red_start = i;
    i = ft_remove_quotes_file(shell->buffer,i, shell);
    shell->g_fd = open(shell->g_red_buff,O_APPEND | O_RDONLY | O_WRONLY | O_CREAT,0777);
    init_var(&i, start, shell);
    return i;
}

int   single_redr(t_list *shell, char **ptr, int *start, int i)
{
    *ptr = ft_strjoin(*ptr,ft_substr(shell->buffer,*start,i - *start));
    i++;
    while(shell->buffer[i] == ' ' && shell->buffer[i])
        i++;
    g_red_start = i;
    i = ft_remove_quotes_file(shell->buffer,i, shell);
    shell->g_fd = open(shell->g_red_buff,O_TRUNC | O_WRONLY | O_CREAT,0777);
    init_var(&i, start, shell);
    return i;
}

int    check_readrd(t_list *shell, char **ptr, int *start, int i)
{
    *ptr = ft_strjoin(*ptr,ft_substr(shell->buffer,*start,i - *start));
    i = i + 2;
    while(shell->buffer[i] == ' ' && shell->buffer[i])
        i++;
    g_red_start = i;
    i = ft_remove_quotes_file(shell->buffer,i, shell);
    shell->g_fd = open(shell->g_red_buff,O_RDONLY,0777);
    shell->g_red_buff = ft_strdup("");
    *start = i;
    dup2(shell->g_fd,0);
    g_read = 1;
    return i;
}

int     is_quote(char c)
{
    if ((c == '\'' || c == '"'))
        return 1;
    else
        return 0;
}

void    ft_check_redr(t_list *shell)
{
    int i = 0;
    int start = 0;
    int flag=0;
    char *ptr;

    ptr = ft_strdup("");
    shell->g_red_buff = ft_strdup("");
    while(shell->buffer[i])
    {
        if (is_quote(shell->buffer[i]) && flag == 0)
            flag = 1;
        else if(is_quote(shell->buffer[i]) && flag == 1)
            flag = 0;
        else
        {
            while(shell->buffer[i] == '>' && shell->buffer[i] != '\0' && flag == 0)
            {
                if(shell->buffer[i] == '>' && shell->buffer[i+1] == '>')
                    i = double_redr(shell, &ptr, &start, i);
                if(shell->buffer[i] == '>' && shell->buffer[i+1] != '>')
                    i = single_redr(shell, &ptr, &start, i);
            }
            if(shell->buffer[i] == '<')
                i = check_readrd(shell, &ptr, &start, i);
        }
        i++;   
    }
    shell->buffer = ft_strjoin(ptr,ft_substr(shell->buffer,start,i - start));
}