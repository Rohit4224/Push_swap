/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:02:43 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/14 19:48:01 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sort4_5(t_node **a, t_node **b, int size)
{
	if (size == 4)
	{

	}
	if (size == 5)
	{

	}
}

void	sort2_3(t_node **a, t_node **b, int size)
{
	int i;

	i = 0;
	size = ft_lstsize(*a);
	if (size == 2)
	{

	}
	if (size == 3)
	{

	}
	sort4_5(a, b, size);
}

// it checks if argv is equal to 2, 
//if it is which means that we have to check numbers in argv[1]
//- and split the numbers and put them in matrix by ft_split.
//index starts from 0 because matrix[size]/matrix[0] has the value.
// index starts from 1 because argv[argc]/argv[0] is the filename.

void	check_input(int argc, char **argv, t_node **a)
{
	int		size;
	char	**matrix;

	size = 0;
	if (argc == 2)
	{
		matrix = ft_split(argv[1], ' ');
		while (matrix[size] != NULL)
			size++;
		create_stack(a, size, matrix, 0);
		free(matrix);
	}
	else if (argc >= 3)
		create_stack(a, argc, argv, 1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	int		size;

	size = 0;
	if (argc == 1)
		return (0);
	else if (argc > 1)
		check_input(argc, argv, &a);
	sort2_5(&a, &b, size);
	return (0);
}
