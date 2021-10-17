#include "get_next_line.h"

char    *ft_join(t_list *shell)
{
    char *test;
        
    test = ft_strjoin(shell->f_cmd, " ");
    test = ft_strjoin(test, shell->rest);
    return test;
}

void    execute(t_list *shell, char **argvv)
{
    int i;
    char    *envv[] = {NULL};

    i = 0;
    while(shell->path[i])
    {
        execve(ft_strjoin(shell->path[i],shell->f_cmd), argvv, envv);
        //printf("command line = |%s|\n",shell->f_cmd);
        i++;
    }
    exit(0);
}

void exec_cmd(char **env, t_list *shell)
{
    int     i;
    int     id;
    char    **argvv;

    id = fork();
    i = 0;
    if(id == 0)
    {
        close(shell->g_fd);
        dup2(shell->stdio[1], 1);
        argvv = ft_split(ft_join(shell),' ');
        execute(shell, argvv);
    }
    wait(NULL);
}
void exec_cmd_pipe(char **env, t_list *shell, int c)
{
    int     i;
    int     id;
    char    **argvv;

    i = 0;
        //close(shell->g_fd);
        //dup2(shell->stdio[1], 1);
        argvv = ft_split(ft_join(shell),' ');
        execute(shell, argvv);
    wait(NULL);
}
