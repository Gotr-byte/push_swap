/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:28:59 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 15:36:16 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_four(t_node **stack_a, t_node **stack_b)
{
	ft_push_b(stack_a, stack_b);
	sort_three(stack_a);
	ft_push_a(stack_a, stack_b);
	rot(stack_a);
}

static void	case_two(t_node **stack_a, t_node **stack_b)
{
	ft_push_b(stack_a, stack_b);
	sort_three(stack_a);
	ft_push_a(stack_a, stack_b);
	ft_swap_a(stack_a);
}

static void	case_three(t_node **stack_a, t_node **stack_b)
{
	ft_push_b(stack_a, stack_b);
	sort_three(stack_a);
	rev_rot(stack_a);
	ft_push_a(stack_a, stack_b);
	rot(stack_a);
	rot(stack_a);
}

static void	case_one(t_node **stack_a, t_node **stack_b)
{
	ft_push_b(stack_a, stack_b);
	sort_three(stack_a);
	ft_push_a(stack_a, stack_b);
}

// void	sort_four(t_node **lst)
// {
// 	t_node	*stack_a;
// 	t_node	*stack_b;

// 	stack_a = *lst;
// 	stack_b = NULL;
// 	if (stack_a->index == 4)
// 		return (case_four(stack_a, stack_b));
// 	else if (stack_a->index == 2)
// 		return (case_two (stack_a, stack_b));
// 	else if (stack_a->index == 3)
// 		return (case_three(stack_a, stack_b));
// 	else if (stack_a->index == 1)
// 		return (case_one(stack_a, stack_b));
// }

void	sort_four(t_node **stack_a, t_node **stack_b)
{
	// t_node	*stack_a;
	// t_node	*stack_b;

	// stack_a = *lst;
	// stack_b = NULL;
	if ((*stack_a)->index == 4)
		return (case_four(stack_a, stack_b));
	else if ((*stack_a)->index == 2)
		return (case_two (stack_a, stack_b));
	else if ((*stack_a)->index == 3)
		return (case_three(stack_a, stack_b));
	else if ((*stack_a)->index == 1)
		return (case_one(stack_a, stack_b));
}
