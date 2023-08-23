#include "main.h"

/**
 * add_node - add new node at the beginning of a list
 * @head: the pointer to the head of the list
 * @data: string
 *
 * Return: nothing
*/

void add_node(Node **head, const char *data)
{
	Node *create_node = new_node(data);

	create_node->next = *head;
	*head = create_node;
}



/**
 * new_node - creates new node
 * @data: string
 *
 * Return: Address of the new element
 */
Node *new_node(const char *data)
{
	Node *node = malloc(sizeof(Node));

	if (node == NULL)
	{
		return (NULL);
	}

	node->data = _strdup(data);
	node->next = NULL;
	return (node);
}

/**
 * free_list - Frees a list
 * @head: The list to be freed
 */
void free_list(Node *head)
{
	if (head)
	{
		free_list(head->next);
		if (head->data)
		{
			free(head->data);
		}
		free(head);
	}
}

/**
 *list_len - Returns the number of elements
 *in a linked listint_t list
 *@head: A pointer to the head of the list
 *
 *
 *Return: the number of elements in the listint_t list
 */

size_t list_len(const Node *head)
{
	size_t n = 0;

	while (head)
	{
		n++;
		head = head->next;
	}
	return (n);
}

/**
 * print_list - prints all the elements of a linked list
 * @head: list
 *
 * Return: Nothing
 */
void print_list(Node *head)
{
	Node *temp = head;

	while (temp)
	{
		/*print function*/
		temp = temp->next;
	}
}

