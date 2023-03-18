/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:09:46 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/18 15:04:35 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_node **a)
{
	t_node	*ptr;
	t_node	*ptr2;

	ptr = *a;
	ptr2 = *a;
	while (ptr2->next != NULL)
	{
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr;
	*a = (*a)->next;
	ptr->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_node **b)
{
	t_node	*ptr;
	t_node	*ptr2;

	ptr = *b;
	ptr2 = *b;
	*b = (*b)->next;
	while (ptr2->next != NULL)
	{
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr;
	ptr->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_node **a, t_node **b)
{
	t_node	*ptr;
	t_node	*ptr2;

	ptr = *a;
	ptr2 = *a;
	while (ptr2->next != NULL)
	{
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr;
	*a = (*a)->next;
	ptr->next = NULL;
	ptr = *b;
	ptr2 = *b;
	*b = (*b)->next;
	while (ptr2->next != NULL)
	{
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr;
	ptr->next = NULL;
	ft_putstr_fd("rr\n", 1);
}
