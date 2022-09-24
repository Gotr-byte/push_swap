/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:08:21 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/23 19:24:59 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **stack)
{
	t_node	*i;
	t_node	*j;
	int		sort_flag;

	sort_flag = 1;
	if (!stack)
		return (0);
	i = (*stack);
	if (i->next == NULL)
		return (sort_flag);
	j = (*stack);
	j = j->next;
	while (1)
	{
		if (j->content < i->content)
			sort_flag = 0;
		if (j->next == NULL)
			break ;
		j = j->next;
		i = i->next;
	}
	return (sort_flag);
}

void	radix(t_node **lst_a, t_node **lst_b, int size)
{
	int		i;
	int		j;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = (*lst_a);
	stack_b = (*lst_b);
	i = 0;
	j = 0;
	while (!is_sorted(&stack_a))
	{
		while (j < size)
		{
			if ((stack_a->index >> i) & 1)
				rot(&stack_a);
			else
				ft_push_b(&stack_a, &stack_b);
			j++;
		}
		while (stack_b)
			ft_push_a(&stack_a, &stack_b);
		j = 0;
		i++;
	}
}
