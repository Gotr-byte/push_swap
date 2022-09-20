/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism_II.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:31:31 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/20 14:51:09 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot_b(t_node **head)
{
	t_node	*prev;
	t_node	*curr;
	t_node	*traverse;

	write(1, "rrb\n", 4);
	prev = *head;
	curr = *head;
	traverse = *head;
	traverse = local_lstlast(traverse);
	prev = local_lst_bef_last(prev);
	prev->next = NULL;
	traverse->next = curr;
	*head = traverse;
}

void	ft_swap_a(t_node	**head)
{
	t_node	*currX;
	t_node	*currY;
	t_node	*temp;

	write(1, "sa\n", 3);
	currX = *head;
	currY = *head;
	if (currX == NULL || currY == NULL || \
	currY->next == NULL || currX->next == NULL)
		return ;
	currY = currY->next;
	temp = currY->next;
	currY->next = currX;
	currX->next = temp;
	*head = currY;
}