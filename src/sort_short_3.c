/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:12:59 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 14:57:20 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	higher_than_next(t_stack *stack_a)
{
	if (stack_a->list->next->rank < stack_a->list->next->next->rank)
	{
		if (stack_a->list->rank < stack_a->list->prev->rank)
			swap_a(stack_a);
		else
			rotate_a(stack_a);
	}
	else
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
}

void	lower_than_next(t_stack *stack_a)
{
	if (stack_a->list->next->rank > stack_a->list->prev->rank
		&& stack_a->list->rank < stack_a->list->prev->rank)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (stack_a->list->rank > stack_a->list->prev->rank)
		reverse_rotate_a(stack_a);
}

void	sort_3(t_stack *stack_a)
{
	if (stack_a->list->rank > stack_a->list->next->rank)
		higher_than_next(stack_a);
	else if (stack_a->list->rank < stack_a->list->next->rank)
		lower_than_next(stack_a);
}
