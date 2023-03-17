/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:02:57 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/17 21:03:47 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew01(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = content;
	node->next = NULL;
	return (node);
}

//list_delete
void	lst_erase(t_node **head)
{
	t_node	*ptr;

	if (*head == NULL)
		return ;
	ptr = *head;
	while (ptr != NULL)
	{
		ptr = (*head)->next;
		free(*head);
		*head = ptr;
	}
}

//to check duplicate numbers
void	check_duplicate(t_node *head, int number, char **argv, char not_argv)
{
	while (head->next != NULL)
	{
		if (head->data == number)
		{
			ft_putstr_fd("Error duplicate\n", 2);
			error_free(argv, &head, not_argv, 1);
			exit(0);
		}
		head = head->next;
	}
}
// se e' gia in tutto ordine

void	check_order(t_node	**head)
{
	t_node	*ptr;
	t_node	*ptr2;

	ptr = *head;
	ptr2 = (*head)->next;
	while (ptr2 != NULL)
	{
		if (ptr->data > ptr2->data)
			return ;
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
	lst_erase(head);
	exit(0);
}

//saving the first node, 
//and adding the node to the back of stack a and to check duplicates
// if index == 0 then not_argv is 1, which means we have to free argv(matrix)

void	create_stack(t_node **head, int argc, char **argv, int index)
{
	t_node		*ptr;
	long long	tmp;
	char		not_argv;

	not_argv = 0;
	if (!index)
		not_argv = 1;
	while (index < argc)
	{
		if (!is_number(argv[index]))
			ft_error_number(argv, head, not_argv, 1);
		tmp = ft_atoi(argv[index]);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error_number(argv, head, not_argv, 2);
		ptr = ft_lstnew01(ft_atoi(argv[index]));
		ft_lstadd_back01(head, ptr);
		check_duplicate(*head, ptr->data, argv, not_argv);
		index++;
	}
	error_free(argv, NULL, not_argv, 0);
	check_order(head);
	ptr = NULL;
}
