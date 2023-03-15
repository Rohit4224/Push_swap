/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:15:04 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/15 17:37:11 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_rra(t_node **a)
{
	t_node	*ptr;
	t_node	*ptr2;

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
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_node **b)
{
	t_node	*ptr;
	t_node	*ptr2;

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
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_node **a, t_node **b)
{
	t_node	*ptr;
	t_node	*ptr2;

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
	ft_putstr_fd("rrr\n", 1);
}
