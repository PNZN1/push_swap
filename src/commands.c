/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 12:39:27 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/05 11:36:49 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_list **lst, char *choice)
{
	int	tmp;

	if (!(*lst))
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
	tmp = (*lst)->pos;
	(*lst)->pos = (*lst)->next->pos;
	(*lst)->next->pos = tmp;
	ft_putstr_fd(choice, 1);
}

void	pa_pb(t_list **from, t_list **to, char *choice)
{
	t_list	*new;
	t_list	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	new = ft_lstnew((*from)->content);
	new->pos = (*from)->pos;
	ft_lstadd_front(to, new);
	delete_node(from);
	ft_putstr_fd(choice, 1);
}

void	ra_rb(t_list **lst, char *choice)
{
	t_list	*first;
	t_list	*last;

	first = *lst;
	last = ft_lstlast(*lst);
	if (!*lst || !(*lst)->next)
		return ;
	*lst = first->next;
	first->next = NULL;
	last->next = first;
	ft_putstr_fd(choice, 1);
}

void	rra_rrb(t_list **lst, char *choice)
{
	t_list	*seclast;
	t_list	*last;

	seclast = NULL;
	last = *lst;
	if (!*lst || !(*lst)->next)
		return ;
	while (last->next != NULL)
	{
		seclast = last;
		last = last->next;
	}
	seclast->next = NULL;
	last->next = *lst;
	*lst = last;
	ft_putstr_fd(choice, 1);
}
