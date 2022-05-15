/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands_2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 15:06:24 by pniezen       #+#    #+#                 */
/*   Updated: 2022/02/25 11:25:20 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa_sb(stack_a, "");
	sa_sb(stack_b, "");
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra_rb(stack_a, "");
	ra_rb(stack_b, "");
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra_rrb(stack_a, "");
	rra_rrb(stack_b, "");
	ft_putstr_fd("rrr\n", 1);
}
