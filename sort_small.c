/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:12:37 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 18:34:49 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_rot(t_node **lst)
{
	ft_swap_a(lst);
	rot(lst);
}

void	sort_two(t_node **lst)
{
	t_node	*point_to_shift;
	int		a;
	int		b;

	point_to_shift = *lst;
	a = point_to_shift->content;
	point_to_shift = point_to_shift->next;
	b = point_to_shift->content;
	if (a <= b)
		return ;
	if (a > b)
		rot(lst);
}

void	sort_three(t_node **lst)
{
	t_var	var;

	var.point_to_shift = *lst;
	var.a = var.point_to_shift->content;
	var.point_to_shift = var.point_to_shift->next;
	var.b = var.point_to_shift->content;
	var.point_to_shift = var.point_to_shift->next;
	var.c = var.point_to_shift->content;
	if (var.a <= var.b && var.b <= var.c && var.c >= var.a)
		return ;
	else if (var.a < var.b && var.b > var.c && var.c > var.a)
		ft_swap_rot(lst);
	else if (var.a > var.b && var.b < var.c && var.c > var.a)
		ft_swap_a(lst);
	else if (var.a < var.b && var.c < var.b && var.c < var.a)
		rev_rot(lst);
	else if (var.a > var.b && var.b < var.c && var.c < var.a)
		rot(lst);
	else if (var.a > var.b && var.b > var.c && var.c < var.a)
	{
		ft_swap_a(lst);
		rev_rot(lst);
	}
}
