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

#include "push_swap.h"

t_node	*sortedmerge(t_node *a, t_node *b);
void	front_back_split(t_node *source, t_node **frontRef, t_node **backRef);

void	mrgsort(t_node **head_ref)
{
	t_node	*head;
	t_node	*a;
	t_node	*b;

	head = *head_ref;
	if ((head == NULL) || (head->next == NULL))
		return ;
	front_back_split(head, &a, &b);
	mrgsort(&a);
	mrgsort(&b);
	*head_ref = sortedmerge(a, b);
}

t_node	*sortedmerge(t_node *a, t_node *b)
{
	t_node	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (a->content <= b->content)
	{
		result = a;
		result->next = sortedmerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sortedmerge(a, b->next);
	}
	return (result);
}

void	front_back_split(t_node *source, t_node **frontRef, t_node **backRef)
{
	t_node	*fast;
	t_node	*slow;

	slow = source;
	fast = source->next;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			fast = fast->next;
			slow = slow->next;
		}
	}
	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}
