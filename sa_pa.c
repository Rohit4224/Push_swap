/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:01:52 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/14 19:56:22 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ft_sa(t_node **a)
{
	t_node	*ptr;
	t_node	*ptr2;

	ptr = *a;
	ptr2 = ptr->next;
	*a = ptr2;
	ptr->next = ptr2->next;
	ptr2->next = ptr;
	ft_putstr("sa\n");
	return ;
}

void	ft_sb(t_node **b)
{
	t_node	*p;
	t_node	*p2;

	p = *b;
	p2 = p->next;
	*b = p2;
	p->next = p2->next;
	p2->next = p;
	ft_putstr("sb\n");
}

void	ft_ss(t_node **a, t_node **b)
{
	t_node	*a01;
	t_node	*a02;
	t_node	*b01;
	t_node	*b02;

	a01 = *a;
	b01 = *b;
	a02 = a01->next;
	b02 = b01->next;
	*a = a01->next;
	*b = b01->next;
	a01->next = a02->next;
	b01->next = b02->next;
	a02->next = a01;
	b02->next = b01;
	ft_putstr("ss\n");
	return ;
}

// b to a

void	ft_pa(t_node **b, t_node **a)
{
	t_node	*ptr;

	if (*b == NULL)
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = *a;
	*a = ptr;
	ft_putstr("pa\n");
	return ;
}

// a to b 

void	ft_pb(t_node **a, t_node **b)
{
	t_node	*ptr;

	if (*a == NULL)
		return ;
	ptr = *a;
	*a = (*a)->next;
	ptr->next = *b;
	*b = ptr;
	ft_putstr("pb\n");
	return ;
}
