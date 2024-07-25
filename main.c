#include <stdio.h>
#include <stdlib.h>
#include"my_LInkedList.h"

Node_t *ListHead=NULL;
uint32_t item=11,len=0;
int main()
{
    Insert_Node_at_Beginning(&ListHead,item);//r
    item=2;
    Insert_Node_at_Beginning(&ListHead,item);

    Insert_Node_at_Beginning(&ListHead,5);

    Insert_Node_After(ListHead,1,12);//r

    Insert_Node_After(ListHead,2,195);

    Insert_Node_After(ListHead,3,12);

    Insert_Node_After(ListHead,4,12);
    Insert_Node_at_End(&ListHead,15);

    Insert_Node_at_End(&ListHead,19);
    Delete_Node_After(ListHead,1);//r
    Delete_Node_at_Beginning(&ListHead);//r
    Delete_Node_at_End(&ListHead);//r
    List_Display(ListHead);//r
    len=Get_List_length(ListHead);//r
    printf("list length is: %i. \n ",len);


    return 0;
}
