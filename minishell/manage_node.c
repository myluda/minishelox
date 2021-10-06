#include "get_next_line.h"

void AddNode(char *beforeEq, char *AfterEq, t_list *shell)
{
    node_t *temp =(node_t*) malloc(sizeof(node_t));
    node_t *tempp = shell->head;
    
    if(search_used_node(beforeEq,AfterEq, shell) == 0)
    {
        temp->BeforeEq = ft_strdup(beforeEq);
        if(AfterEq == 0)
            temp->AfterEq = NULL;
        else
            temp->AfterEq = ft_strdup(AfterEq);
        temp->next=NULL;
        while(tempp->next!=NULL)
        {
            tempp=tempp->next;
        }
        tempp->next = temp;
    }
}

void DeleteNode( char *t, t_list *shell)
{
    node_t *tempp = shell->head;
    while(tempp->next !=NULL)
    {
        if(strcmp(tempp->next->BeforeEq,t) == 0)
        {
            node_t *next = tempp->next->next;
            tempp->next = next;
            break ;
        }
        tempp=tempp->next;
    }
}

char * SearchNode(char *t)
{
    char *afterEq;
    node_t *tempp = head;
    while(tempp->next !=NULL)
    {
        if(strcmp(tempp->next->BeforeEq,t) == 0)
        {
           return tempp->next->AfterEq;
        }
        tempp=tempp->next;
    }
    return 0;
}

int ft_strrlen(char **v)
{
    int i=0;
    while(v[i])
    {
        i++;
    }
    return i;
}
