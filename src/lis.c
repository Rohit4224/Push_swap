/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhinchi <rkhinchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:31:24 by rkhinchi          #+#    #+#             */
/*   Updated: 2023/03/18 15:04:30 by rkhinchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*elmnt_lis to store the length of the 
longest increasing subsequence 
for each element of the input array*/
//prev_index to store the index of the previous element 
//in the longest increasing subsequence

// initial LIS length for each elemnt is 1
// lultima posizione del ultimo elemento del LIS e' pos

typedef struct s_temp
{
	int	*elmnt_lis;
	int	*prev_index;
	int	*actual_lis;
	int	i;
	int	j;
	int	len;
	int	pos;
}	t_temp;

void	lis_continue(t_temp *all, int arr[], int n)
{
	while (all->i < n)
	{
		all->elmnt_lis[all->i] = 1;
		all->prev_index[all->i] = -1;
		all->j = 0;
		while (all->j < all->i)
		{
			if (arr[all->j] < arr[all->i] && \
			all->elmnt_lis[all->j] + 1 >= all->elmnt_lis[all->i])
			{
				all->elmnt_lis[all->i] = all->elmnt_lis[all->j] + 1;
				all->prev_index[all->i] = all->j;
			}
			all->j++;
		}
		if (all->len < all->elmnt_lis[all->i])
		{
			all->len = all->elmnt_lis[all->i];
			all->pos = all->i;
		}
		all->i++;
	}
}

int	*lis(int arr[], int n, int *len_lis)
{
	t_temp	all;

	all.elmnt_lis = malloc(sizeof(int) * n);
	all.prev_index = malloc(sizeof(int) * n);
	all.i = 0;
	all.len = 1;
	all.pos = 0;
	lis_continue(&all, arr, n);
	all.actual_lis = malloc(sizeof(int) * all.len);
	all.i = all.len - 1;
	while (all.i >= 0)
	{
		all.actual_lis[all.i] = arr[all.pos];
		all.pos = all.prev_index[all.pos];
		all.i--;
	}
	*len_lis = all.len;
	free(all.elmnt_lis);
	free(all.prev_index);
	return (all.actual_lis);
}

/*
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    int *lis_arr = lis(arr, n);
    int i = 0;
    while (lis_arr[i] != '\0')
    {
        printf("%d ", lis_arr[i]);
        i++;
    }
    printf("\n");
    free(lis_arr);

    return 0;
}
*/