/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:11:26 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/17 14:46:17 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*t_node_to_push;

	if (!(*stack_a))
		return ;
	t_node_to_push = (*stack_a);
	(*stack_a) = (*stack_a)->next; 
	t_node_to_push->next = NULL;
	if (!*stack_b)
		(*stack_b) = t_node_to_push;
	else
	{
		t_node_to_push->next = (*stack_b);
		(*stack_b) = t_node_to_push;
	}
	t_node_to_push = NULL;
	write (1, "pa\n", 3);
}

void	ft_push_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*t_node_to_push;

	if (!(*stack_a))
		return ;
	t_node_to_push = (*stack_a);
	(*stack_a) = (*stack_a)->next; 
	t_node_to_push->next = NULL;
	if (!*stack_b)
		(*stack_b) = t_node_to_push;
	else
	{
		t_node_to_push->next = (*stack_b);
		(*stack_b) = t_node_to_push;
	}
	t_node_to_push = NULL;
	write (1, "pb\n", 3);
}

void	rot(t_node **head)
{
	t_node	*prev;
	t_node	*curr;
	t_node	*traverse;

	write(1, "ra\n", 3);
	prev = *head;
	curr = *head;
	traverse = *head;
	traverse = traverse->next;
	prev = local_lstlast(prev);
	prev->next = curr;
	curr->next = NULL;
	*head = traverse;
}

void	rot_b(t_node **head)
{
	t_node	*prev;
	t_node	*curr;
	t_node	*traverse;

	write(1, "rb\n", 3);
	prev = *head;
	curr = *head;
	traverse = *head;
	traverse = traverse->next;
	prev = local_lstlast(prev);
	prev->next = curr;
	curr->next = NULL;
	*head = traverse;
}

void	rev_rot(t_node **head)
{
	t_node	*prev;
	t_node	*curr;
	t_node	*traverse;

	write(1, "rra\n", 4);
	prev = *head;
	curr = *head;
	traverse = *head;
	traverse = local_lstlast(traverse);
	prev = local_lst_bef_last(prev);
	prev->next = NULL;
	traverse->next = curr;
	*head = traverse;
}