#include<stdio.h>
#include <unistd.h>
#include<string.h>
#include<stdlib.h>
#include "get_next_line.h"
#include <sys/wait.h>


int main(int argc,char **argv,char **env)
{
    char *buff;
    char *ptr;
    t_list *shell;
    
    shell = (t_list*)malloc(sizeof(t_list));
    shell->g_fd = 1;
    shell->head = malloc(sizeof(node_t));
    copy(env,ft_strrlen(env), shell);
    shell->stdio[0] = dup(0);
    shell->stdio[1] = dup(1);
    while(1)
    {
        dup2(shell->stdio[0], 0);
        dup2(shell->stdio[1], 1);
        write(1,"$> ",3);
        get_next_line(0,&shell->buffer);
        split_cmds(env, shell);
        // ft_init(&split_cpt, &i, &awdi);
    }
   
}


