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

t_node *SortedMerge (t_node *a, t_node *b);
void FrontBackSplit (t_node *source, t_node **frontRef, t_node **backRef);

void	mrgsort(t_node **headRef)
{
	t_node	*head = *headRef;
	t_node	*a;
	t_node	*b;

	if ((head == NULL) || (head->next == NULL))
	{
		return ;
	}
	FrontBackSplit(head, &a, &b);
	mrgsort(&a);
	mrgsort(&b);
	*headRef = SortedMerge(a, b);
}

t_node	*SortedMerge(t_node *a, t_node *b)
{
	t_node	*result = NULL;
	
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

void FrontBackSplit(t_node *source, t_node **frontRef, t_node **backRef)
{
	t_node	*fast;
	t_node	*slow;

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
