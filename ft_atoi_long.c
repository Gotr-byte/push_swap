/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:51:45 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/21 10:52:44 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_wh_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	' || str[i] == '\t' \
	|| str[i] == '\n' || str[i] == '\v' \
	|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

long int	ft_atoi_long(const char *str)
{
	long int	val[4];

	val[0] = ft_wh_space((char *)str);
	val[1] = 0;
	val[2] = 1;
	val[3] = 0;
	if (str[val[0]] == '-')
		val[2] = -1;
	if (str[val[0]] == '-' || str[val[0]] == '+')
	{
		val[0]++;
		if (str[val[0] + 1] == '-' || str[val[0] + 1] == '+')
			return (0);
	}
	while (((*(str + val[0])) >= 48) && ((*(str + val[0])) <= 57))
	{
		val[1] = 10 * val[1] + (int)(*(str + val[0]) - 48);
		val[3] = 1;
		val[0]++;
	}
	if (val[3] != 0)
		return (val[2] * val[1]);
	return (0);
}