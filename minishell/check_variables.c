#include "get_next_line.h"

char    *CheckVariables(char *str, t_list *shell)
{
    char *s;
    node_t *temp = shell->head; 
    
    s = ft_strdup("");
    while(temp!=NULL)
    {
        if(temp->AfterEq != 0)
        {
            if(strcmp(temp->BeforeEq,str) == 0)
            {
                s = ft_strdup(temp->AfterEq);
                return s;
            }
        }         
        temp=temp->next;
    }
    return s;
}

char    *expand_variable(t_list *shell, char *str, int *i, char *res)
{
    int start;
    char *var;
    
    *i = *i + 1;
    start = *i;
    while (str[*i] != ' ' && str[*i] != '\'' && str[*i] != '"')
        *i = *i + 1;
    var = ft_substr(str, start, *i-start);
    var = CheckVariables(var, shell);
    res = ft_strjoin(res, var);
    return res;    
    
}
