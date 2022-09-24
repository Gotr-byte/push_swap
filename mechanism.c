/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:11:26 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 15:13:05 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// in push a stack a is actually stack b

#include "push_swap.h"

void	ft_push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	if(!stack_a)
		return ;
	head_a = (*stack_a);
	head_b = (*stack_b);
	if (head_a->next != NULL)
		head_a = (*stack_a)->next;
	(*stack_a)->next = (*stack_b);
	(*stack_b) = (*stack_a);
	(*stack_a) = head_a;
	head_a = NULL;
	head_b = NULL;
	write(1, "pb\n", 3);
}

void	ft_push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	if(!stack_b)
		return ;
	head_a = (*stack_a);
	head_b = (*stack_b);
	if (head_a->next != NULL)
		head_b = (*stack_b)->next;
	(*stack_b)->next = (*stack_a);
	(*stack_a) = (*stack_b);
	(*stack_b) = head_b;
	head_a = NULL;
	head_b = NULL;
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
