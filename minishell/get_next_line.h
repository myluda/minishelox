/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:46:13 by nainhaja          #+#    #+#             */
/*   Updated: 2019/11/06 23:53:30 by nainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
struct node {
        char* BeforeEq;
        char* AfterEq;
        struct node* next;
    };
typedef struct node node_t;
node_t *head;

typedef struct t_list{
    char    *buffer;
    char    *f_cmd;
    char    *rest;
    char    *g_red_buff;
    node_t *head;
    int     stdio[2];
    int     *g_fd_pipe;
    char    **path;
    int     g_fd;
    char **tab;
    int     g_n;
}           t_list;

int g_red_start;
int g_read;

int	ft_strcmp(const char *str, const char *to_find);
char	**ft_split(char const *s, char c);
int		get_next_line(int fds, char **line);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, unsigned int len);
char	*ft_strchr(char *str, int c);
size_t	ft_strlen(char *str);
int key_press(int key, void *ptr);
char		*ft_strjoin(char *s1, char *s2);
char *ft_checkDollar(char *str,char **env);
char *ft_RmSpace(char *s,int c);
char *ft_AddSpace(char *s,int i);
char *ft_BeforeEq(char *k);
char *ft_AfterEq(char *k, t_list *shell);
char			**ft_split(char const *s, char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char *ft_BeforeEq_two(char *k);
char *ft_AfterEq_two(char *k);
char *ft_remove_quotes_two(char *buf);
int    ft_checkQuotes(int *i,int *cpt,int *cpt2,char *s);
void    ft_storeData(char *s,char **str,int start,int i,char **env);
char *ft_remove_spaces(int *start, int *i);
void ft_get_between_spaces(char *haha,int *i,int *start,char **ptr);
void ft_get_between_slash(char *haha,int *i,int *start,char **ptr);
void ft_get_string_quotes(char *haha,int *i,int *start,char **ptr);
char *ft_remove_spacess(char *haha, int start, int i);
char *ft_remove_slash(char *haha);
char *ft_remove_quotes(char *buf, char **env);
void ft_sort(t_list *shell);
char *ft_checkCases(char *s,char **env);
char    *ft_remove_n(char *str);
void copy(char **t,int n, t_list *shell);
int get_listcount();
void exec_echo(int *stdio, int split_cpt, int start, char **env, int i);
void DeleteNode( char *t, t_list *shell);
int     search_lastRed(char *str);
int  search_used_node(char *beforeEq, char *AfterEq, t_list *shell);
void AddNode(char *beforeEq, char *AfterEq, t_list *shell);
char * SearchNode(char *t);
int ft_strrlen(char **v);
void ft_putstr(char *str);
void ft_check_split();
void exec_export(int split_cpt);
void exec_unset(int split_cpt);
void exec_cmds(int *stdio, int split_cpt, char **env);
void check_conditions(int split_cpt, int *stdio, int start, char **env, int i, char *buff);
void    split_cmds(char **env, t_list *shell);
void    ft_check_redr(t_list *shell);
void ft_free(int split_cpt);
void    ft_init(int *split_cpt, int *i, int *awdi);
void ft_stock_split(char *str, int *i,int cpt);
int     skip_spaces(int i, char *str);
int     ft_remove_quotes_file(char *str,int i, t_list *shell);
void    get_rest_command(t_list *shell);
int    skip_quotes(int i, char c, char *str);   
char    *remove_spaces(char *str);
int     skip_spaces(int i, char *str);
int     skip_onlyspaces(int i, char *str, char **res);
int get_only_char(char *str, int i, char **res);
char    *remove_quotes(char *str, t_list *shell);
char    *inside_dquotes(char *str, int *i, t_list *shell);
char    *inside_squotes(char *str, int *i);
int get_last_quote(int i, char c, char *str);
void    print_export(t_list *shell);
void    print_env(t_list *shell);
char    *expand_variable(t_list *shell, char *str, int *i, char *res);
void    export(t_list *shell);
void exec_cmd(char **env, t_list *shell);
void    get_first_command(t_list *shell);
void    get_first_command_pipe(t_list *shell, int c);
void exec_cmd_pipe(char **env, t_list *shell, int i);
void    get_rest_command_pipe(t_list *shell , int c);
void    conditions_pipe(t_list *shell, char **env,int i);
void    ft_initiate_pipe(t_list *shell, int pipes, char **env);
void    ft_check_redr_pipe(t_list *shell, int c);




#endif