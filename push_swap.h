/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:55:43 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/24 17:59:05 by pbiederm         ###   ########.fr       */
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
	struct t_nodes	*next;
}	t_node;
typedef struct s_variable_bucket
{
	t_node	*point_to_shift;
	int		a;
	int		b;
	int		c;
	t_node	*stack_a;
	t_node	*stack_b;
	int		sent;
}t_var;

void		ft_print_t_node(int content);
void		ft_push_b(t_node **stack_a, t_node **stack_b);
void		ft_push_a(t_node **stack_a, t_node **stack_b);
void		rot(t_node **head);
void		rot_b(t_node **head);
void		rev_rot(t_node **head);
void		ft_swap_a(t_node	**head);
t_node		*local_lstlast(t_node *lst);
void		mrgsort(t_node **headRef);
void		sort_two(t_node **lst);
void		sort_three(t_node **lst);
void		sort_five(t_node **lst_a, t_node **lst_b);
void		indexes(t_node **stack);
void		local_lstiter(t_node **lst, void (*f)(int));
void		rot(t_node **head);
void		rot_b(t_node **head);
void		rev_rot(t_node **head);
t_node		*ft_lstnew_pl(int content, int index, int position);
void		local_lstadd_back(t_node **lst, t_node *new);
int			is_sorted(t_node **stack);
void		sort_two(t_node **lst);
void		rev_rot_b(t_node **head);
void		positions(t_node **stack);
void		radix(t_node **lst_a, t_node **lst_b, int size);
void		con_to_index(t_node **lst_con, t_node **lst_i);
t_node		*local_lstlast(t_node *lst);
void		local_lstiter(t_node **lst, void (*f)(int));
t_node		*ft_lstnew_int(int content);
void		local_lstadd_back(t_node **lst, t_node *new);
int			is_the_same(t_node **lst_a);
int			av_read(char **av, int ac);
int			is_limit(long int checklimit);
long int	ft_atoi_long(const char *str);
int			plus_minus_count(char **av, int ac);
void		free_lst(t_node	*head);
void		bubble_sort(t_node **head, int count);
void		sort_four(t_node **stack_a, t_node **stack_b);
void		sort_four_five(t_node **stack_a, t_node **stack_b);

#endif