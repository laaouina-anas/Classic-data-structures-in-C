# Linked List Implementation

This project is a doubly linked list implemented in pure C with a minimal set of libraries


## Usage

```c
#include <stdio.h>
#include <linked_list.h>

void custom_function(int *data)
{
   *data = *data * 2; // multiply all elements by 2

}

int main()
{
    Node *head = NULL; // empty linked list
    head = ll_push_back(head , 0);
    head = ll_push_front(head,1);
    head = ll_push_back(head,2);
    head = ll_insert(head ,3 , 3); 
    display(head);

    foreach(head , &custom_function);
    ll_destroy_linked_list(head);

    return 0;
}

```

## About

This project is made for educational purposes only, It
is not designed for real world use.
It focuses on algorithmic thinking and simplicity more than usability and performance.
## License

You are free to use this code however you want !
