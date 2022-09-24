/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:05:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/23 14:11:51 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//X  need an is the same error handling
//X  need error handling for words instead of numbers
//X some arguments aren’t integers, some arguments are
//X bigger than an integer and/or there are duplicates.
// -2,147,483,648 to 2,147,483,647
// -0x80000000 0x7FFFFFFF

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	av_read(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+')
				return (2);
			j++;
		}
		j = 0;
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if (is_limit(ft_atoi_long(av[i])))
			return (is_limit(ft_atoi_long(av[i])));
		i++;
	}
	if (plus_minus_count(av, ac))
		return (2);
	return (0);
}

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
				exit (2);
			}
			compare = compare->next;
		}
		compare = *lst_a;
		stack_a = stack_a->next;
	}
	return (0);
}

int	plus_minus_count(char **av, int ac)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 1;
	j = 0;
	while (i < ac)
	{
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				count++;
			if (count == 2)
				return (2);
		j++;
		}
		count = 0;
		j = 0;
		i++;
	}
	return (0);
}

int	is_limit(long int checklimit)
{
	if (checklimit < (-2147483648))
	{
		return (2);
	}
	else if (checklimit > 0x7FFFFFFF)
	{
		return (2);
	}
	else
		return (0);
}

// int	main()
// {
// 	printf("Output signal: %d",is_limit(21474836));
// 	return(is_limit(21474836));
// }
