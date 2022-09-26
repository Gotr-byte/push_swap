/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:05:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/26 14:25:11 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	letter_err(char **av, int ac)
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
	return (0);
}

int	av_read(char **av, int ac)
{
	int	i;

	if (letter_err(av, ac))
		return (2);
	i = 1;
	while (i < ac)
	{
		if (is_limit(ft_atoi_long(av[i])))
			return (is_limit(ft_atoi_long(av[i])));
		i++;
	}
	if (plus_minus_count(av, ac))
		return (2);
	if (ac < 3)
		exit(0);
	if (sort_flag(av) == 1)
		exit(0);
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
				write (1, "Error\n", 7);
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
