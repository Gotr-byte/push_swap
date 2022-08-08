/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/08 15:52:44 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Function name ft_lstmap
// Prototype t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
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

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void ft_print_node(int content)
{
	printf ("%d\n", content);
}

void delete (void * content)
{
	printf("The following content has been deleted: %s", content);
}

void del_pos(t_list **head, int position)
{
	t_list	*current;
	t_list	*previous;

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
// swap first two positions of a linked list
void ft_swap_a(t_list	**head)
{
	t_list	*currX;
	t_list	*currY;
    t_list	*temp;
	
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

// void ft_push_b(t_list **stack_a, t_list **stack_b)
// {
// 	// pushes the first element from stack a to stack b
// 	// if stack b doesnt exits create stack_b
// 	// creates copy in stack b and links it accordingly
// 	// deletes node in stack a
// 	t_list new_node;

// 	new_node = *stack_a;
// 	// stack_b = NULL;

// }

t_list	*ft_lstnew_int(int content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	if (!content)
	{
		free(tmp);
		return(NULL);
	}
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}


int	main(int ac, char **av)
{
	if (ac > 2)
	{
	// t_list	*ptr;
	t_list 	*head;
	// t_list 	*first;
	// t_list 	*second;
	// t_list 	*second_head;
	// t_list 	*third;
	// int 	position;
	int		i;

	i = 1;
	head = NULL;
	while (i < ac)
	{
		ft_lstadd_back(&head, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}

	// head = ft_lstnew("1\n");
	// first = ft_lstnew("2\n");
	// ft_lstadd_back (&head, first);
	// second = ft_lstnew("3\n");
	// ft_lstadd_back (&head, second);
	// second_head = ft_lstnew("4\n");
	// ft_lstadd_front (&head, second_head);
	// third = ft_lstnew("5\n");
	// ft_lstadd_back(&second_head, third);
	// printf ("Before deletion: \n");
	// ft_lstiter(head, &ft_print_node);
	// position = 1;
	// del_pos(&head, position);
	// ptr = second_head;
	// printf ("After deletion: \n");
	// ft_lstiter(head, &ft_print_node);
	// ft_swap_a(&head);
	// printf ("After swap a: \n");
	ft_lstiter(head, &ft_print_node);
	}
	else
	{
		printf("Wrong input");
		return(2);
	}
}

