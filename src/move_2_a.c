/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:37:44 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/18 22:28:28 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	moves_2_peak(int i, int size)
{
	if (i > (size / 2))
		i = i - size;
	return (i);
}

int	arr_4_a(t_node *a, int b_data, int size)
{
	int		i;
	int		index_arr_a;
	int		index_2_peak;
	t_node	*ptr;
	t_node	*ptr2;

	ptr = a;
	ptr2 = a;
	i = 0;
	while (ptr->data < b_data && ptr != NULL)
	{
		i++;
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	if (ptr == NULL)
	{
		index_2_peak = size + 1;
		//i = 0;
		//return (i);
	}
	while (ptr != NULL)
	{
		if (ptr->data > b_data)
		{
			if (ptr->data <= ptr2->data)
			{	
				index_2_peak = i;
				ptr2 = ptr;
			}
		}
		i++;
		ptr = ptr->next;
	}
	index_arr_a = moves_2_peak(index_2_peak, size);
	return (index_arr_a);
	// if (i = size - 1)
	// {
	// 	ft_pa()
	// }
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
	i = 0;
	while (i < b_size)
	{
		arr_b[i] = moves_2_peak(i, b_size);
		i++;
	}
	i = 0;
	while (i < b_size && b_ptr != NULL)
	{
		arr_a[i] = arr_4_a(*a, b_ptr->data, a_size);
		b_ptr = b_ptr->next;
		i++;
		// printf("a :\n");
		// print_list(*a);
		// printf("b :\n");
		// print_list(*b);
	}
	
	// i = 0;
	// while (i < b_size)
	// {
	// 	printf("%d", arr_a[i]);
	// 	i++;
	// }

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
		
		// printf("\n");
		
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

// int	return_max_or_min(int cont, int *max_n_min, int size)
// {
// 	if (cont > max_n_min[0])
// 		return (max_n_min[2]);
// 	if (cont < max_n_min[1])
// 		return (max_n_min[3]);
// 	return (size + 1);
// }
/*
int	ft_max_or_min(t_node *stack_a, int cont, int size)
{
	int	max_n_min[5];

	max_n_min[0] = stack_a->data;
	max_n_min[1] = stack_a->data;
	max_n_min[2] = 0;
	max_n_min[3] = 0;
	max_n_min[4] = 1;
	while (stack_a != NULL)
	{
		if (stack_a->data >= max_n_min[0])
		{
			max_n_min[0] = stack_a->data;
			max_n_min[2] = max_n_min[4];
		}
		if (stack_a->data < max_n_min[1])
		{
			max_n_min[1] = stack_a->data;
			max_n_min[3] = max_n_min[4] - 1;
		}
		stack_a = stack_a->next;
		max_n_min[4]++;
	}
	return (return_max_or_min(cont, max_n_min, size));
}

int	arr_4_a(t_node *stack_a, int cont, int size)
{
	t_node	*tmp;
	int		i;

	tmp = stack_a;
	i = ft_max_or_min(stack_a, cont, size);
	if (i != size + 1)
		return (moves_2_peak(i, size));
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (cont < stack_a->data && cont > tmp->data)
		return (0);
	i = 1;
	while (!(cont > stack_a->data && cont < (stack_a->next)->data))
	{
		stack_a = stack_a->next;
		i++;
	}
	return (moves_2_peak(i, size));
}*/
