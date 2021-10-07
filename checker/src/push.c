/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:13:15 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 13:46:22 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	push(t_stack *stack_1, t_stack *stack_2)
{
	t_list	*scd;
	t_list	*last;

	if (stack_2->size == 0)
		return (0);
	scd = stack_2->list->next;
	last = stack_2->list->prev;
	list_addfront(stack_1, stack_2->list);
	if (stack_2->size == 1)
		stack_2->list = NULL;
	else
	{
		stack_2->list = scd;
		stack_2->list->prev = last;
		last->next = scd;
	}
	stack_2->size -= 1;
	return (1);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
}
