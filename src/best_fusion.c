/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_fusion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:59:40 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/18 20:36:33 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	continue_best_fusion(int *arr_a, int *arr_b, int *arr_c, int size)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (i < size)
	{
		if (arr_c[i] < arr_c[pos])
			pos = i;
		i++;
	}
	free(arr_c);
	free(arr_b);
	free(arr_a);
	return (pos);
}

int	best_fusion(int *arr_a, int *arr_b, int size)
{
	int	*arr_c;
	int	i;

	i = 0;
	arr_c = (int *) malloc(sizeof(int) * size);
	if (arr_c == 0 || arr_a == 0 || arr_b == 0)
		error_malloc();
	while (i < size)
	{
		if ((arr_a[i] < 0 && arr_b[i] < 0)
			|| (arr_a[i] > 0 && arr_b[i] > 0))
			arr_c[i] = max_nbr(arr_a[i], arr_b[i]);
		else
		{
			if (arr_a[i] < 0)
				arr_a[i] *= -1;
			if (arr_b[i] < 0)
				arr_b[i] *= -1;
			arr_c[i] = arr_a[i] + arr_b[i];
		}
		i++;
	}
	return (continue_best_fusion(arr_a, arr_b, arr_c, size));
}

int	comb_a_moves(int a, int b, t_node **a_stack, t_node **b_stack)
{
	while (a < 0 && b < 0)
	{
		ft_rrr(a_stack, b_stack);
		a++;
		b++;
	}
	while (a > 0 && b > 0)
	{
		ft_rr(a_stack, b_stack);
		a--;
		b--;
	}
	if (a < 0)
		while (a++ < 0)
			ft_rra(a_stack);
	else if (a > 0)
		while (a-- > 0)
			ft_ra(a_stack);
	return (b);
}
