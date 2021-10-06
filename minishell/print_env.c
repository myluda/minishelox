#include "get_next_line.h"

void copy(char **t,int n, t_list *shell)                        
{
    node_t *temp = malloc(sizeof(node_t));

    temp->BeforeEq= ft_BeforeEq(t[0]);
    temp->AfterEq = ft_AfterEq(t[0], shell);
    temp->next=NULL;
    shell->head = temp;
    int i=1;
    while(i<n)
    {
        node_t *temp2= malloc(sizeof(node_t));
        temp->next= temp2;
        temp2->BeforeEq= ft_BeforeEq(t[i]);
        temp2->AfterEq = ft_AfterEq(t[i], shell);
        temp2->next = NULL;
        temp=temp2;
        i++;
     }  
}   

void   print_env(t_list *shell)
{
    node_t *temp;
    
    temp = shell->head;
    while(temp!=NULL)
    {
        if(temp->AfterEq != 0)
        {  
            printf("%s=",temp->BeforeEq);
            printf("%s \n",temp->AfterEq);
        }
        temp=temp->next;
    }
}

