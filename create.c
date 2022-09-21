/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:27:04 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/21 13:33:03 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	create(t_node **a, t_node **b, t_node **sort, char **av, int ac)
{
	int i;

	i = 1;
	a = NULL;
	b = NULL;
	sort = NULL;
	while (i < ac)
	{
		local_lstadd_back(&a, ft_lstnew_int(ft_atoi(av[i])));
		local_lstadd_back(&sort, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}
	indexes(&a);
	mrgsort(&sort);
	indexes(&sort);
	con_to_index(&a, &sort);
	positions(&a);
}
