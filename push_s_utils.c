/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_s_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:02:57 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/14 19:37:45 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
void	lst_check(t_node *head, int number)
{
	while (head->next != NULL)
	{
		if (head->data == number)
		{
			ft_putstr_fd("Error duplicate\n", 2);
			exit(0);
		}
		head = head->next;
	}
}

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
	exit(0);
}

//saving the first node, 
//and adding the node to the back of stack a and to check duplicates

void	create_stack(t_node **head, int argc, char **argv, int index)
{
	t_node		*ptr;
	int			i;

	while (index < argc)
	{
		i = 0;
		while (argv[index][i])
		{
			if (ft_isdigit(argv[index][i]) == 0)
			{
				ft_putstr_fd("Error digit\n", 2);
				exit(0);
			}
			i++;
		}
		ptr = ft_lstnew01(ft_atoi(argv[index]));
		ft_lstadd_back01(head, ptr);
		lst_check(*head, ptr->data);
		index++;
	}
	check_order(head);
	ptr = NULL;
}
