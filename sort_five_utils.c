/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:08:28 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/17 17:32:38 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_one (t_node **stack_a)
{
	t_node *tmp_stack_a;

	tmp_stack_a = *stack_a;
	rot(&tmp_stack_a);
	positions(&tmp_stack_a);	
}

void rev_rot_one (t_node **stack_a)
{
	t_node *tmp_stack_a;

	tmp_stack_a = *stack_a;
	rev_rot(&tmp_stack_a);
	positions(&tmp_stack_a);	
}