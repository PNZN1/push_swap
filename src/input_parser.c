/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/08 10:00:54 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/14 08:21:32 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	check_malloc_single(char *str)
{
	if (!str)
		error_exit_single(str);
}

static void	check_malloc_double(char **str)
{
	if (!str)
		error_exit_double(str);
}

static char	*ft_strjoin_and_free_s1(char *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, (s1_len + s2_len + 1));
	free(s1);
	return (str);
}

static char	*parse_input2(char **input, char *ret, int j)
{
	while (input[j])
	{
		ret = ft_strjoin_and_free_s1(ret, input[j]);
		check_malloc_single(ret);
		ret = ft_strjoin_and_free_s1(ret, " ");
		check_malloc_single(ret);
		j++;
	}
	return (ret);
}

char	**parse_input(int argc, char **argv)
{
	char	**input;
	char	*ret;
	int		i;
	int		j;

	ret = ft_strdup("");
	check_malloc_single(ret);
	i = 1;
	j = 0;
	while (i < argc)
	{
		input = ft_split(argv[i], ' ');
		check_malloc_double(input);
		j = 0;
		ret = parse_input2(input, ret, j);
		free_pointer(input);
		i++;
	}
	argv = ft_split(ret, ' ');
	check_malloc_double(argv);
	free(ret);
	return (argv);
}
