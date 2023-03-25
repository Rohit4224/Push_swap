/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrr_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:18:06 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/25 16:44:45 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	checker_rra(t_node **a)
{
	t_node	*ptr;
	t_node	*ptr2;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	ptr = *a;
	ptr2 = (*a)->next;
	while (ptr2->next != NULL)
	{
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	ptr2->next = *a;
	*a = ptr2;
	ptr->next = NULL;
}

void	checker_rrb(t_node **b)
{
	t_node	*ptr;
	t_node	*ptr2;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	ptr = *b;
	ptr2 = (*b)->next;
	while (ptr2->next != NULL)
	{
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	ptr2->next = *b;
	*b = ptr2;
	ptr->next = NULL;
}

void	checker_rrr(t_node **a, t_node **b)
{
	t_node	*ptr;
	t_node	*ptr2;

	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		return ;
	ptr = *a;
	ptr2 = (*a)->next;
	while (ptr2->next != NULL)
	{
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	ptr2->next = *a;
	*a = ptr2;
	ptr->next = NULL;
	ptr = *b;
	ptr2 = (*b)->next;
	while (ptr2->next != NULL)
	{
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	ptr2->next = *b;
	*b = ptr2;
	ptr->next = NULL;
}
