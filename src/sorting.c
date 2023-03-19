/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:04:58 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/19 18:00:15 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	continue_3(t_node **a, t_node *ptr, t_node *ptr2, t_node *ptr3)
{
	if (ptr->data > ptr2->data && ptr2->data > ptr3->data)
	{
		ft_rra(a);
		ft_sa(a);
		ft_ra(a);
	}
	if (ptr->data < ptr2->data && ptr2->data > ptr3->data)
	{
		if (ptr3->data < ptr->data)
			ft_rra(a);
		else if (ptr3->data > ptr->data)
		{
			ft_rra(a);
			ft_sa(a);
		}
	}
}

void	sort_3(t_node **a)
{
	t_node	*ptr;
	t_node	*ptr2;
	t_node	*ptr3;

	ptr = *a;
	ptr2 = (*a)->next;
	ptr3 = (*a)->next->next;
	if (ptr->data > ptr2->data && ptr2->data < ptr3->data)
	{
		if (ptr3->data < ptr->data)
		{
			ft_rra(a);
			ft_rra(a);
		}
		else
			ft_sa(a);
	}
	continue_3(a, ptr, ptr2, ptr3);
}

void	sort_4(t_node **a, t_node **b)
{
	int		min;

	min = lowest_n(*a);
	point_head_to_min(a, min);
	check_order(a);
	ft_pb(a, b);
	sort_3(a);
	ft_pa(b, a);
	check_order(a);
}

void	sort_5(t_node **a, t_node **b)
{
	int		min;

	min = lowest_n(*a);
	point_head_to_min(a, min);
	check_order(a);
	ft_pb(a, b);
	min = lowest_n(*a);
	point_head_to_min(a, min);
	ft_pb(a, b);
	sort_3(a);
	ft_pa(b, a);
	ft_pa(b, a);
	check_order(a);
}

void	sorting(t_node **a, t_node **b)
{
	int		size;
	t_node	*ptr;

	ptr = *a;
	size = ft_lstsize01(ptr);
	if (size == 3)
		sort_3(a);
	check_order(a);
	if (size == 4)
		sort_4(a, b);
	if (size == 5)
		sort_5(a, b);
	if (size > 5)
	{
		sort_lis(a, b, size);
	}
}
