/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:05:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/20 17:31:21 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// need an is the same error handling
// need error handling for words instead of numbers
//some arguments aren’t integers, some arguments are
//bigger than an integer and/or there are duplicates.

#include "push_swap.h"

int	is_the_same(t_node **lst_a)
{
	t_node	*stack_a;
	t_node	*compare;

	stack_a = *lst_a;
	compare = *lst_a;
	while (stack_a)
	{
		while (compare)
		{
			if (compare->content == stack_a->content && \
			compare->position != stack_a->position)
			{
				write (1, "Entry error: same numbers\n", 27);
				// free (lst_a);
				exit (2);
			}
			compare = compare->next;
		}
		compare = *lst_a;
		stack_a = stack_a->next;
	}
	return (0);
}

// int	is_letter()

//int is_limit()
