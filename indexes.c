/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:54:16 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/18 20:56:43 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexes(t_node **stack)
{
	t_node	*stack_index;
	int		i;

	stack_index = *stack;
	i = 1;
	while (1)
	{
		stack_index->index = i;
		stack_index->new_chonk_size = 0;
		i++;
		if (stack_index->next == NULL)
			break ;
		stack_index = stack_index->next;
	}
}