/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:25:08 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/23 16:47:46 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node*	swap(t_node* ptr1, t_node* ptr2)
{
	t_node* tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return ptr2;
}
 
/* Function to sort the list */
void bubble_sort(t_node** head, int count)
{
    t_node** h;
    int i, j, swapped;
 
    for (i = 0; i <= count; i++) {
 
        h = head;
        swapped = 0;
 
        for (j = 0; j < count - i - 1; j++) {
 
            t_node* p1 = *h;
            t_node* p2 = p1->next;
 
            if (p1->content > p2->content) {
 
                /* update the link after swapping */
                *h = swap(p1, p2);
                swapped = 1;
            }
 
            h = &(*h)->next;
        }
 
        /* break if the loop ended without any swap */
        if (swapped == 0)
            break;
    }
}