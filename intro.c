/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/24 11:31:28 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstmap
// Prototype Node *ft_lstmap(Node *lst, void *(*f)(void *),
// void (*del)(void *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.
// del: The address of the function used to delete
// the content of a node if needed.
// Return value The new list.
// NULL if the allocation fails.
// External functs. malloc, free
// Description Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.
// for some reason segfaults with 0 as input


#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void ft_print_node(int content)
{
	printf ("%d\n", content);
}

void delete (char * content)
{
	printf("The following content has been deleted: %s", content);
}

void del_pos(Node **head, int position)
{
	Node	*current;
	Node	*previous;

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

void ft_swap_a(Node	**head)
{
	Node	*currX;
	Node	*currY;
    Node	*temp;
	
	printf("Swapped list a\n");
	currX = *head;
	currY = *head;
    if (currX == NULL || currY == NULL || currY->next == NULL || currX->next == NULL)
        return;
    currY = currY->next;
	temp = currY->next;
    currY->next = currX;
    currX->next = temp;
	*head = currY;
}

void	local_lstadd_back(Node **lst, Node *new)
{
	Node	*last;

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

void	loc_lstadd_front(Node **lst, Node *new)
{
	new->next = *lst;
	*lst = new;
}

void ft_push_b(Node **stack_a, Node **stack_b)
{
	Node	*tmp;
	Node	*traverse;
	
	if (*stack_a == NULL)
		return ;
	tmp = *stack_a;
	traverse = *stack_a;
	traverse = traverse->next;
	*stack_a = traverse;
	tmp->next = NULL;
	local_lstadd_back(stack_b, tmp);
}



Node	*ft_lstnew_int(int content)
{
	Node	*tmp;

	tmp = (Node *)malloc(sizeof(Node));
	if (!tmp)
		return (NULL);
	// if (!content)
	// {
	// 	free(tmp);
	// 	return(NULL);
	// }
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}


void	local_lstiter(Node *lst, void (*f)(int))
{
	Node	*point_to_shift;

	point_to_shift = lst;
	while (point_to_shift)
	{
		(*f)(point_to_shift->content);
		point_to_shift = point_to_shift->next;
	}
}

Node	*local_lstlast(Node *lst)
{
	Node	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

Node	*local_lst_bef_last(Node *lst)
{
	Node	*tmp;
	Node	*tmp_bef;
	
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


void rot(Node **head)
{
	Node	*prev;
	Node	*curr;
	Node	*traverse;

	prev = *head;
	curr = *head;
	traverse = *head;
	traverse = traverse->next;
	prev = local_lstlast(prev);
	prev->next = curr;
	curr->next = NULL;
	*head = traverse;
}

void rev_rot(Node **head)
{
	Node	*prev;
	Node	*curr;
	Node	*traverse;

	printf("rra\n");
	prev = *head;
	curr = *head;
	traverse = *head;
	traverse = local_lstlast(traverse);
	prev = local_lst_bef_last(prev);
	prev->next = NULL;
	traverse->next = curr;
	*head = traverse;
}
void sort_two(Node *lst)
{
	Node	*point_to_shift;
	
	point_to_shift = lst;
	int	a;
	int b;

	a = point_to_shift->content;
	// a = 0;
	point_to_shift = point_to_shift->next;
	b = point_to_shift->content;
	if (a <= b)
	{
		local_lstiter(lst, &ft_print_node);
		printf("Hi! It is all sorted :)\n");
	}
	if (a > b)
	{
		ft_swap_a(&lst);
		printf("Swapped list a\n");
		local_lstiter(lst, &ft_print_node);
		printf("Hi! It is all sorted :)\n");
	}
}

void sort_three(Node *lst)
{
	Node	*point_to_shift;
	
	point_to_shift = lst;
	int	a;
	int b;
	int c;

	a = point_to_shift->content;
	point_to_shift = point_to_shift->next;
	b = point_to_shift->content;
	point_to_shift = point_to_shift->next;
	c = point_to_shift->content;
	if (a <= b && b <= c && c >= a)
	{
		local_lstiter(lst, &ft_print_node);
		printf("Hi! It is all sorted :)\n");
	}
	else if (a < b && b > c && c >a)
	{
		ft_swap_a(&lst);
		rot(&lst);
		local_lstiter(lst, &ft_print_node);
		printf("Hi! It is all sorted :)\n");
	}
	else if (a > b && b < c && c > a)
	{
		ft_swap_a(&lst);
		local_lstiter(lst, &ft_print_node);
		printf("Hi! It is all sorted :)\n");
	}
	else if (a < b && c < b && c < a)
	{
		rev_rot(&lst);
		local_lstiter(lst, &ft_print_node);
		printf("Hi! It is all sorted :)\n");
	}
	else if (a > b && b < c && c < a)
	{
		rot(&lst);
		local_lstiter(lst, &ft_print_node);
		printf("Hi! It is all sorted :)\n");
	}
	else if (a > b && b > c && c < a)
	{
		ft_swap_a(&lst);
		rev_rot(&lst);
		local_lstiter(lst, &ft_print_node);
		printf("Hi! It is all sorted :)\n");
	}

}

// void is_sorted(Node **stack)
// {
		// Node	*i;
		// Node	*j;

// }


int	main(int ac, char **av)
{
	if (ac > 1)
	{
	Node 	*stack_a;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		// printf("%d", ft_atoi(av[i]));
		// break;
		local_lstadd_back(&stack_a, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}
	if (ac == 3)
		sort_two(stack_a);
	if (ac == 4)
		sort_three(stack_a);
	// printf("Before rrot_a:\n");
	// local_lstiter(stack_a, &ft_print_node);
	// rev_rot(&stack_a);
	// printf("After rrot_a:\n");
	// local_lstiter(stack_a, &ft_print_node);
	}
	else
	{
		printf("Wrong input");
		return(2);
	}
}

