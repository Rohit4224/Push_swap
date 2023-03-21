/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:42:37 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/21 19:49:45 by rkhinchi         ###   ########.fr       */
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

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_number(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

int	*list_to_arr(t_node **a, int size)
{
	t_node	*ptr;
	int		*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(int) * size);
	ptr = *a;
	while (ptr != NULL)
	{
		arr[i] = ptr->data;
		ptr = ptr->next;
		i++;
	}
	return (arr);
}
