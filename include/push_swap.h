/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 13:31:13 by pniezen       #+#    #+#                 */
/*   Updated: 2022/03/14 09:04:30 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

# define TRUE 1
# define FALSE 0

char		**parse_input(int argc, char **argv);
void		error_exit_double(char **str);
void		error_exit_single(char *str);

void		sorting(t_list **stack_a, t_list **stack_b, int count);
void		simple_sort(t_list **stack_a, char **input, int argc);

int			sorted_from(t_list *lst, int from);
int			sorted_till(t_list *lst, int till);
void		sort_2(t_list **lst);
void		sort_3(t_list **lst);
void		sort_4(t_list **stack_a, t_list **stack_b);
void		sort_5(t_list **stack_a, t_list **stack_b);
void		sort_till_40(t_list **stack_a, t_list **stack_b, int count);
void		radix_sort(t_list **stack_a, t_list **stack_b, int count);

void		sa_sb(t_list **lst, char *choice);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa_pb(t_list **from, t_list **to, char *choice);
void		ra_rb(t_list **lst, char *choice);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra_rrb(t_list **lst, char *choice);
void		rrr(t_list **stack_a, t_list **stack_b);

void		small_on_top(t_list **lst);
int			find_smallest(t_list *lst);

void		delete_node(t_list **head);
void		free_pointer(char **str);
void		free_all(t_list **stack_a, t_list **stack_b, char **argv_cpy);

#endif
