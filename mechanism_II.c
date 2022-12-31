/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism_II.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:31:31 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 14:41:14 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_node	**head)
{
	t_node	*first;
	t_node	*second;
	t_node	*temp;

	first = *head;
	second = *head;
	if (second->next != NULL)
		second = second->next;
	if (first == NULL || first->next == NULL)
		return ;
	write(1, "sa\n", 3);
	temp = second;
	first->next = temp->next;
	second->next = first;
	*head = second;
}
