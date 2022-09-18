/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:55:43 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/18 20:55:47 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct t_nodes
{
	int				content;
	int				index;
	int				position;
	int				chonk_size;
	int				new_chonk_size;
	struct t_nodes	*next;
}	t_node;
struct	s_variable_bucket
{
	t_node	*point_to_shift;
	int		a;
	int		b;
	int		c;
	t_node	*stack_a;
	t_node	*stack_b;
	int		sent;
}var;

void	ft_push_a(t_node **stack_a, t_node **stack_b);
void	ft_push_b(t_node **stack_a, t_node **stack_b);
void	rot(t_node **head);
void	rot_b(t_node **head);
void	rev_rot(t_node **head);
void	rev_rot_b(t_node **head);
void	ft_swap_a(t_node	**head);
t_node	*local_lst_bef_last(t_node *lst);
t_node	*local_lstlast(t_node *lst);
void	mrgsort(t_node **headRef);
void	sort_two(t_node **lst);
void	sort_three(t_node **lst);
void	sort_four(t_node **lst);
void	sort_five(t_node **lst);
void	indexes(t_node **stack);
void	positions(t_node **stack);
int		count_chonk_number(t_node **lst, int chonksize);
void	chonk_resize(t_node **lst, int rest_chonk, int new_size);
int		is_less_than_mid(t_node **lst, int rest_chonk, int midpoint);
void	local_lstiter_chonks(t_node *lst, void (*f)(int));
void	local_lstiter(t_node *lst, void (*f)(int));
int		find_mid(t_node **lst);
void	big_sort(t_node **lst, t_node **lst_b, int len_init, int mode);
void	ft_push_b(t_node **stack_a, t_node **stack_b);
void	rot(t_node **head);
void	rot_b(t_node **head);
void	rev_rot(t_node **head);
void	ft_print_t_node(int content);
t_node	*ft_lstnew_pl(int content, int index, int position, int chonk_size);
void	local_lstadd_back(t_node **lst, t_node *new);
int		t_nodes_count(t_node **lst);
int		is_sorted(t_node **stack);
void	sort_two(t_node **lst);
void	sort_two_b(t_node **lst);
void	ft_push_a(t_node **stack_a, t_node **stack_b);
void	rev_rot_b(t_node **head);
void	local_lstiter_chonks(t_node *lst, void (*f)(int));
void	positions(t_node **stack);
void	rot_one(t_node **stack_a);
void	rev_rot_one(t_node **stack_a);

#endif