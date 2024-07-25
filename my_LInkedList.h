/**
 * @file LinkedList.h
 * @author Marwa Abdelrhman
 * @brief contains declarations of LinkedList
 * @version 1.0
 * @date 2024-07-16
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef MY_LINKEDLIST_H_
#define MY_LINKEDLIST_H_



#include "std_def.h"

#define LINKED_LIST_DEBUG_MODE /*use this macro in case your data type in the list is uint32*/


typedef struct{
    void * NodeData;
    struct Node *NextNode;
}Node_t;

/**
 *@brief add node at Beginning of the list
 *@param list ptr to list
 *@param item value to be added
 *@return void nothing
 */
void Insert_Node_at_Beginning(Node_t **list, void * item);
/**
 *@brief add node after any node of the list
 *@param list ptr to list
 *@param position value of location to add node
 *@param item value to be added
 *@return void nothing
 */
void Insert_Node_After(Node_t *list,uint32_t position, void * item);
/**
 *@brief add node at end of the list
 *@param list ptr to list
 *@param item value to be added
 *@return void nothing
 */
void Insert_Node_at_End(Node_t **list, void * item);
/**
 *@brief delete node at Beginning of the list
 *@param list ptr to list
 *@return void nothing
 */
void Delete_Node_at_Beginning(Node_t **list);
/**
 *@brief delete node at any location of the list
 *@param list ptr to list
 *@param position value of location to add node
 *@return void nothing
 */
void Delete_Node_After(Node_t *list,uint32_t position);
/**
 *@brief delete node at end of the list
 *@param list ptr to list
 *@return void nothing
 */
void Delete_Node_at_End(Node_t **list);
/**
 *@brief display all nodes in the list
 *@param list ptr to list
 *@return void nothing
 */
void List_Display(Node_t *list);
/**
 *@brief get length of the list, how many nodes.
 *@param list ptr to list
 *@return void nothing
 */
uint32_t Get_List_length(Node_t *list);














#endif // MY_LINKEDLIST_H_

