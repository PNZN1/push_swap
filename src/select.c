/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   select.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/28 13:17:28 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/11 11:01:24 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

int	sorted_from(t_list *lst, int from)
{
	int	idx;

	idx = 0;
	if (!lst)
		return (TRUE);
	while (lst->next != NULL)
	{
		if (lst->pos > lst->next->pos && idx >= from)
			return (FALSE);
		lst = lst->next;
		idx++;
	}
	return (TRUE);
}

int	sorted_till(t_list *lst, int till)
{
	int	idx;

	idx = 0;
	if (!lst)
		return (TRUE);
	while (lst->next != NULL)
	{
		if (lst->pos > lst->next->pos && idx <= till)
			return (FALSE);
		lst = lst->next;
		idx++;
	}
	return (TRUE);
}

void	small_on_top(t_list **lst)
{
	float	size;
	int		idx;

	size = ft_lstsize(*lst);
	idx = find_smallest(*lst);
	if (idx > size / 2)
	{
		while (idx < size)
		{
			rra_rrb(lst, "rra\n");
			idx++;
		}
	}
	else
	{
		while (idx > 0)
		{
			ra_rb(lst, "ra\n");
			idx--;
		}
	}
}

int	find_smallest(t_list *lst)
{
	int	count;
	int	idx;
	int	smallest;

	count = 0;
	idx = 0;
	smallest = INT_MAX;
	while (lst != NULL)
	{
		if (smallest > lst->pos)
		{
			smallest = lst->pos;
			idx = count;
		}
		count++;
		lst = lst->next;
	}
	return (idx);
}
