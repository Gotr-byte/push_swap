/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:25:08 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 18:26:29 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*swap(t_node *ptr1, t_node *ptr2)
{
	t_node	*tmp;

	tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return (ptr2);
}

void	bubble_sort(t_node **head, int count)
{
	t_node	**h;
	t_node	*p1;
	t_node	*p2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= count)
	{
		h = head;
		while (j < count - i - 1)
		{
			p1 = *h;
			p2 = p1->next;
			if (p1->content > p2->content)
				*h = swap(p1, p2);
			h = &(*h)->next;
			j++;
		}
		j = 0;
		i++;
	}
}
