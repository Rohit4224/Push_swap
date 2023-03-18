/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:42:37 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/16 18:39:37 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_lstsize01(t_node *lst)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = lst;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

/*void	int_range(long int c)
{
	if (c < -2147483648 || c > 2147483647)
	{
		write(2, "Error int is not in range\n", 27);
		exit(0);
	}
	else if (c > -2147483648 && c < 2147483647)
		return ;
	else
	{
		write(2, "Error int is not in range\n", 27);
		exit(0);
	}
}*/

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
