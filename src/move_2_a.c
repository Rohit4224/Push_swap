/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:37:44 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/19 19:14:27 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_2_peak(int i, int size)
{
	if (i > (size / 2))
		i = i - size;
	return (i);
}

int	remaining_b(t_node **b, int b_size, t_node **a, int a_size)
{
	int		*arr_a;
	int		*arr_b;
	t_node	*b_ptr;
	int		i;

	arr_a = malloc(sizeof(int) * b_size);
	arr_b = malloc(sizeof(int) * b_size);
	b_ptr = *b;
	i = -1;
	while (++i < b_size)
		arr_b[i] = moves_2_peak(i, b_size);
	i = -1;
	while (++i < b_size && b_ptr != NULL)
	{
		arr_a[i] = arr_4_a(*a, b_ptr->data, a_size);
		b_ptr = b_ptr->next;
	}
	i = best_fusion(cpy_arr(arr_a, b_size),
			cpy_arr(arr_b, b_size), b_size);
	i = comb_a_moves(arr_a[i], arr_b[i], a, b);
	free(arr_a);
	free(arr_b);
	return (i);
}

void	move_2_a(t_node **a, t_node **b)
{
	int	left_b_index;
	int	a_size;
	int	b_size;

	left_b_index = 0;
	a_size = ft_lstsize01(*a);
	b_size = ft_lstsize01(*b);
	while (*b != NULL)
	{
		left_b_index = remaining_b(b, b_size, a, a_size);
		if (left_b_index < 0)
			while (left_b_index++ < 0)
				ft_rrb(b);
		else if (left_b_index > 0)
			while (left_b_index-- > 0)
				ft_rb(b);
		ft_pa(b, a);
		a_size++;
		b_size--;
	}
}
