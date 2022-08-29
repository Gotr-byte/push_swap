/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:43:01 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/29 16:43:01 by pbiederm         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#include <stdio.h>

// [38, 27 ,43, 3, 9, 82, 10]
// 	/				\
// [38, 27, 43, 3] 	[9, 82, 10]
// 	/		|			|		\
// [38, 27]	[43, 3]	[9, 82]	 	[10]
// /		|	|	\	|	\		|
// [38]	[27][43][30][9][82]		[10]
// \		|	\	/	\	/		|
// [27, 38]	[30, 43][9, 82]		[10]
// 	\			/		\		/
// [27, 30, 38, 43]	[9, 10, 82]
// 		\				/
// [9, 10, 27, 30, 38, 43, 82]

void merge_sort(int a[], int lenght);
void merge_sort_recursion(int a[], int l, int r);
void merge_sorted_arrays(int a[], int l, int m, int r);
int main()
{
	int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
	int lenght = 10;
	merge_sort(array, lenght);
	for (int i = 0; i < lenght; i++)
		printf( "%d", array[i]);
	printf("\n");
}	


void merge_sort(int a[], int lenght)
{
	merge_sort_recursion(a, 0, lenght - 1);
}
void merge_sort_recursion(int a[], int l, int r)
{
	int m;
	if ( l< r)
	{
	m = 1 + (r - 1) / 2;

	merge_sort_recursion(a, l, m);
	merge_sort_recursion(a, m + 1, r);
	merge_sorted_arrays(a, l, m, r);
	}
}


void merge_sorted_arrays(int a[], int l, int m, int r)
{
	int left_lenght = m - 1 + 1;
	int right_lenght = r - m;
	int temp_left[left_lenght];
	int temp_right[right_lenght];

	int i ,j ,k;

	for (int i = 0; i < left_lenght; i++)
		temp_left[i] = a[l + i];
	for (int i = 0; i < right_lenght; i++)
		temp_right[i] = a[m + 1 + i];
	for (i = 0, j = 0, k = l; k <= r; k++)
	{
		if((i < left_lenght) && (j >= right_lenght) || temp_left[i] <= temp_right[j])
		{
			a[k] = temp_left[i];
			i++;
		}
		else
		{
			a[k] = temp_right[j];
			j++;
		}
	}
}
