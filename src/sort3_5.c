//header


void    sort_4(t_node **a, t_node **b)
{
    a = lowest_n(a);
    ft_pb(a, b);
    sort_3.0(a);
    ft_pa(a);
}

void    sort_3.0(t_node **a)
{
    t_node *ptr;

    ptr = *a;
    ptr2 = (*a)->next;
    ptr3 = (*a)->next->next;
    if (ptr->data > ptr2->data && ptr2->data < ptr3->data)
    {
        if (ptr3->data < ptr->data)
        {  
            ft_rra(a);
            ft_rra(a);
        }
        else
            ft_sa(a);
    }
    if (ptr->data > ptr2->data && ptr2->data > ptr3->data)
    {
        ft_rra(a);
        ft_sa(a);
        ft_ra(a);
    }
    if (ptr->data < ptr2->data && ptr2->data > ptr3->data)
    {
        if (ptr3->data < ptr->data)
                ft_rra(a);
        else if (ptr3->data > ptr->data)
        {
            ft_rra(a);
            ft_sa(a);
        }   
    }
}

// i suppose that first two number has already been swapped to ascending order
// probability of having number 132 || 231 || 264
void    sort_3(t_node **a)
{
    t_node ptr;
    t_node ptr2;

    ptr = *a;
    ptr2 = (*a)->next;
    if (ptr->data < ptr2->data)
        ft_rra(a);
    check_order(a);
    if ((*a)->data > ptr->data)
        ft_sa(a);
    check_order(a);
} 

void	continue(t_node **a, t_node **b, int size)
{
	if (size == 4)
	{
        sort_4(a, b);
	}
	if (size == 5)
	{

	}
}

void	sort3_5(t_node **a, t_node **b)
{
	int i;
    int size;

	i = 0;
	size = ft_lstsize(*a);
	if (size == 3)
	{
        sort_3(a);
	}
	continue(a, b, size);
}