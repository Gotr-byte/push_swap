/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/20 16:54:16 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// need an is the same error handling
// need error handling for words instead of numbers
//some arguments aren’t integers, some arguments are
//bigger than an integer and/or there are duplicates.

#include "./libft/libft.h"
#include "push_swap.h"

void	handle(t_node	**stack_a, int ac)
{
	if (ac == 3)
		sort_two(stack_a);
	if (ac == 4)
		sort_three(stack_a);
	if (ac == 5)
		sort_four(stack_a);
	if (ac == 6)
		sort_five(stack_a);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*sorted;
	t_node	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	sorted = NULL;
	while (i < ac)
	{
		local_lstadd_back(&stack_a, ft_lstnew_int(ft_atoi(av[i])));
		local_lstadd_back(&sorted, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}
	indexes(&stack_a);
	mrgsort(&sorted);
	indexes(&sorted);
	con_to_index(&stack_a, &sorted);
	free(sorted);
	positions(&stack_a);
	stack_b = NULL;
	if (is_sorted(&stack_a))
		return (0);
	handle(&stack_a, ac);
	radix(&stack_a, &stack_b, ac - 1);
	free(stack_a);
	free(stack_b);
}
