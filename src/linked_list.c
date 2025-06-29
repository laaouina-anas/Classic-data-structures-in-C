#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

Node *create_node(int data)
{
	Node *node = malloc(sizeof(Node));
	if(node == NULL) return NULL; 

	node->data = data; 
	node->prev = node->next = NULL;
	return node;
}


void destroy_node(Node *node)
{
	if(node == NULL) return;
	free(node);
}

void destroy_linked_list(Node *head)
{
	Node *temp = NULL;
	Node *curr = head;
	while(curr != NULL)
	{
		temp = curr->next;
		destroy_node(curr);
		curr = temp;
	}
}

Node *ll_push_back(Node *head ,const int data)
{
	Node *node = create_node(data);
	if(node == NULL) return NULL;

	// if the list is empty, return the head
	if(head == NULL)
	{
		return node;
	}

	// traverse the list to find the last node
	Node *last = head;
	while(last->next != NULL)
	{
		last = last->next;
	}

	// push the node at the end
	last->next = node;
	node->prev = last;

	return head; // finally return head
}


Node *ll_push_front(Node *head ,const int data)
{
	Node *node = create_node(data);
	if(node == NULL) return NULL;

	// if list is empty, return the head
	if(head == NULL) 
	{
		return node;
	}

	// otherwise, add it
	node->next = head;
	head->prev = node;

	return node;
}

Node *ll_remove_back(Node *head)
{
	if(head == NULL) return NULL;

	// if list contains one node
	if(head->next == NULL)
	{
		destroy_node(head);
		return NULL;
	}

	// if list contains more than one node
	// traverse the list to reach the previous than last node

	Node *curr = head;
	while(curr->next->next != NULL)
	{
		curr = curr->next;
	}

	destroy_node(curr->next);

	curr->next = NULL;
	return head;
}

Node *ll_remove_front(Node *head)
{
	if(head == NULL) return NULL;

	if(head->next == NULL)
	{
		destroy_node(head);
		return NULL;
	}

	Node *temp = head->next;
	destroy_node(head);
	temp->prev = NULL;
	
	return temp; 
}


Node *ll_insert(Node *head , const int data , const unsigned int position)
{
	Node *node = create_node(data);
	if(head == NULL && position == 0)
	{
		return node;
	}

	// reach the node before the position
	int i = 0;
	Node *curr = head;
	while(curr != NULL && i < position - 1)
	{
		i++; curr = curr->next;
	}

	// if the position is too big or curr = NULL
	if(curr == NULL)
	{
		destroy_node(node);
		return head; // gracefully return head
	}

	// handle the insertion at the end
	if(curr->next == NULL)
	{
		curr->next = node;
		node->prev = curr;
		return head;
	}

	// insertion between two nodes
	node->next = curr->next;
	node->prev = curr;
	curr->next->prev = node;
	curr->next = node;

	return head;
}


Node *ll_remove(Node *head , const unsigned int position)
{
	if(head == NULL) return NULL;
	if(head->next == NULL && position == 0)
	{
		destroy_node(head);
		return NULL;
	}

	// reach the node before deletion
	int i = 0;
	Node *curr = head;
	while(curr != NULL && i < position - 1)
	{
		i++; curr = curr->next;
	}

	if(curr == NULL || curr->next == NULL)
	{
		return head; // return gracefully
	}

	if(curr->next->next == NULL)
	{
		// removing the last node
		destroy_node(curr->next);
		curr->next = NULL;
		return head;
	}

	destroy_node(curr->next);
	curr->next = curr->next->next;
	curr->next->prev = curr;
	return head;

}

void foreach(Node *head , void (*function)(int data))
{
	for(Node *curr = head ; curr != NULL ; curr = curr->next)
	{
		function(curr->data);
	}
}

void ll_display(Node *head)
{
	if(head == NULL)
	{
		printf("[]\n");
		return;
	}
	Node *curr = head;
	printf("[");
	for(;curr->next != NULL ; curr = curr->next)
	{
		printf("%d, " ,curr->data);
	}

	printf("%d]\n" ,curr->data);
	return;
}



void ll_test_push_back()
{
	printf("running push back test ... \n");
	Node *head = NULL;
	for(int i = 0; i < 10 ; i++)
	{
		head = ll_push_back(head , i);
	}
	ll_display(head);
	destroy_linked_list(head);
	printf("push back test done \n");
	printf("==============================\n");
}

void ll_test_push_front()
{
	printf("running push front test ... \n");
	Node *head = NULL;
	for(int i = 0; i < 10 ; i++)
	{
		head = ll_push_front(head , i);
	}
	ll_display(head);
	destroy_linked_list(head);
	printf("push front test done \n");
	printf("==============================\n");
}
void ll_test_remove_front()
{
	printf("running remove front test ... \n");
	Node *head = NULL;

	for(int i = 0; i < 10 ; i++)
	{
		head = ll_push_front(head , i);
	}
	ll_display(head);

	for(int i = 0; i < 10 ; i++)
	{
		head = ll_remove_front(head);
		ll_display(head);
	}
	
	destroy_linked_list(head);
	printf("remove front test done \n");
	printf("==============================\n");
}
void ll_test_remove_back()
{
	printf("running remove back test ... \n");
	Node *head = NULL;

	for(int i = 0; i < 10 ; i++)
	{
		head = ll_push_front(head , i);
	}
	ll_display(head);

	for(int i = 0; i < 10 ; i++)
	{
		head = ll_remove_back(head);
		ll_display(head);
	}
	
	destroy_linked_list(head);
	printf("remove back test done \n");
	printf("==============================\n");
}
void ll_test_insert()
{
	printf("running insert test ... \n");
	Node *head = NULL;

	for(int i = 0; i < 10 ; i++)
	{
		head = ll_push_front(head , i);
	}
	ll_display(head);

	head = ll_insert(head , 11 , 1);
	ll_display(head);
	head = ll_insert(head , 22 , 2);
	ll_display(head);
	head = ll_insert(head , 99 , 10);
	ll_display(head);

	destroy_linked_list(head);
	printf("insert test done \n");
	printf("==============================\n");
}
void ll_test_remove()
{
	printf("running remove test ... \n");
	Node *head = NULL;

	for(int i = 0; i < 10 ; i++)
	{
		head = ll_push_front(head , i);
	}
	ll_display(head);

	head = ll_remove(head , 1);
	ll_display(head);
	head = ll_remove(head , 2);
	ll_display(head);
	head = ll_remove(head , 10);
	ll_display(head);

	destroy_linked_list(head);
	printf("remove test done \n");
	printf("==============================\n");
}
void ll_test_all()
{
	ll_test_push_back();
	ll_test_push_front();
	ll_test_remove_front();
	ll_test_remove_back();
	ll_test_insert();
	ll_test_remove();
}

