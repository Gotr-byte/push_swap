/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_manage.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:31:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/21 13:14:17 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// void	ft_print_t_node(int content)
// {
// 	printf ("%d\n", content);
// }
#include "push_swap.h"

void	local_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last)
	{
		if (last->next == NULL)
			break ;
		last = last->next;
	}
	last->next = new;
	return ;
}

t_node	*ft_lstnew_int(int content)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	if (!content)
		tmp->content = 0;
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}

void	local_lstiter(t_node **lst, void (*f)(int))
{
	t_node	*point_to_shift;

	point_to_shift = (*lst);
	while (point_to_shift)
	{
		(*f)(point_to_shift->content);
		point_to_shift = point_to_shift->next;
	}
}
