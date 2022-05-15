/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_high.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 08:02:17 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/08 13:27:19 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int count)
{
	int	max_bits;
	int	i;
	int	j;

	max_bits = get_max_bits(count - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < count)
		{
			if ((((*stack_a)->pos >> i) & 1) == 1)
				ra_rb(stack_a, "ra\n");
			else
				pa_pb(stack_a, stack_b, "pb\n");
			j++;
		}
		while ((*stack_b))
			pa_pb(stack_b, stack_a, "pa\n");
		i++;
	}
}

void	sort_till_40(t_list **stack_a, t_list **stack_b, int count)
{
	int	push_back;

	push_back = 0;
	while (count > 0)
	{
		if (count == 5)
			sort_5(stack_a, stack_b);
		else if (count > 5)
		{
			small_on_top(stack_a);
			pa_pb(stack_a, stack_b, "pb\n");
			push_back++;
		}
		count--;
	}
	while (push_back > 0)
	{
		pa_pb(stack_b, stack_a, "pa\n");
		push_back--;
	}
}
