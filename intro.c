/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/07 20:45:22 by pbiederm         ###   ########.fr       */
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

void ft_print_node(void	*content)
{
	printf ("%s\n", content);
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
	t_list	*tmp;
	t_list	*curr;
	if(*head == NULL || curr->next == NULL)
		printf("Lists are empty");
	curr = *head->next;
	tmp = *head->next;
	*head->next = curr->next;
	curr->next = tmp;
}

#include "./libft/libft.h"
int	main(void)
{
	t_list	*ptr;
	t_list 	*head;
	t_list 	*first;
	t_list 	*second;
	t_list 	*second_head;
	t_list 	*third;
	t_list	*tmp;
	int 	position;

	head = ft_lstnew("1\n");
	first = ft_lstnew("2\n");
	ft_lstadd_back (&head, first);
	second = ft_lstnew("3\n");
	ft_lstadd_back (&head, second);
	second_head = ft_lstnew("4\n");
	ft_lstadd_front (&head, second_head);
	third = ft_lstnew("5\n");
	ft_lstadd_back(&second_head, third);
	printf ("Before deletion: \n");
	ft_lstiter(head, &ft_print_node);
	position = 1;
	del_pos(&head, position);
	ptr = second_head;
	printf ("After deletion: \n");
	ft_lstiter(head, &ft_print_node);
	ft_swap_a(&head);
	printf ("After swap a: \n");
}