/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rr_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:58 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/21 19:18:22 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_ra(t_node **a)
{
	t_node	*ptr;
	t_node	*ptr2;

	if (*a == NULL || (*a)->next == NULL)
		return ;
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

	if (*b == NULL || (*b)->next == NULL)
		return ;
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

	if (*a == NULL || (*a)->next == NULL)
		return ;
	ptr = *a;
	ptr2 = *a;
	while (ptr2->next != NULL)
	{
		ptr2 = ptr2->next;
	}
	ptr2->next = ptr;
	*a = (*a)->next;
	ptr->next = NULL;
	if (*b == NULL || (*b)->next == NULL)
		return ;
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
