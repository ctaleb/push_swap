/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 10:53:52 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/12 15:33:43 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (push(stack_a, stack_b))
		write(1, "pa\n", 3);
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	if (push(stack_b, stack_a))
		write(1, "pb\n", 3);
}
