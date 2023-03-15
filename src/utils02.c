/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:27:24 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/14 19:52:19 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
void	printList(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}

t_node	*lowest_n(t_node **head)
{
	t_node	*ptr;
	t_node	*ptr2;

	ptr = *head;
	ptr2 = (*head)->next;
	while(ptr2 != NULL)
	{
		if (ptr2->data < ptr->data)
			ptr = ptr2;
		ptr2 = ptr2->next;
	}
	ptr2->next = *head;
	ptr2 = *head;
	while (ptr2->next != ptr)
	{
		ptr2 = ptr2->next;
	}
	ptr2->next = NULL;
	*head = ptr;

	return (head);
}