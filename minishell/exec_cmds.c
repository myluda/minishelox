#include "get_next_line.h"

// void check_conditions(int split_cpt, int *stdio, int start, char **env, int i, char *buff)
// {
//     int j;
//     int startt;

//     j = i;
//     startt = start;
//     if(strcmp(buff,"echo") == 0)
//     {
//         if(strcmp(ft_remove_quotes(ft_remove_spaces( &startt, &j),env),"-n") == 0)
//             ft_putstr(ft_checkCases(ft_remove_n(split[split_cpt]+(j)),env));
//         else
//             exec_echo(stdio, split_cpt, start, env, i);
//     } 
//     else if(strcmp(buff,"env") == 0)
//     {
//         //printlist(0);
//     }
//     else if(strcmp(buff,"export") == 0)
//     {
//         exec_export(split_cpt);
//     }
//     else if(strcmp(buff,"unset") == 0)
//     {
//         exec_unset(split_cpt);
//     }
//     else
//     {  
//         exec_cmds(stdio, split_cpt, env);
//     }
// }

// void ft_free(int split_cpt)
// {
//     split_cpt = 0;
//     while(split_cpt < g_red)
//     {
//         free(split[split_cpt]);
//         split_cpt++;
//     }
// }

// void    ft_init(int *split_cpt, int *i, int *awdi)
// {
//     *split_cpt = 0;
//     g_red = 0;
//     *i = 0;
//     *awdi = 0;
//     g_start = 0;
// }
