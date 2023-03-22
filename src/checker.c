/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:17:49 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/22 17:44:08 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_finale(t_node *stack_a)
{
	if (stack_a == NULL)
	{
		write(1, "KO\n", 3);
		return ;
	}
	while (stack_a->next != NULL)
	{
		if (stack_a->data > (stack_a->next)->data)
		{
			write(1, "KO\n", 3);
			return ;
		}
		stack_a = stack_a->next;
	}
	write(1, "OK\n", 3);
	return ;
}

void	continue_sorting_checker(t_node **stack_a, t_node **stack_b, char *str)
{
	if (ft_strcmp(str, "rra\n"))
		checker_rra(stack_a);
	else if (ft_strcmp(str, "rrb\n"))
		checker_rrb(stack_b);
	else if (ft_strcmp(str, "rrr\n"))
		checker_rrr(stack_a, stack_b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		lst_erase(stack_a);
		lst_erase(stack_b);
		free(str);
		exit(0);
	}
}

void	sorting_checker(t_node **stack_a, t_node **stack_b, char *str)
{
	while (str != NULL)
	{
		if (ft_strcmp(str, "sa\n"))
			checker_sa(stack_a);
		else if (ft_strcmp(str, "sb\n"))
			checker_sb(stack_b);
		else if (ft_strcmp(str, "ss\n"))
			checker_ss(stack_a, stack_b);
		else if (ft_strcmp(str, "pa\n"))
			checker_pa(stack_b, stack_a);
		else if (ft_strcmp(str, "pb\n"))
			checker_pb(stack_a, stack_b);
		else if (ft_strcmp(str, "ra\n"))
			checker_ra(stack_a);
		else if (ft_strcmp(str, "rb\n"))
			checker_rb(stack_b);
		else if (ft_strcmp(str, "rr\n"))
			checker_rr(stack_a, stack_b);
		else
			continue_sorting_checker(stack_a, stack_b, str);
		free(str);
		str = get_next_line_gnl(0);
	}
}

void	check_input_checker(int argc, char **argv, t_node **a)
{
	int		size;
	char	**matrix;

	size = 0;
	if (argc == 2)
	{
		matrix = ft_split(argv[1], ' ');
		if (matrix[0] == NULL)
		{
			error_free(matrix, NULL, 1, 0);
			exit(0);
		}
		while (matrix[size] != NULL)
			size++;
		create_stack_checker(a, size, matrix, 0);
	}
	else if (argc >= 3)
		create_stack_checker(a, argc, argv, 1);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*str;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc > 1)
		check_input_checker(argc, argv, &a);
	str = get_next_line_gnl(0);
	sorting_checker(&a, &b, str);
	check_finale(a);
	lst_erase(&a);
	lst_erase(&b);
}
