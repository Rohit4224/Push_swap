/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:02:43 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/17 21:03:46 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort for 2
void	sort_2(t_node **a)
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
	ft_sa(a);
	check_order(a);
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
		if (matrix[0] == NULL)
			exit(0);
		while (matrix[size] != NULL)
			size++;
		create_stack(a, size, matrix, 0);
	}
	else if (argc >= 3)
		create_stack(a, argc, argv, 1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 1)
		check_input(argc, argv, &a);
	sort_2(&a);
	sorting(&a, &b);
	lst_erase(&a);
	lst_erase(&b);
	return (0);
}
