/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 11:23:55 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/22 11:28:51 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

static int	duplicates(char **input)
{
	int		argc;
	int		i;
	int		j;

	i = 0;
	j = i +1;
	argc = 0;
	while (input[argc])
		argc++;
	while (input[i])
	{
		j = i +1;
		while (input[j])
		{
			if (!ft_strncmp(input[i], input[j], 5))
				error_exit_double(input);
			j++;
		}
		i++;
	}
	return (argc);
}

static int	valid_num(char *str, t_list **st_a, t_list **st_b, char **argv)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
		{
			free_all(st_a, st_b, argv);
			ft_putstr_fd("Error\n", 2);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
	{
		free_all(st_a, st_b, argv);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (num);
}

static void	add_to_stack(t_list **head, int val)
{
	t_list	*new;

	new = ft_lstnew(val);
	ft_lstadd_back(head, new);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**input;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc == 1)
		return (0);
	input = parse_input(argc, argv);
	argc = duplicates(input);
	while (i < argc)
	{
		add_to_stack(&stack_a, valid_num(input[i], &stack_a, &stack_b, input));
		i++;
	}
	simple_sort(&stack_a, input, argc);
	if (!sorted_from(stack_a, 0))
		sorting(&stack_a, &stack_b, argc);
	free_all(&stack_a, &stack_b, input);
	return (0);
}
