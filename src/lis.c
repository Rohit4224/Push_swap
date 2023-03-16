//header

//elmnt_lis to store the length of the longest increasing subsequence for each element of the input array
//prev_index to store the index of the previous element in the longest increasing subsequence
#include "push_swap.h"

int		*lis(int arr[], int n)
{
	int	*elmnt_lis;
	int	*prev_index;
	int *actual_lis;
	int i;
	int j;
	int len;
	int pos;

	elmnt_lis = malloc(sizeof(int) * n);
	prev_index = malloc(sizeof(int) * n);
	i = 0;
	len = 1;
	pos = 0;

	while (i < n)
	{
		elmnt_lis[i] = 1; // initial LIS length for each elemnt is 1
		prev_index[i] = -1;
		j = 0;
		while(j < i)
		{
			if (arr[j] < arr[i] && elmnt_lis[j] + 1 >= elmnt_lis[i])
			{
				elmnt_lis[i] = elmnt_lis[j] + 1;
				prev_index[i] = j;
			}
			j++;
		}
		if (len < elmnt_lis[i])
		{
			len = elmnt_lis[i];
			pos = i;
		}
		i++;
	}
	actual_lis = malloc(sizeof(int) * len + 1);
	actual_lis[len] == '\0';
	i = len - 1;
	while (i >= 0)
	{
		actual_lis[i] = arr[pos];
		pos = prev_index[pos];
		i--;
	}
	free(elmnt_lis);
	free(prev_index);

	return (actual_lis);
}

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