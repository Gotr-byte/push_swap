/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:11:26 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/26 13:29:58 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	local_lstadd_front(stack_b, \
	ft_lstnew_push((*stack_a)->content, \
	(*stack_a)->index, (*stack_a)->position));
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	free(tmp);
	write(1, "pb\n", 3);
}

void	ft_push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*tmp;

	local_lstadd_front(stack_a, \
	ft_lstnew_push((*stack_b)->content, \
	(*stack_b)->index, (*stack_b)->position));
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	free(tmp);
	write(1, "pa\n", 3);
}

void	rot(t_node **head)
{
	t_node	*last;
	t_node	*first;
	t_node	*second;

	first = (*head);
	last = (*head);
	while (last->next != NULL)
		last = last->next;
	second = first->next;
	last->next = first;
	first->next = NULL;
	(*head) = second;
	write(1, "ra\n", 3);
}

void	rev_rot(t_node **head)
{
	t_node	*last;
	t_node	*before_last;

	if (!head)
		return ;
	before_last = NULL;
	last = *head;
	while (last->next != NULL)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *head;
	*head = last;
	write(1, "rra\n", 4);
}
