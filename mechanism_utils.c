/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanism_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:26:40 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 12:41:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//this needs some thinking
#include "push_swap.h"

// t_node	*local_lst_bef_last(t_node *lst)
// {
// 	t_node	*tmp;
// 	t_node	*tmp_bef;

// 	if (!lst)
// 	{
// 		tmp = NULL;
// 		tmp_bef = NULL;
// 		return (NULL);
// 	}
// 	tmp = lst;
// 	tmp_bef = lst;
// 	if (tmp->next != NULL)
// 		tmp = tmp->next;
// 	while (tmp->next != NULL)
// 	{
// 		tmp = tmp->next;
// 		tmp_bef = tmp->next;
// 	}
// 	return (tmp_bef);
// }

t_node	*local_lstlast(t_node *lst)
{
	t_node	*tmp;

	if (!lst)
	{
		tmp = NULL;
		return (NULL);
	}
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
