/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:40:45 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/18 20:36:31 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_sort
{
	int		*arr;
	int		*arr_lis;
	t_node	*ptr;
	int		i;
	int		len;
	int		len_lis;
}	t_sort;

void	get_min(t_node **stack_a, int size)
{
	int		pos;
	int		pos_min;
	int		min;
	t_node	*tmp;

	pos_min = 0;
	pos = 0;
	tmp = *stack_a;
	min = tmp->data;
	while (pos < size)
	{
		if (min > tmp->data)
		{
			min = tmp->data;
			pos_min = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	tmp = NULL;
	pos = moves_2_peak(pos_min, size);
	comb_a_moves(pos, 0, stack_a, &tmp);
}

void	sort_lis(t_node **a, t_node **b, int size)
{
	t_sort	k;

	k.i = 0;
	k.ptr = *a;
	k.arr = list_to_arr(a, size);
	k.arr_lis = lis(k.arr, size, &k.len_lis);
	k.len = 0;
	while (k.len++ < size)
	{
		if (k.i < k.len_lis && k.ptr->data == k.arr_lis[k.i])
		{
			k.ptr = k.ptr->next;
			ft_ra(a);
			k.i++;
		}
		else
		{
			k.ptr = k.ptr->next;
			ft_pb(a, b);
		}
	}
	free(k.arr_lis);
	free(k.arr);
	
	printf("a :\n");
	print_list(*a);
	printf("b :\n");
	print_list(*b);
	
	move_2_a(a, b);
	get_min(a, size);
	
	printf("a :\n");
	print_list(*a);
	printf("b :\n");
	print_list(*b);
}
