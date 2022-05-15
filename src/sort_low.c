/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_low.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 10:52:27 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/22 14:19:29 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **lst)
{
	if ((*lst)->pos > (*lst)->next->pos)
		sa_sb(lst, "sa\n");
}

void	sort_3(t_list **lst)
{
	int	first;
	int	second;
	int	third;

	first = (*lst)->pos;
	second = (*lst)->next->pos;
	third = (*lst)->next->next->pos;
	if (first > second && third > second && first < third)
		sa_sb(lst, "sa\n");
	else if (first > second && second > third)
	{
		sa_sb(lst, "sa\n");
		rra_rrb(lst, "rra\n");
	}
	else if (first > second && first > third && second < third)
		ra_rb(lst, "ra\n");
	else if (first < second && first < third && second > third)
	{
		sa_sb(lst, "sa\n");
		ra_rb(lst, "ra\n");
	}
	else
		rra_rrb(lst, "rra\n");
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	if (sorted_from(*stack_a, 0))
		return ;
	small_on_top(stack_a);
	if (!sorted_from(*stack_a, 1))
	{
		pa_pb(stack_a, stack_b, "pb\n");
		sort_3(stack_a);
		pa_pb(stack_b, stack_a, "pa\n");
	}
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (sorted_from(*stack_a, 0))
		return ;
	small_on_top(stack_a);
	if (!sorted_from(*stack_a, 1))
	{
		pa_pb(stack_a, stack_b, "pb\n");
		sort_4(stack_a, stack_b);
		pa_pb(stack_b, stack_a, "pa\n");
	}
}
