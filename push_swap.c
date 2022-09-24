/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 15:42:14 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//need an is the same error handling
//need error handling for words instead of numbers
//some arguments aren’t integers, some arguments are
//bigger than an integer and/or there are duplicates.
//need a cleaner function that traverses the nodes and frees them
// the error handling should check the input av

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
	(*stack_a) = head_a;
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*sorted;
	t_node	*stack_b;
	int		i;

	// printf("size of t node: %lu", sizeof(t_node));
	if (av_read(av, ac))
		return (write(2, "Error\n", 6));
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	sorted = NULL;
	while (i < ac)
	{
		local_lstadd_back(&stack_a, ft_lstnew_int(ft_atoi(av[i])));
		local_lstadd_back(&sorted, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}
	indexes(&stack_a);
	bubble_sort(&sorted, ac-1);
	// mrgsort(&sorted);
	indexes(&sorted);
	con_to_index(&stack_a, &sorted);
	positions(&stack_a);
	is_the_same(&stack_a);
	if (is_sorted(&stack_a))
	{
		free_lst(sorted);
		sorted = NULL;
		free_lst(stack_b);
		stack_b = NULL;
		free_lst(stack_a);
		stack_a = NULL;
		return (0);
	}
	handle(&stack_a, &stack_b, ac);
	// radix(&stack_a, &stack_b, ac - 1);
	free_lst(sorted);
	sorted = NULL;
	free_lst(stack_b);
	stack_b = NULL;
	free_lst(stack_a);
	stack_a = NULL;
	return (0);
	// local_lstiter(&sorted, &ft_print_t_node);
	// free (av);
	// av = NULL;
	// write(1, "1\n", 2);
	// return (0);
}
