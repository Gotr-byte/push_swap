/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/30 10:00:13 by pbiederm         ###   ########.fr       */
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
// 


#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

Node * insert(Node *head, int data)
{
	Node* temp;
	Node *newP;
	int key;
	
	newP = malloc(sizeof(Node));
	newP->content = data;
	newP->next= NULL;
	key = data;	
	
	if (head == NULL || key < head->content)
	{
		newP->next = head;
		head = newP;
	}
	else
	{
		temp = head;
		while (temp->next != NULL && temp->next->content < key)
		{
			temp = temp->next;
		}
		newP->next = temp->next;
		temp->next = newP;
	}
	return (head);
}

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

	// tmp = (Node*)malloc(sizeof(Node));
	tmp = (Node*)malloc(sizeof(tmp));
	if (!tmp)
		return (NULL);
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

//while each pair of elements is sorted the stack is sorted

char *is_sorted(Node **stack)
{
	Node	*i;
	Node	*j;
	char*	sort_flag;
	
	sort_flag = "sorted";
	i = (*stack);
	j = (*stack);
	j = j->next;
	
	while (1)
	{
		if(j->content == i->content)
		{
			sort_flag = "equals";
			break ;
		}
		if(j->content < i->content)
			sort_flag = "unsorted";
		if(j->next == NULL)
			break ;
		j = j->next;
		i = i->next;
	}
	return(sort_flag);	
}

// Node *ft_lis (int n)
Node *ft_lis (Node** lst, int n)
{
	Node 	*lis;
	Node	*first;
	Node	*second;
	Node	*traverse;
	Node	*traverse_next;
    int i;
	int j;

    i = 0;

	// lis->content = 1;
	lis = NULL;
	while (i < n)
		{
			local_lstadd_back(&lis, ft_lstnew_int(1));
			i++;
		}

	first = *lst;
	second = *lst;
	second = second->next;
	traverse = lis;
	traverse_next = lis;
	traverse_next = traverse_next->next;
    j = 0;
    i = 1;

    while (i < n)
    {
	j = 0;
	first = *lst;
	traverse = lis;
	
        while (j < i)
        {
            if((second->content > first->content) && (traverse_next->content < traverse->content + 1))
            {
				traverse_next->content = traverse->content + 1;
            }
			first = first->next;
			traverse = traverse->next;
            j++;
        }
			second = second->next;
			traverse_next = traverse_next->next;
        	i++;
    }
	return (lis);
}

int	main(int ac, char **av)
// int main(void)
{
	// if (ac > 1)
	// {
	Node 	*stack_a;
	int		i;

	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		local_lstadd_back(&stack_a, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}
	printf("The stack is: %s \n", is_sorted(&stack_a));
	// local_lstiter(insert(stack_a, 11), &ft_print_node);

	// local_lstiter(ft_lis(&stack_a, ac - 1), &ft_print_node);
	// if (ac == 3)
	// 	sort_two(stack_a);
	// if (ac == 4)
	// 	sort_three(stack_a);
	// printf("Before rrot_a:\n");
	// local_lstiter(stack_a, &ft_print_node);
	// rev_rot(&stack_a);
	// printf("After rrot_a:\n");
	// local_lstiter(stack_a, &ft_print_node);
	// }
	// else
	// {
	// 	printf("Wrong input");
	// 	return(2);
	// }
}

