/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_4_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:10:36 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/23 16:19:05 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lowest_number(t_node *a, int size, int index_2_peak)
{
	int		i;
	t_node	*ptr;
	int		lowest_num;

	i = 0;
	ptr = a;
	lowest_num = lowest_n(ptr);
	ptr = a;
	while (ptr != NULL && i < size)
	{
		if (ptr->data == lowest_num)
		{
			index_2_peak = i;
		}
		i++;
		ptr = ptr->next;
	}
	return (index_2_peak);
}

int	to_find_index_2_peak(t_node *ptr, t_node *ptr2, int i, int b_data)
{
	int	index_2_peak;

	index_2_peak = 0;
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
	return (index_2_peak);
}

// array for a, trovare appena maggiore di b_data

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
	index_2_peak = 0;
	while (ptr != NULL && ptr->data < b_data)
	{
		i++;
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	if (ptr == NULL)
		index_2_peak = lowest_number(a, size, index_2_peak);
	if (ptr != NULL)
		index_2_peak = to_find_index_2_peak(ptr, ptr2, i, b_data);
	index_arr_a = moves_2_peak(index_2_peak, size);
	return (index_arr_a);
}
