/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:29:58 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/14 09:52:43 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add1_to_a3(t_stack *stack_a, t_stack *stack_b)
{
	push_a(stack_a, stack_b);
	if (stack_a->list->rank > stack_a->list->prev->rank)
		rotate_a(stack_a);
	else if (stack_a->list->rank > stack_a->list->prev->prev->rank)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (stack_a->list->rank > stack_a->list->next->rank)
		swap_a(stack_a);
}

void	add1_to_a4(t_stack *stack_a, t_stack *stack_b)
{
	push_a(stack_a, stack_b);
	if (stack_a->list->rank > stack_a->list->prev->rank)
		rotate_a(stack_a);
	else if (stack_a->list->rank > stack_a->list->prev->prev->rank)
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (stack_a->list->rank > stack_a->list->next->next->rank)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (stack_a->list->rank > stack_a->list->next->rank)
		swap_a(stack_a);
}

void	push_smallest(t_stack *stack_a, t_stack *stack_b, int rank)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a->list;
	while (i < stack_a->size)
	{
		if (tmp->rank == rank)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i <= 2)
		while (i--)
			rotate_a(stack_a);
	else
		while (i++ < stack_a->size)
			reverse_rotate_a(stack_a);
	push_b(stack_a, stack_b);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest(stack_a, stack_b, 0);
	if (stack_a->size == 4)
		push_smallest(stack_a, stack_b, 1);
	sort_3(stack_a);
	while (stack_b->size)
		push_a(stack_a, stack_b);
}
