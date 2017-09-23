#include <stdio.h>
#include <stdlib.h>

//create_node
//append_node
//insert_after
//remove_node
//delete_node
//get_node


typedef struct Node
{
	int num;
	struct Node *prev, *next;
} Node;

Node* create_node(int num)
{
	Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	newNode->num = num;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

Node* append_node(Node** head, Node* newNode)
{
	if ((*head) == NULL)
	{
		*head = newNode;
	}
	else
	{
		Node* tail = NULL;
		tail = (*head);
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newNode;
		newNode->prev = tail;
	}
}

void insert_after(Node* current, Node* newNode)
{
	newNode->prev = current->next->prev;
	newNode->next = current->next;
	
	if (current->next != NULL) {
		current->next->prev = newNode;
	}
	current->next = newNode;
}

Node* get_node(Node* head, int num)
{
	Node* current = NULL;
	current = head;
	Node* temp = NULL;
	
	while (current != NULL)
	{
		if (current->num == num)
		{
			temp = current;
		}
		current = current->next;
	}
/*
	while (current != NULL && --num)
	{
		current = current->next;
	}
	temp = current;
	*/
	return temp;
}

void remove_node(Node** head, Node* Remove)
{
	if ((*head) == Remove)
	{
		*head = Remove->next;
		/* ºü¶ß¸° ºÎºĞ */
		if ((*head) != NULL)
		{
			(*head)->prev = NULL;
		}
	}
	else
	{
		Node* temp = Remove;

		Remove->prev->next = temp->next;
		if (Remove->next != NULL) {
			Remove->next->prev = temp->prev;
		}
	}

	Remove->prev = NULL;
	Remove->next = NULL;
}

void delete_node(Node* node)
{
	free(node);
}

void print_node(Node* head)
{
	Node* current = head;
	while (current != NULL)
	{
		printf("%d ", current->num);
		current = current->next;
	}
	printf("\n");
}

void pprint_node(Node* head, Node* tail)
{
	Node* temp = tail;

	while (temp != head)
	{
		printf("%d ", temp->num);
		temp = temp->prev;
	}

	printf("%d\n", temp->num);
}

int main()
{
	Node* head = NULL;
	
	Node* new_node = create_node(199);
	Node* insert_node = create_node(66);
	Node* my_node = create_node(505);
	Node* your_node = create_node(606);
	Node* find_node = NULL;
	Node* tail_node = NULL;

	//printf("%d\n", new_node->num);
	append_node(&head, new_node);
	append_node(&head, create_node(200));
	append_node(&head, create_node(2));
	append_node(&head, create_node(1111));
	append_node(&head, create_node(8));
	insert_after(new_node, insert_node);
	insert_after(head, my_node);
	insert_after(head, your_node);
	//find_node = get_node(head, 3);
	//insert_after(find_node, create_node(4));



	remove_node(&head, my_node);
	delete_node(my_node);
	remove_node(&head, new_node);
	delete_node(new_node);
	print_node(head);
	find_node = get_node(head, 8);
	pprint_node(head, find_node);
	//printf("\n node: %d\n", new_node->next->next->next->prev->num);
	return 0;

}