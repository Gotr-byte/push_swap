/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/18 20:54:12 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//needs an is sorted function
//needs cases when to use functions with most sorting prowess
//we find the lis then it stays in stack a
// put the other things in stack b
//sort stack b
//if there is a largest one we can rotate it to the end maybe
// if we can put two in stack b and then rotate its good
// need a is sorted function
// could use subsequence
// follow the tutorial with the bucket sort 
// use index for 4 and 5
// push b is to be fixed
// sort descending in b
// divide by index 2
// sort by chunks and divide
// Nums to test 2 3 5 12 10 6 9 7 4 1 8 11
// is antisorted needed
// number of chunks behaviour pattern is needed
// Rei needs to be Rei and Asuka Asuka
// is reverse sorted needs test
// reverse rotating when it is the last chunk in stack b needs a bit of work
// ARG=seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' '; ./push_swap $ARG
// above is testing randoms
// so we can have immovable chunks which are already sorted, we could use a function that recognises chunks that are already in the correct sequence

#include "./libft/libft.h"
#include "push_swap.h"
// #include <stdio.h>
// #include <stdlib.h>
// #include "linkedlistmerge.c"

int count_chonk_number (t_node **lst, int chonksize);
void chonk_resize(t_node **lst, int rest_chonk, int new_size);
int is_less_than_mid(t_node **lst, int rest_chonk, int midpoint);
void	local_lstiter_chonks(t_node *lst, void (*f)(int));
void	local_lstiter(t_node *lst, void (*f)(int));
int find_mid(t_node **lst);
void big_sort (t_node **lst, t_node **lst_b, int len_init, int mode);
void ft_push_b(t_node **stack_a, t_node **stack_b);
void rot(t_node **head);
void rot_b(t_node **head);
void rev_rot(t_node **head);
void ft_print_t_node(int content);
t_node	*ft_lstnew_pl(int content, int index, int position, int chonk_size);
void	local_lstadd_back(t_node **lst, t_node *new);
int	t_nodes_count (t_node **lst);
int is_sorted(t_node **stack);
void sort_two(t_node **lst);
void sort_two_b(t_node **lst);
void ft_push_a(t_node **stack_a, t_node **stack_b);
void rev_rot_b(t_node **head);
void	local_lstiter_chonks(t_node *lst, void (*f)(int));

int	t_nodes_count(t_node **lst)
{
	t_node *to_count;
	int		i;

	to_count = *lst;
	i = 0;
	while (to_count)
	{
		to_count = to_count->next;
		i++;
	}
	return (i);
}

t_node	*ft_lstnew_pl(int content, int index, int position, int chonk_size)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return (NULL);
	if (tmp)
	{
		tmp->content = content;
		tmp->position = position;
		tmp->index = index;
		tmp->chonk_size = chonk_size;
		tmp->next = NULL;
	}
	return (tmp);
}

int find_mid(t_node **lst)
{
	t_node	*find_last;
	t_node	*sorted;
	int	i;
	sorted = NULL;
	while(*lst)
	{
		local_lstadd_back(&sorted, ft_lstnew_pl((*lst)->content, (*lst)->index, (*lst)->position, (*lst)->chonk_size));
		(*lst) = (*lst)->next;
	}

	mrgsort(&sorted);
	find_last = sorted;
	i = 1;
	while(find_last->next != NULL)
	{
		find_last = find_last->next;
		i++;
	}
	find_last = sorted;
	
	i = i / 2;
	while(1)
	{
		if(i == 0)
			break;
		i--;
		if(find_last->next != NULL)
			find_last = find_last->next;
	}
	// free(sorted);
	i = find_last->index;
	// free(find_last);
	return (i);
}

int find_mid_b(t_node **lst, int chunk_size)
{
	t_node	*find_last;
	t_node	*sorted;
	int	i;
	i = chunk_size;
	sorted = NULL;
	if (i == 1)
		return ((*lst)->index);
	find_last = *lst;
	while(find_last && chunk_size)
	{
		local_lstadd_back(&sorted, ft_lstnew_pl(find_last->content, find_last->index, find_last->position, find_last->chonk_size));
		find_last = find_last->next;
		chunk_size--;
	}

	mrgsort(&sorted);
	find_last = sorted;
	i = i / 2;
	while(1)
	{
		if(i <= 0)
			break;
		i--;
		if(find_last->next != NULL)
		{
			find_last = find_last->next;
			
		}
	}
	i = find_last->index;
	return (i);
}

int ft_chonk_size(t_node **lst)
{
	int		i;
	t_node	*find_last;

	find_last = *lst;
	i = 0;
	while(find_last != NULL)
	{
		i++;
		find_last = find_last->next;
	}
	find_last = *lst;
	return (i / 2);
}

void	chonkifier( t_node	**lst, int chonk_size)
{
	t_node *traverse;
	int i;

	i = 0;
	traverse = *lst;
	while ((chonk_size - i) != 0)
	{
		traverse->chonk_size = chonk_size;
		traverse = traverse->next;
		if (i == chonk_size)
			break ;
		i++;
	}
}

void big_sort (t_node **lst, t_node **lst_b, int len_init, int mode)
{
	int		i;
	int		m;
	int		chonk_size;
	int		rev_rot_count;
	int		test;
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*kite;

	test = 0;
	rev_rot_count = 0;
	stack_a = *lst;
	stack_b = *lst_b;
	if (mode == 1)
		i = find_mid(lst);
	if (mode == -1)
		{
			if (stack_b != NULL)
				i = find_mid_b(&stack_b, stack_b->chonk_size);
		}
	if(mode == 1)
		chonk_size = ft_chonk_size(&stack_a);
	if(mode == -1 && stack_b != NULL)
	{
		chonk_size = stack_b->chonk_size;
	}
	m = chonk_size;
	if(is_sorted(&stack_a) && t_nodes_count(&stack_a) == len_init)
	{
		return ;

	}
	if (t_nodes_count(&stack_a) > 2 && mode == 1)
	{	
		while(m != 0)
		{
			if (stack_a->index < i)
			{
				stack_a->chonk_size = chonk_size;
				ft_push_b(&stack_a, &stack_b);
				m--;
			}
			else
			{
				kite = stack_a;
				while(kite->next != NULL)
					{
						kite = kite->next;
					}
				if(kite->index < i)
					{
						rev_rot(&stack_a);
						stack_a->chonk_size = chonk_size;
						ft_push_b(&stack_a, &stack_b);
						m--;
					}
				else
				{
					rot(&stack_a);
				}
			}
		}
		big_sort(&stack_a, &stack_b, len_init, mode);
	}
	else if (t_nodes_count(&stack_b) > 2 && mode == -1)
	{	
		if (stack_b->chonk_size == 1)
		{
	
			ft_push_a(&stack_b, &stack_a);
			m--;
		}
		while(m != 0)
		{
			if(m == 2 && rev_rot_count == 0)
			{
					sort_two_b(&stack_b);
					ft_push_a(&stack_b, &stack_a);
					ft_push_a(&stack_b, &stack_a);
					m = m - 2;
			}
			if(m > 2)
			{
				if (stack_b->index > i)
				{
					ft_push_a(&stack_b, &stack_a);
					m--;
				}
				else
				{
					if (is_less_than_mid(&stack_b, m, i) > 0)
					{
						// printf ("m2: %d\n ", m);
						while (rev_rot_count > 0)
						{
							rev_rot_b(&stack_b);
							rev_rot_count--;
						}
						chonk_resize(&stack_b, count_chonk_number(&stack_b, stack_b->chonk_size), count_chonk_number(&stack_b, stack_b->chonk_size));
						big_sort(&stack_a, &stack_b, len_init, mode);
					}
					if(stack_b != NULL)
						{
							rot_b(&stack_b);
							rev_rot_count++;
							m--;
						}

				}
			}
			if(m <= 0 || (m == 2 && rev_rot_count > 0))
			{
				break;
				test = 1;
			}
		}
		if (test == 1)
			{
				return ;
			}
		big_sort(&stack_a, &stack_b, len_init, mode);
	}
	else if (t_nodes_count(&stack_a) == 2 && mode == 1)
	{
		sort_two(&stack_a);
		mode = mode * -1;
		big_sort(&stack_a, &stack_b, len_init, mode);
	}
	else if (stack_b == NULL && mode == -1)
	{
		mode = mode * -1;
		big_sort(&stack_a, &stack_b, len_init, mode);
	}
}

int count_chonk_number (t_node **lst, int chonksize)
{
	t_node	*traverse;
	t_node	*traverse_next;
	int chonk_number;

	chonk_number = 0;
	if (lst == NULL)
		return (0);
	traverse = *lst;
	traverse_next = *lst;
	traverse_next = traverse_next->next;
	while (chonksize > 0)
	{
		chonk_number++;
		if (traverse->next == NULL)
			return(chonk_number);
		if (traverse->chonk_size != traverse_next->chonk_size)
			return(chonk_number);
		traverse = traverse->next;
		if (traverse_next->next != NULL)
			traverse_next = traverse_next->next;
		chonksize--;
	}
	return(chonk_number);
}

int is_less_than_mid(t_node **lst, int rest_chonk, int midpoint)
{
	t_node *traverse;
	int chonk_size;

	traverse = *lst;
	chonk_size = 1;
	while(rest_chonk--)
	{
		if(traverse->index > midpoint)
			return(0);
		if (traverse->next == NULL)
			return(chonk_size);
		chonk_size++;
		traverse = traverse->next;
	}
	return(chonk_size);
}

void chonk_resize(t_node **lst, int rest_chonk, int new_size)
{
	t_node *traverse;

	traverse = *lst;
	while (rest_chonk > 0)
	{
		traverse->chonk_size = new_size;
		if (traverse->next == NULL)
			return ;
		traverse = traverse->next;
		rest_chonk--;
	}
}

void ft_print_t_node(int content)
{
	printf ("%d\n", content);
}

void del_pos(t_node **head, int position)
{
	t_node	*current;
	t_node	*previous;

	current = *head;
	previous = *head;
	if(*head == NULL)
		printf("Lists are empty");
	else if(position == 1)
	{
		*head = current->next;
		free(current);
		current = NULL;
	}
	else
	{
		while (position != 1)
		{
			previous = current;
			current = current->next;
			position--;
		}
		previous->next = current->next;
		free(current);
		current = NULL;
	}
}

void	ft_swap_b(t_node	**head)
{
	t_node	*currX;
	t_node	*currY;
    t_node	*temp;
	
	write(1, "sb\n", 3);
	currX = *head;
	currY = *head;
    if (currX == NULL || currY == NULL ||
	currY->next == NULL || currX->next == NULL)
        return;
    currY = currY->next;
	temp = currY->next;
    currY->next = currX;
    currX->next = temp;
	*head = currY;
}

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

void	local_lstiter(t_node *lst, void (*f)(int))
{
	t_node	*point_to_shift;

	point_to_shift = lst;
	while (point_to_shift)
	{
		(*f)(point_to_shift->content);
		point_to_shift = point_to_shift->next;
	}
}

void	local_lstiter_chonks(t_node *lst, void (*f)(int))
{
	t_node	*point_to_shift;

	point_to_shift = lst;
	while (point_to_shift)
	{
		(*f)(point_to_shift->chonk_size);
		point_to_shift = point_to_shift->next;
	}
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
		if(tmp_bef->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

// may not need this
void	sort_two_b(t_node **lst)
{
	t_node	*point_to_shift;
	int		a;
	int		b;

	point_to_shift = *lst;
	a = point_to_shift->content;
	point_to_shift = point_to_shift->next;
	b = point_to_shift->content;
	if (a <= b)
	{
		ft_swap_b(lst);
		return ;
	}
	if (a > b)
		return ;
}

int is_sorted(t_node **stack)
{
	t_node	*i;
	t_node	*j;
	int		sort_flag;
	
	sort_flag = 1;
	i = (*stack);
	j = (*stack);
	j = j->next;
	
	while (1)
	{
		if(j->content == i->content)
		{
			sort_flag = 2;
			break ;
		}
		if(j->content < i->content)
			sort_flag = 0;
		if(j->next == NULL)
			break ;
		j = j->next;
		i = i->next;
	}
	return(sort_flag);	
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
			if(content_t_nodes->content == index_t_nodes->content)
				content_t_nodes->index = index_t_nodes->index;
			if(index_t_nodes->next == NULL)
				break ;
			index_t_nodes = index_t_nodes->next;
		}
		if(content_t_nodes->next == NULL)
			return ;
		content_t_nodes = content_t_nodes->next;
	}
}


int	main(int ac, char **av)
{
	t_node 	*stack_a;
	t_node	*sorted;
	t_node	*stack_b;
	int		i;
	int		mode;

	i = 1;
	stack_a = NULL;
	sorted = NULL;
	mode = 1;
	while (i < ac)
	{
		local_lstadd_back(&stack_a, ft_lstnew_int(ft_atoi(av[i])));
		local_lstadd_back(&sorted, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}
	indexes(&stack_a);
	mrgsort(&sorted);
	indexes(&sorted);
	con_to_index(&stack_a, &sorted);
	positions(&stack_a);
	stack_b = NULL;
	// local_lstiter(ft_lis(&stack_a, ac - 1), &ft_print_t_node);
	if (ac == 3)
		sort_two(&stack_a);
	if (ac == 4)
		sort_three(&stack_a);
	if (ac == 5)
		sort_four(&stack_a);
	if (ac == 6)
		sort_five(&stack_a);
	// if (ac > 6)
	// big_sort(&stack_a, &stack_b, t_nodes_count(&stack_a), mode);
}
