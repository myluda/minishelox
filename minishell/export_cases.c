#include "get_next_line.h"


char    *get_before_eq(char *str, int *i)
{
    int start;
    char    *before_eq;
    
    start = 0;
    *i = 0;
    while(str[*i] != '=' && str[*i] != '\0')
        *i = *i + 1;
    before_eq = ft_substr(str, start, *i - start);
    return before_eq;
}

char    *get_after_eq(char *str, int *i)
{
    int start;
    char *after_eq;
    
    if (str[*i] == '=')
    {
        start = *i + 1;
        while(str[*i] != '\0')
            *i = *i + 1;
        after_eq = ft_substr(str, start, *i - start);
        return after_eq;
    }
    else if(str[*i] == '\0')
        return 0;
    else
        return ft_strdup("");
}

void    get_variables(char *str, t_list *shell)
{
    int i;
    char    *before_eq;
    char    *after_eq;

    before_eq = get_before_eq(str, &i);
    after_eq = get_after_eq(str, &i);
    AddNode(before_eq, after_eq, shell);
    
}

void    check_line(t_list *shell)
{
    char **line;
    int i;

    i = 0;
    line = ft_split(shell->rest, ' ');
    while(line[i])
    {
        if (line[i][0] == '=')
            printf("minishell: export: `%s': not a valid identifier\n",line[i]);
        else
            get_variables(line[i], shell);
        i++;
    }
}

void    print_export(t_list *shell)
{
    node_t *temp;
    
    temp = shell->head;
    ft_sort(shell);
    int i = 0;
    
    while(temp!=NULL)
    {
        printf("declare -x %s",temp->BeforeEq);
        if(temp->AfterEq == 0)
            printf("\n");
        else
            printf("=\"%s\" \n",temp->AfterEq);
        temp=temp->next;
        i++;
    }
}

void    export(t_list *shell)
{
    if (!(ft_strcmp(shell->rest, "")))
        print_export(shell);
    else
        check_line(shell);
}

