/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:44:30 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/17 18:48:01 by pbiederm         ###   ########.fr       */
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

static int	find_pos_one(t_node **lst)
{
	t_node	*stack_a;

	stack_a = *lst;
	while (1)
	{	
		if (stack_a->index == 1)
			return (stack_a->position);
		if (stack_a->next == NULL)
			return (-1);
		stack_a = stack_a->next;
	}
}

int	find_pos_two(t_node **lst)
{
	t_node	*stack_a;

	stack_a = *lst;
	while (1)
	{	
		if (stack_a->index == 2)
			return (stack_a->position);
		if (stack_a->next == NULL)
			return (-1);
		stack_a = stack_a->next;
	}
}

void sort_push_push(t_node **stack_b, t_node **stack_a)
{
	sort_three(stack_a);
	ft_push_a(stack_b, stack_a);
	ft_push_a(stack_b, stack_a);
}

void	sort_five(t_node **lst)
{
	var.sent = 2;
	var.stack_a = *lst;
	var.stack_b = NULL;
	while (1)
	{
		if (var.sent == 0)
			break ;
		if (var.stack_a->index == 1)
		{
			ft_push_b(&var.stack_a, &var.stack_b);
			var.sent--;
		}
		if (var.sent == 1 && var.stack_a->index == 2)
			{
				ft_push_b(&var.stack_a, &var.stack_b);
				var.sent--;
			}
		if (find_pos_one(&var.stack_a) < 4 || find_pos_two(&var.stack_a) < 4)
			rot(&var.stack_a);
		else if (find_pos_one(&var.stack_a) >= 4 || find_pos_two(&var.stack_a) >= 4)
			rev_rot(&var.stack_a);
		positions(&var.stack_a);
	}
	sort_push_push(&var.stack_b, &var.stack_a);
	local_lstiter(var.stack_a, &ft_print_t_node);
}

