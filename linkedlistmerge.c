/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistmerge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:26:44 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/29 18:26:44 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include "push_swap.h"
// typedef struct Nodes{
// 	int content;
// 	struct Nodes* next;
// }Node;

Node *SortedMerge (Node *a, Node *b);
void FrontBackSplit (Node *source, Node **frontRef, Node **backRef);

void MergeSort(Node **headRef)
{
	Node	*head = *headRef;
	Node	*a;
	Node	*b;

	if ((head == NULL) || (head->next == NULL))
	{
		return ;
	}
	FrontBackSplit(head, &a, &b);

	MergeSort(&a);
	MergeSort(&b);

	*headRef = SortedMerge(a, b);
}

Node *SortedMerge(Node *a, Node *b)
{
	Node	*result = NULL;
	
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->content <= b->content)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}

void FrontBackSplit(Node *source, Node **frontRef, Node **backRef)
{
	Node	*fast;
	Node	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast !=NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

void printList(Node *node)
{
	while(node != NULL)
	{
		printf("%d \n", node->content);
		node = node->next;
	}
}

// void push(Node **head_ref, int new_data)
// {
// 	Node* new_node = (Node *)malloc(sizeof(Node));

// 	new_node->content = new_data;
// 	new_node->next = (*head_ref);
// 	(*head_ref) = new_node;
// }

// int main()
// {
// 	Node *res = NULL;
// 	Node *a = NULL;

// 	push(&a, 15);
// 	push(&a, 10);
// 	push(&a, 5);
// 	push(&a, 11);
// 	push(&a, 3);
// 	push(&a, 2);

// 	MergeSort(&a);

// 	printf("Sorted Linked list is \n");
// 	printList(a);

// 	getchar();

// 	return (0);

// }