/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 12:15:33 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/11 11:05:39 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

static void	set_pos(t_list *stack_a, char **input, int argc)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i = 0;
		while (i < argc)
		{
			if (ft_atoi(input[i]) == stack_a->content)
			{
				stack_a->pos = i;
			}
			i++;
		}
		stack_a = stack_a->next;
	}
}

void	simple_sort(t_list **stack_a, char **input, int argc)
{
	int		step;
	int		i;
	char	*temp;

	step = 0;
	i = 0;
	temp = 0;
	while (step < (argc - 1))
	{
		i = 0;
		while (i < (argc - 1))
		{
			if (ft_atoi(input[i]) > ft_atoi(input[i + 1]))
			{
				temp = input[i];
				input[i] = input[i + 1];
				input[i + 1] = temp;
			}
			i++;
		}
		step++;
	}
	set_pos(*stack_a, input, argc);
}

void	sorting(t_list **stack_a, t_list **stack_b, int count)
{
	if (sorted_from(*stack_a, 0))
		return ;
	else if (count == 2)
		sort_2(stack_a);
	else if (count == 3)
		sort_3(stack_a);
	else if (count == 4)
		sort_4(stack_a, stack_b);
	else if (count == 5)
		sort_5(stack_a, stack_b);
	else if (count > 5 && count <= 40)
		sort_till_40(stack_a, stack_b, count);
	else
		radix_sort(stack_a, stack_b, count);
}
