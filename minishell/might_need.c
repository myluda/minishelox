#include "get_next_line.h"

// void might_need()
// {
//     int awdi,split_cpt;
//     if(buffer[ft_strlen(buffer) - 1] != ';')
//         buffer = ft_strjoin(buffer,";");
//     ft_check_split();
//     split = malloc(sizeof(char*)*(g_red));
//     while (g_red > split_cpt)
//     {
//         ft_stock_split(buffer,&awdi,split_cpt);
//         split_cpt++;
//     }
// }

// void might_need2()
// {
//     int split_cpt;
//     int *stdio;
//     char *buff;
//     int start;
//     int i;
//     char **env;
//     while(split_cpt < g_red)
//     {
//         g_read = 0;
//         buff = ft_remove_quotes(ft_remove_spaces(ft_check_redr(split[split_cpt],split_cpt), &start, &i),env);
//         check_conditions(split_cpt, stdio, start, env, i, buff);
//         i = 0;
//         start = 0;
//         split_cpt++;
//     }
// }
// void ft_check_split()
// {
//     int i = 0;

//     while(buffer[i])
//     {
//         if(buffer[i] == '\'')
//         {
//             i++;
//             while(buffer[i] != '\'' && buffer[i] != '\0')
//                 i++;
//             if(buffer[i] != '\0')
//                 i++;
//             else
//             {
//                 g_red++;
//                 break;
//             }
                
//         }

//         if(buffer[i] == '"')
//         {
//             i++;
//             while(buffer[i] != '"' && buffer[i] != '\0')
//                 i++;
//             if(buffer[i] != '\0')
//                 i++;
//             else
//             {
//                 g_red++;
//                 break;
//             }
//         }
//         if(buffer[i] == ';')
//         {
//             g_red++;
//         }
//         i++;
//     }
// }
// void ft_stock_split(char *str, int *i,int cpt)
// {
//     while(str[*i])
//     {
//         if(str[*i] == '\'' && (stock_squotes(str, i, cpt) == 0))
//             break;
//         if(str[*i] == '"' && (stock_dquotes(str, i, cpt) == 0))
//             break;
//         if(str[*i] == ';' &&  (stock_last(str, i, cpt) == 0))
//             break;
//         *i = *i +1;
//     }
// }