/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rr_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:58 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/20 15:18:01 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_ra(t_node **a)
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
}

void	checker_rb(t_node **b)
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
}

void	checker_rr(t_node **a, t_node **b)
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
}
