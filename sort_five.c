/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:44:30 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/26 21:25:45 by pbiederm         ###   ########.fr       */
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

int	find_min(t_node **lst_a)
{
	int		min_i;
	int		position;
	t_node	*find_min_i;

	min_i = 0;
	find_min_i = *lst_a;
	while (find_min_i)
	{
		if (min_i == 0 || min_i > find_min_i->index)
		{
			min_i = find_min_i->index;
			position = find_min_i->position;
		}
		find_min_i = find_min_i->next;
	}
	return (position);
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
		{
			if (find_min(&stack_a) == 2 || find_min(&stack_a) == 3)
				rot(&stack_a);
			else if (find_min(&stack_a) == 4 || find_min(&stack_a) == 5)
				rev_rot(&stack_a);
		}
		positions(&stack_a);
	}
	sort_four_five(&stack_a, &stack_b);
	ft_push_a(&stack_a, &stack_b);
	(*lst_a) = stack_a;
	(*lst_b) = stack_b;
}
