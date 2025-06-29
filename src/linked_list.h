#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
	int data;
	struct Node *prev , *next;
} Node;


//============== Memory Management ====================

// Create a new node, returns NULL in failure
Node *create_node(int data);

// Deallocate memory for the node, returns if node is NULL
void destroy_node(Node *node);

// Deallocate entire linked list
void destroy_linked_list(Node *head);

//============== Insertions / Deletions ===============

// Adds a node at the end of the linked list
// returns head in sucess, NULL if failure
Node *ll_push_back(Node *head ,const int data);

// Adds a node at the begining of the linked list
// returns head if sucess, NULL if failure
Node *ll_push_front(Node *head ,const int data);

// Adds a node at the end of the linked list
// returns head if sucess, NULL if failure
Node *ll_remove_back(Node *head);

// Adds a node at the begining of the linked list
// returns head if sucess, NULL if failure
Node *ll_remove_front(Node *head);

// inserts data exactly at the requested position
// position starts from 0 and ends at the position next to the last element (NULL's position)
// returns head in case of success, NULL if failure
Node *ll_insert(Node *head , const int data , const unsigned int position);

// inserts data exactly at the requested position
// position starts from 0 and ends at the position next to the last element (NULL's position)
// returns head in case of success, NULL if failure
Node *ll_remove(Node *head , const unsigned int position);
// ============== Display ==================================

void ll_foreach(Node *head , void (*function)(int data));

void ll_display(Node *head);

//================ Tests ===================================

void ll_test_push_back();
void ll_test_push_front();
void ll_test_remove_front();
void ll_test_remove_back();
void ll_test_insert();
void ll_test_remove();

void ll_test_all();



#endif // LINKED_LIST_H