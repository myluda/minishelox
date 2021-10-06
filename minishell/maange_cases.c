#include "get_next_line.h"

void ft_sort(t_list *shell)
{
    node_t *temp = shell->head;
    int sort_indice=1;
    char *tmp_be;
    char *tmp_ae;
    while (sort_indice)
    {
        sort_indice = 0;
        while (temp->next != NULL)
        {
            if(strcmp(temp->BeforeEq,temp->next->BeforeEq) > 0)
            {
                sort_indice = 1;
                tmp_be = temp->BeforeEq;
                temp->BeforeEq = temp->next->BeforeEq;
                temp->next->BeforeEq = tmp_be;

                tmp_ae = temp->AfterEq;
                temp->AfterEq = temp->next->AfterEq;
                temp->next->AfterEq = tmp_ae;
            }
            temp = temp->next;
        }
        temp = shell->head;
    }
}

char    *ft_remove_n(char *str)
{
    int i;
    char *ptr;
    int start;
    int ft_break;

    i = 0;
    start = 0;
    ft_break = 0;
    ptr = ft_strdup("");
    while(str[i])
    {
        while(str[i] == '-' && str[i + 1] == 'n')
        {
            ptr = ft_strjoin(ptr, ft_substr(str, start, i - start));
            i++;
            while (str[i] == 'n' && str[i])
                i++;
            while (str[i] == ' ' && str[i])
                i++;
            start = i;
            ft_break = 1;
        }
        if(ft_break == 1)
        {
            ptr = ft_strjoin(ptr, ft_substr(str, start, ft_strlen(str) - start));
            break;
        }
        i++;
    }
    if(start != i)
        ptr = ft_strjoin(ptr, ft_substr(str, start, i - start));
    return ptr;
}

