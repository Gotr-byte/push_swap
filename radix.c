/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:08:21 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 19:16:29 by pbiederm         ###   ########.fr       */
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
	t_var	var;

	var.stack_a = (*lst_a);
	var.stack_b = (*lst_b);
	var.a = 0;
	var.b = 0;
	while (!is_sorted(&var.stack_a))
	{
		while (var.b < size)
		{
			if ((var.stack_a->index >> var.a) & 1)
				rot(&var.stack_a);
			else
				ft_push_b(&var.stack_a, &var.stack_b);
			var.b++;
		}
		while (var.stack_b)
			ft_push_a(&var.stack_a, &var.stack_b);
		var.b = 0;
		var.a++;
	}
	(*lst_a) = var.stack_a;
	(*lst_b) = var.stack_b;
}
