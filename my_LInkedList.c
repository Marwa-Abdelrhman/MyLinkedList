/**
 * @file LinkedList.c
 * @author Marwa Abdelrhman
 * @brief contains definitions of LinkedList
 * @version 1.0
 * @date 2024-07-16
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "my_LInkedList.h"
#include <stdlib.h>
/**
 *@brief add node at Beginning of the list
 *@param list ptr to list
 *@param item value to be added
 *@return void nothing
 */
void Insert_Node_at_Beginning(Node_t **list, void *item)
{
    Node_t *temp_node = NULL;
    temp_node = (Node_t *)malloc(sizeof(Node_t));
    if (temp_node != NULL)
    {
        if (item == NULL)
        {
    #ifdef LINKED_LIST_DEBUG_MODE
            printf("ERROR: NULL Ptr @Insert_Node_at_Beginning.\n");
    #endif
        }
        else
        {
            temp_node->NodeData = item;
            if (*list == NULL) /*list is empty so temp node is the first node at list*/
            {

                temp_node->NextNode = NULL;
                *list = temp_node;
            }
            else /*list not empty*/
            {

                /*conect node to its right*/
                temp_node->NextNode = *list;

                /*conect node to its left*/
                *list = temp_node;
            }

        }

    
    }
    else{
        /* Nothing */
    }
    
}
/**
 *@brief add node after any node of the list
 *@param list ptr to list
 *@param position value of location to add node
 *@param item value to be added
 *@return void nothing
 */
void Insert_Node_After(Node_t *list, uint32_t position, void *item)
{
    Node_t *temp_node = NULL;
    Node_t *node_after = NULL;
    uint32_t node_counter = 1, list_len = 0;

    if ((list == NULL) || (item == NULL)) /*to check that list is already exists*/
    {
#ifdef LINKED_LIST_DEBUG_MODE
        printf("ERROR: NULL Ptr @Insert_Node_After.\n");
#endif

    }
    else
    {
        list_len=Get_List_length(list);

       if (position > list_len)
        {
#ifdef LINKED_LIST_DEBUG_MODE
            printf("ERROR: position is greater than list length@Insert_Node_After.\n");
#endif
        }
        else
        {
            node_after = list;
            temp_node = (Node_t *)malloc(sizeof(Node_t));
            if (temp_node != NULL)
            {

                temp_node->NodeData = item;
                while (node_counter < position)
                {
                    node_counter++;
                    node_after = node_after->NextNode;

                }
                /*conect node to its right*/
                temp_node->NextNode = node_after->NextNode;

                /*conect node to its left*/
                node_after->NextNode = temp_node;
            }
        }
    }
    
}
/**
 *@brief add node at end of the list
 *@param list ptr to list
 *@param item value to be added
 *@return void nothing
 */
void Insert_Node_at_End(Node_t **list, void *item)
{
    Node_t *temp_node = NULL;
    Node_t *node_end = NULL;

    if (item == NULL)
    {
#ifdef LINKED_LIST_DEBUG_MODE
        printf("ERROR: NULL Ptr @Insert_Node_at_End.\n");
#endif
    }
    else
    {
        temp_node = (Node_t *)malloc(sizeof(Node_t));
        if (temp_node != NULL)
        {

            temp_node->NodeData = item;
            if (*list == NULL) /*list is empty so temp node is the last node*/
            {
                *list = temp_node;
            }
            else /*list is not empty*/
            {
                node_end = *list;

                while (node_end->NextNode!= NULL)
                {

                    node_end = node_end->NextNode;
                }
                /*conect node to its right*/
                temp_node->NextNode = NULL;

                /*conect node to its left*/
                node_end->NextNode = temp_node;
            }
        }
    }
}
/**
 *@brief delete node at Beginning of the list
 *@param list ptr to list
 *@return void nothing
 */
void Delete_Node_at_Beginning(Node_t **list)
{
    Node_t *temp_node = NULL;

    if (list == NULL) /*list is empty or not exists  */
    {
#ifdef LINKED_LIST_DEBUG_MODE
        printf("ERROR: NULL Ptr @Delete_Node_at_Beginning.\n");
#endif
    }
    else
    {
        temp_node = *list;
        *list = temp_node->NextNode;
        /*make temp node apart from the list then delete it*/
        temp_node->NextNode = NULL;
        free(temp_node);
    }
}
/**
 *@brief delete node at any location of the list
 *@param list ptr to list
 *@param position value of location to add node
 *@return void nothing
 */
void Delete_Node_After(Node_t *list, uint32_t position)
{
    Node_t *temp_node = NULL;
    Node_t *node_after = list;
    uint32_t node_counter = 1, list_len = Get_List_length(list);

    if (list == NULL) /*to check that list is already exists*/
    {
#ifdef LINKED_LIST_DEBUG_MODE
        printf("ERROR: NULL Ptr @Delete_Node_After.\n");
#endif
        if (position > list_len)
        {
#ifdef LINKED_LIST_DEBUG_MODE
            printf("ERROR: position is greater than list length@Delete_Node_After.\n");
#endif
        }
    }
    else
    {
        while (node_counter < position)
        {
            node_after = node_after->NextNode;
            node_counter++;
        }
        // list=node_after;
        temp_node = node_after->NextNode;
        node_after->NextNode = temp_node->NextNode;
        free(temp_node);
    }
}
/**
 *@brief delete node at end of the list
 *@param list ptr to list
 *@return void nothing
 */
void Delete_Node_at_End(Node_t **list)
{
    Node_t *temp_node = *list;
    Node_t *node_end = NULL;

    if (list == NULL)
    {
#ifdef LINKED_LIST_DEBUG_MODE
        printf("Linked List Empty, nothing to delete.\n");
#endif
    }
    else
    {
        // if Linked List has only 1 node
        if (temp_node== NULL)
            {
                *list=NULL;

            }
        else
            {

                while (temp_node->NextNode != NULL)
                {
                    
                    node_end=temp_node;

                    temp_node = temp_node->NextNode;
                }

                node_end->NextNode =NULL;

            }
            
        free(temp_node);

    }
                


        
    
}
/**
 *@brief display all nodes in the list
 *@param list ptr to list
 *@return void nothing
 */
void List_Display(Node_t *list)
{
    Node_t * temp_node=list;
    if (temp_node == NULL) /*to check that list is already exists*/
    {
#ifdef LINKED_LIST_DEBUG_MODE
        printf("ERROR: NULL Ptr @List_Display, list is empty.\n");
#endif
    }
    else
    {
        printf("list display: ");

        while (temp_node!= NULL)//if temp_node->NodeData it will ignore the first node
        {
            printf("%i    \t", temp_node->NodeData);
            temp_node=temp_node->NextNode;
        }
        printf("\n");
    }
}

/**
 *@brief get length of the list, how many nodes.
 *@param list ptr to list
 *@return void nothing
 */
uint32_t Get_List_length(Node_t *list)
{
    uint32_t count = 0;
    if (list == NULL)
    {
#ifdef LINKED_LIST_DEBUG_MODE
        printf("NULL Ptr @Get_List_length.\n");
#endif
    }
    else
    {
        while (list != NULL)
        {
            count++;
            list=list->NextNode;
        }
    }

    return count;
}

// void Insert_Node_at_End(Node_t **list, void *item)
// {
//     Node_t *temp_node = NULL;
//     Node_t *node_end = list;
//     uint32_t node_counter = 1, list_len = Get_List_length(list);

//     if ((list == NULL) || (item == NULL)) /*to check that list is already exists*/
//     {
// #ifdef LINKED_LIST_DEBUG_MODE
//         printf("NULL Ptr @Insert_Node_at_End.\n");
// #endif
//     }
//     else
//     {
//         temp_node = (Node_t *)malloc(sizeof(Node_t));
//         if (temp_node != NULL)
//         {

//             temp_node->NodeData = item;
//             while (node_counter < list_len)
//             {
//                 node_end = node_end->NextNode;
//                 node_counter++;
//             }
//             /*conect node to its right*/
//             temp_node->NextNode = NULL;

//             /*conect node to its left*/
//             node_end->NextNode = temp_node;
//         }
//     }
// }
