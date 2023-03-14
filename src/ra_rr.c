/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:09:46 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/14 19:56:24 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
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
	ft_putstr("ra\n");
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
	ft_putstr("rb\n");
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
	ft_putstr("rr\n");
}
