/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:38:15 by pbiederm          #+#    #+#             */
/*   Updated: 2022/08/24 11:38:15 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"

int *ft_lis (int arr[], int n)
{
    int *lis;
    int i;
    int    j;

    lis = (int*)malloc (sizeof(int)*n);

    // Initialises LIS values for all indexes
    i = 0;

    while (i < n)
    {
        lis[i] = 1;
        i++;
    }

    j = 0;
    i = 1;

    while (i < n)
    {
        while (j < i)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
            j++;
        }
        i++;
    }
    return (lis);
}

int *ft_lis (int arr[], int n)
{
    int *lis;
    int i;
    int    j;

    lis = (int*)malloc (sizeof(int)*n);

    // Initialises LIS values for all indexes
    i = 0;

    while (i < n)
    {
        lis[i] = 1;
        i++;
    }

    j = 0;
    i = 1;

    while (i < n)
    {
        while (j < i)
        {
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
            j++;
        }
        i++;
    }
    return (lis);
}

int main(void)
{
    int arr[15];
    int i;
    int *lis;
    i = 0;
    
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 5;
    arr[4] = 3;
    arr[5] = 2;
    arr[6] = 6;
    arr[7] = 7;
    arr[8] = 8;
    arr[9] = 9;
    arr[10]= 10;
    arr[11] = 11;
    arr[12] = 12;
    arr[13] = 14;
    arr[14] = 15;

    lis = ft_lis(arr, 15);

    while (i < 15)
    {
        printf("%d", lis[i]);
        i++;
    }

    return(0);
}