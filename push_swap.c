/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/30 11:55:12 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void	handle(t_node	**stack_a, t_node **stack_b, int ac)
{
	t_node	*head_a;

	head_a = (*stack_a);
	if (ac == 3)
		sort_two(&head_a);
	if (ac == 4)
		sort_three(&head_a);
	if (ac == 5)
		sort_four(&head_a, stack_b);
	if (ac == 6)
		sort_five(&head_a, stack_b);
	if (ac > 6)
		radix(&head_a, stack_b, ac - 1);
	(*stack_a) = head_a;
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*sorted;
	t_node	*stack_b;
	int		i;

	if (av_read(av, ac))
		return (write(2, "Error\n", 6));
	i = 1;
	while (i < ac)
	{
		local_lstadd_back(&stack_a, ft_lstnew_int(ft_atoi(av[i])));
		local_lstadd_back(&sorted, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}
	indexes(&stack_a);
	bubble_sort(&sorted, ac - 1);
	indexes(&sorted);
	con_to_index(&stack_a, &sorted);
	positions(&stack_a);
	is_the_same(&stack_a, &stack_b, &sorted);
	handle(&stack_a, &stack_b, ac);
	free_lst(sorted);
	free_lst(stack_b);
	free_lst(stack_a);
	return (0);
}
