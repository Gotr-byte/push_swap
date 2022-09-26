/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:00:26 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/26 18:20:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_flag(char **av)
{
	int	sort_flag;
	int	i;

	sort_flag = 1;
	if (!av)
		return (sort_flag);
	i = 2;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= ft_atoi(av[i - 1]))
			sort_flag = 0;
		i++;
	}
	return (sort_flag);
}
