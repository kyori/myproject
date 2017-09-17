#include <stdio.h>
#include <stdlib.h>

// ��� ����  (create_node) : ok
// ��� ����  (append_node) : ok
// insert_after
// ��� ����  (remove_node)
// ��� �ı�? (delete_node)
// get_node

typedef struct Node
{
	int num;
	struct Node* prev;
	struct Node* next;
} Node;


Node* create_node(int num)
{
	Node* newNode;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->num = num;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

void append_node(Node** head, Node* newNode)
{
	if ((*head) == NULL)
	{
		*head = newNode;
	}
	else
	{
		Node* tail = (*head);
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newNode;
		newNode->prev = tail;      
	}
}

void print_node(Node* head)
{
	Node* current = head;
	while (current != NULL)
	{
		printf("%d ", current->num);
		current = current->next;
	}
}

int main()
{
	Node* head = NULL;
	Node* new_node = NULL;
	Node* next_node = NULL;

	new_node = create_node(117);
	next_node = create_node(119);
	append_node(&head, new_node);
	append_node(&head, next_node);
	append_node(&head, create_node(225));

	print_node(head);
	return 0;
}