/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 14:56:56 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/19 18:03:01 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*cpy_arr(int *arr, int size)
{
	int	i;
	int	*cpy;

	i = 0;
	cpy = (int *) malloc (sizeof(int) * size);
	if (!arr || !cpy)
		error_malloc();
	while (i < size)
	{
		cpy[i] = arr[i];
		i++;
	}
	return (cpy);
}

int	max_nbr(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
}

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
}
