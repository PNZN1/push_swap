/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 10:38:13 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/11 14:48:12 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	error_exit_double(char **str)
{
	free_pointer(str);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	error_exit_single(char *str)
{
	free(str);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_pointer(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	delete_node(t_list **head)
{
	t_list	*temp;

	temp = *head;
	*head = temp->next;
	free(temp);
	return ;
}

void	free_all(t_list **stack_a, t_list **stack_b, char **argv)
{
	t_list	*tmp_a;
	t_list	*tmp_b;

	free_pointer(argv);
	while (*stack_a != NULL)
	{
		tmp_a = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp_a);
	}
	while (*stack_b != NULL)
	{
		tmp_b = *stack_b;
		*stack_b = (*stack_b)->next;
		free(tmp_b);
	}
}
