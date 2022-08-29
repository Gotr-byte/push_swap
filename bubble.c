/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:10:05 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/29 14:10:05 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void bubble_sort(int a[], int lenght)
{
	int i;
	int j;
	int temp;
	int swapped = 0;
	do
	{
		swapped = 0;
	for(i = 0; i <lenght; i++)
	{
		for(int j = 0; j < (lenght - 1 - i); j++)
		{
			if (a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				swapped = 1;
			}
		}
	}}while(swapped);
}

int main(void)
{
	int a[] = {7, 1, 3, 9, 0, 2, 4, 5, 8, 6};

	int lenght;
	lenght = 10;

	bubble_sort(a, 10);
	for (int i = 0; i < lenght; i++)
		printf("a[%d] = %d\n", i, a[i]);
	return 0;
}