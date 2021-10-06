#include "get_next_line.h"

int get_listcount()
{
    node_t *temp = head;
    int i = 0;
    while(temp!=NULL)
    {
        temp=temp->next;
        i++;
    }
    return i;
}

int     search_lastRed(char *str)
{
    int i=0;
    int cpt=0;
    while(str[i])
    {
        if(str[i] == '>')
            cpt = i;
        i++;
    }
    return cpt;
}

int  search_used_node(char *beforeEq, char *AfterEq, t_list *shell)
{
    char *afterEq;
    node_t *tempp = shell->head;
    while(tempp->next !=NULL)
    {
        if(strcmp(tempp->next->BeforeEq,beforeEq) == 0 && AfterEq != 0)
        {
           tempp->next->AfterEq = AfterEq;
           return 1;
        }
        else if(strcmp(tempp->next->BeforeEq,beforeEq) == 0 && AfterEq == 0)
            return 1;
        tempp=tempp->next;
    }
    return 0;
}