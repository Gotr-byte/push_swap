/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:26:40 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/26 13:30:03 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	local_lstadd_front(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

t_node	*ft_lstnew_push(int content, int index, int position)
{
	t_node	*tmp;

	tmp = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!tmp)
		return (NULL);
	if (!content)
		tmp->content = 0;
	if (tmp)
	{
		tmp->content = content;
		tmp->index = index;
		tmp->position = position;
		tmp->next = NULL;
	}
	return (tmp);
}
