/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:26:40 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/20 16:28:39 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*local_lst_bef_last(t_node *lst)
{
	t_node	*tmp;
	t_node	*tmp_bef;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp_bef = tmp;
		tmp_bef = tmp_bef->next;
		if (tmp_bef->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

t_node	*local_lstlast(t_node *lst)
{
	t_node	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
