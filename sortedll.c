/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortedll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:42:58 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/29 14:42:58 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


Node * insert(Node *head, int data)
{
	Node* temp;
	Node *newP;
	int key = newP->content;	

	newP = malloc(sizeof(Node));
	newp->data = data;
	newP-> = NULL;

	int keu = data;
	if (head == NULL || key < head->data)
	{
		newP->link = head;
		head = newP;
	}
	else
	{
		temp = head;
		while (temp->next != NULL && temp->next->content < key)
		{
			temp - temp->next;
		}
		temp->next = newP;
	}
}
