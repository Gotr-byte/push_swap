/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:44:30 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 15:37:25 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	positions(t_node **stack)
{
	t_node	*stack_index;
	int		i;

	stack_index = *stack;
	i = 1;
	while (1)
	{
		stack_index->position = i;
		i++;
		if (stack_index->next == NULL)
			break ;
		stack_index = stack_index->next;
	}
}

void	sort_five(t_node **lst_a, t_node **lst_b)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = *lst_a;
	stack_b = *lst_b;
	while (1)
	{
		if (stack_a->index == 1)
		{
			ft_push_b(&stack_a, &stack_b);
			break ;
		}
		else
			rev_rot(&stack_a);
	}
	sort_four_five(&stack_a);
	ft_push_a(&stack_a, &stack_b);
	(*lst_a) = stack_a;
	(*lst_b) = stack_b;
}
