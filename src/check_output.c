/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:28 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/21 20:34:43 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate_checker(t_node *head, int number,
				char **argv, char not_argv)
{
	while (head->next != NULL)
	{
		if (head->data == number)
		{
			ft_putstr_fd("Error\n", 2);
			error_free(argv, &head, not_argv, 1);
			exit(0);
		}
		head = head->next;
	}
}

void	check_order_4_checker(t_node **head)
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

void	sort_2_checker(t_node **a)
{
	t_node	*ptr;
	t_node	*ptr2;

	ptr = *a;
	ptr2 = (*a)->next;
	while (ptr2 != NULL)
	{
		if (ptr->data < ptr2->data)
			return ;
		ptr = ptr->next;
		ptr2 = ptr2->next;
	}
}

void	create_stack_checker(t_node **head, int argc, char **argv, int index)
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
		check_duplicate_checker(*head, ptr->data, argv, not_argv);
		index++;
	}
	error_free(argv, NULL, not_argv, 0);
	check_order_4_checker(head);
	sort_2_checker(head);
	ptr = NULL;
}
