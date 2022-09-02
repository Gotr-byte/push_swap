/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 08:52:32 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/02 18:52:53 by pbiederm         ###   ########.fr       */
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

#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include "linkedlistmerge.c"

void positions(Node **stack);
void	local_lstiter(Node *lst, void (*f)(int, int, int));

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

void ft_print_node(int content, int index, int position)
{
	printf ("%d\n", content);
	printf ("%d\n", index);
	printf ("%d\n", position);
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
	
	write(1, "sa\n", 3);
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
void ft_swap_b(Node	**head)
{
	Node	*currX;
	Node	*currY;
    Node	*temp;
	
	write(1, "sb\n", 3);
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
	Node *node_to_push;
	
	if (!(*stack_a))
		return ;
	node_to_push = (*stack_a);
	(*stack_a) = (*stack_a)->next; 
	node_to_push->next = NULL;
	if (!*stack_b)
		(*stack_b) = node_to_push;
	else
	{
		node_to_push->next = (*stack_b);
		(*stack_b) = node_to_push;
	}
	node_to_push = NULL;
	write (1, "pb\n", 3);
}

void ft_push_a(Node **stack_a, Node **stack_b)
{
	Node *node_to_push;
	
	if (!(*stack_a))
		return ;
	node_to_push = (*stack_a);
	(*stack_a) = (*stack_a)->next; 
	node_to_push->next = NULL;
	if (!*stack_b)
		(*stack_b) = node_to_push;
	else
	{
		node_to_push->next = (*stack_b);
		(*stack_b) = node_to_push;
	}
	node_to_push = NULL;
	write (1, "pa\n", 3);
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

void	local_lstiter(Node *lst, void (*f)(int, int, int))
{
	Node	*point_to_shift;

	point_to_shift = lst;
	while (point_to_shift)
	{
		(*f)(point_to_shift->content, point_to_shift->index, point_to_shift->position);
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

	write(1, "ra\n", 3);
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

	write(1, "rra\n", 4);
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
		// local_lstiter(lst, &ft_print_node);
		// printf("Hi! It is all sorted :)\n");
		return ;
	}
	if (a > b)
	{
		ft_swap_a(&lst);
		// local_lstiter(lst, &ft_print_node);
		// printf("Hi! It is all sorted :)\n");
	}
}

void sort_two_b(Node **lst)
{
	Node	*point_to_shift;
	
	point_to_shift = *lst;
	int	a;
	int b;

	a = point_to_shift->content;
	// a = 0;
	point_to_shift = point_to_shift->next;
	b = point_to_shift->content;
	if (a <= b)
	{
		// local_lstiter(lst, &ft_print_node);
		// printf("Hi! It is all sorted :)\n");
		ft_swap_b(lst);
		return ;
	}
	if (a > b)
	{
		// local_lstiter(lst, &ft_print_node);
		// printf("Hi! It is all sorted :)\n");
		return ;
	}
}

void sort_three(Node **lst)
{
	Node	*point_to_shift;
	
	point_to_shift = *lst;
	int	a;
	int b;
	int c;

	a = point_to_shift->content;
	point_to_shift = point_to_shift->next;
	b = point_to_shift->content;
	point_to_shift = point_to_shift->next;
	c = point_to_shift->content;
	//1 2 3
	if (a <= b && b <= c && c >= a)
	{
		return ;
		// local_lstiter(lst, &ft_print_node);
		// printf("Hi! It is all sorted :)\n");
	}
	//1 3 2
	else if (a < b && b > c && c > a)
	{
		// ft_swap_a(&lst);
		// rot(&lst);
		
		ft_swap_a(lst);
		rot(lst);
		// local_lstiter(lst, &ft_print_node);
		// printf("Hi! It is all sorted :)\n");
	}
	//2 1 3
	else if (a > b && b < c && c > a)
	{
		// ft_swap_a(&lst);
		ft_swap_a(lst);
		// rev_rot(&lst);
		// local_lstiter(lst, &ft_print_node);
		// printf("Hi! It is all sorted :)\n");
	}
	//2 3 1
	else if (a < b && c < b && c < a)
	{
		// rev_rot(&lst);
		rev_rot(lst);
		
		// local_lstiter(lst, &ft_print_node);
		// printf("Hi! It is all sorted :)\n");
	}
	//3 1 2 
	else if (a > b && b < c && c < a)
	{
		// rot(&lst);
		rot(lst);
		// printf("Hi! It is all sorted :)\n");
	}
	// 3 2 1
	else if (a > b && b > c && c < a)
	{
		// ft_swap_a(&lst);
		// rev_rot(&lst);
		ft_swap_a(lst);
		rev_rot(lst);
		// local_lstiter(lst, &ft_print_node);
		// printf("Hi! It is all sorted :)\n");
	}

}

void sort_four(Node **lst)
{
	Node *stack_a;
	Node *stack_b;

	stack_a = *lst;
	stack_b = NULL;
	if (stack_a->index == 4)
	{
		ft_push_b(&stack_a, &stack_b);
		sort_three(&stack_a);
		ft_push_a(&stack_b, &stack_a);
		rot(&stack_a);
		// printf("stack a\n");
		// local_lstiter(stack_a, &ft_print_node);
		// printf("stack_b\n");
		// local_lstiter(stack_b, &ft_print_node);
		return ;
	}
	else if (stack_a->index == 2)
	{
		ft_push_b(&stack_a, &stack_b);
		sort_three(&stack_a);
		ft_push_a(&stack_b, &stack_a);
		ft_swap_a(&stack_a);
		// printf("stack a\n");
		// local_lstiter(stack_a, &ft_print_node);
		// printf("stack_b\n");
		// local_lstiter(stack_b, &ft_print_node);
		return ;
	}
	else if (stack_a->index == 3)
	{
		ft_push_b(&stack_a, &stack_b);
		sort_three(&stack_a);
		rev_rot(&stack_a);
		ft_push_a(&stack_b, &stack_a);
		rot(&stack_a);
		rot(&stack_a);
		// printf("stack a\n");
		// local_lstiter(stack_a, &ft_print_node);
		// printf("stack_b\n");
		// local_lstiter(stack_b, &ft_print_node);
		return ;
	}
	else if (stack_a->index == 1)
	{
		ft_push_b(&stack_a, &stack_b);
		sort_three(&stack_a);
		ft_push_a(&stack_b, &stack_a);
		// printf("stack a\n");
		// local_lstiter(stack_a, &ft_print_node);
		// printf("stack_b\n");
		// local_lstiter(stack_b, &ft_print_node);
		return ;
	}
}
//while each pair of elements is sorted the stack is sorted
int	find_pos_one(Node **lst)
{
	Node	*stack_a;

	stack_a = *lst;
	while(1)
	{	
		if(stack_a->index == 1)
			return(stack_a->position);
		if(stack_a->next == NULL)
			return(-1);
		stack_a = stack_a->next;
	}
}

int	find_pos_two(Node **lst)
{
	Node	*stack_a;

	stack_a = *lst;
	while(1)
	{	
		if(stack_a->index == 2)
			return(stack_a->position);
		if(stack_a->next == NULL)
			return(-1);
		stack_a = stack_a->next;
	}
}

void sort_five(Node **lst)
{
	Node *stack_a;
	Node *stack_b;
	int  sent;

	sent = 2;
	stack_a = *lst;
	stack_b = NULL;
	
	while(1)
	{
		if(sent == 0)
			break ;
		if(stack_a->index == 1)
			{
				ft_push_b(&stack_a, &stack_b);
				sent--;
			}
		if(sent == 1)
			if (stack_a->index == 2)
			{
				ft_push_b(&stack_a, &stack_b);
				sent--;
			}
		if (find_pos_one(&stack_a) < 4 && find_pos_one(&stack_a) > 0)
			{
				rot(&stack_a);
				positions(&stack_a);	
			}
		else if (find_pos_one(&stack_a) >= 4 && find_pos_one(&stack_a) > 0)
			{
				rev_rot(&stack_a);
				positions(&stack_a);	
			}
		if (find_pos_two(&stack_a) < 4 && find_pos_one(&stack_a) < 0)
			{
				rot(&stack_a);
				positions(&stack_a);
			}
		else if (find_pos_two(&stack_a) >= 4 && find_pos_one(&stack_a) < 0)
			{
				rev_rot(&stack_a);
				positions(&stack_a);
			}
	}
	sort_three(&stack_a);
	ft_push_a(&stack_b, &stack_a);
	ft_push_a(&stack_b, &stack_a);	
}
// sort four can use the indexing for the first element which would be pushed to b then
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

void indexes(Node **stack)
{
	Node *stack_index;
	int 	i;
	
	stack_index = *stack;
	i = 1;
	while (1)
	{
		stack_index->index = i;
		i++;
		if(stack_index->next == NULL)
			break ;
		stack_index = stack_index->next;
	}
}

void positions(Node **stack)
{
	Node *stack_index;
	int 	i;
	
	stack_index = *stack;
	i = 1;
	while (1)
	{
		stack_index->position = i;
		i++;
		if(stack_index->next == NULL)
			break ;
		stack_index = stack_index->next;
	}
}

void con_to_index(Node **lst_con, Node **lst_i)
{
	Node	*index_nodes;
	Node	*content_nodes;

	index_nodes = *lst_i;
	content_nodes = *lst_con;
	while (1)
	{
		index_nodes = *lst_i;
		while (1)
		{
			if(content_nodes->content == index_nodes->content)
				content_nodes->index = index_nodes->index;
			if(index_nodes->next == NULL)
				break ;
			index_nodes = index_nodes->next;
		}
		if(content_nodes->next == NULL)
			return ;
		content_nodes = content_nodes->next;
	}
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
				//subs++ the subsequence should increment
				//managing the chonks
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
	Node	*sorted;
	int		i;

	// write (1, "toto", 4);
	// return (0);
	i = 1;
	stack_a = NULL;
	sorted = NULL;
	while (i < ac)
	{
		local_lstadd_back(&stack_a, ft_lstnew_int(ft_atoi(av[i])));
		local_lstadd_back(&sorted, ft_lstnew_int(ft_atoi(av[i])));
		i++;
	}
	indexes(&stack_a);
	MergeSort(&sorted);
	indexes(&sorted);
	con_to_index(&stack_a, &sorted);
	positions(&stack_a);
	//printf("The stack is: %s \n", is_sorted(&stack_a));
	// local_lstiter(insert(stack_a, 11), &ft_print_node);

	// local_lstiter(ft_lis(&stack_a, ac - 1), &ft_print_node);
	if (ac == 3)
		sort_two(stack_a);
	if (ac == 4)
		sort_three(&stack_a);
	if (ac == 5)
		sort_four(&stack_a);
	if (ac == 6)
		sort_five(&stack_a);
	// local_lstiter(stack_a, &ft_print_node);
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

