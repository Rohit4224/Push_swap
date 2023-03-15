/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:27:24 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/15 21:05:52 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back01(t_node **alst, t_node *new)
{
	t_node	*tmp;

	if (!alst)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}


int	my_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

int	is_sorted(t_node **head)
{
	t_node	*ptr;

	ptr = *head;
	while (ptr && ptr->next)
	{
		if (ptr->data > ptr->next->data)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

// Prints the Linked List
/*
void	print_list(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->data, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}*/

int	lowest_n(t_node *head)
{
	int		val;
	t_node	*ptr2;

	ptr2 = head;
	val = INT_MAX;
	while (ptr2 != NULL)
	{
		if (ptr2->data < val)
			val = ptr2->data;
		ptr2 = ptr2->next;
	}
	return (val);
}

void	point_head_to_min(t_node **head, int val)
{
	t_node	*list;

	list = *head;
	while (list->data != val)
	{
		ft_rra(head);
		list = *head;
	}
}

