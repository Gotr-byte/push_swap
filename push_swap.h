/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:55:43 by pbiederm          #+#    #+#             */
/*   Updated: 2022/09/16 12:43:05 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
typedef struct Nodes
{
	int				content;
	int				index;
	int				position;
	int				chonk_size;
	int				new_chonk_size;
	struct Nodes	*next;
}	Node;
#endif