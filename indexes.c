/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 20:54:16 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/20 16:14:10 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexes(t_node **stack)
{
	t_node	*stack_index;
	int		i;

	stack_index = *stack;
	i = 1;
	while (1)
	{
		stack_index->index = i;
		i++;
		if (stack_index->next == NULL)
			break ;
		stack_index = stack_index->next;
	}
}

void con_to_index(t_node **lst_con, t_node **lst_i)
{
	t_node	*index_t_nodes;
	t_node	*content_t_nodes;

	index_t_nodes = *lst_i;
	content_t_nodes = *lst_con;
	while (1)
	{
		index_t_nodes = *lst_i;
		while (1)
		{
			if (content_t_nodes->content == index_t_nodes->content)
				content_t_nodes->index = index_t_nodes->index;
			if (index_t_nodes->next == NULL)
				break ;
			index_t_nodes = index_t_nodes->next;
		}
		if (content_t_nodes->next == NULL)
			return ;
		content_t_nodes = content_t_nodes->next;
	}
}
