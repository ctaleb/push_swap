/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:25:44 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 11:15:04 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	stack->list = stack->list->prev;
	return (1);
}

void	reverse_rotate_a(t_stack *stack)
{
	if (reverse_rotate(stack))
		write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *stack)
{
	if (reverse_rotate(stack))
		write(1, "rrb\n", 4);
}

void	reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		write(1, "rrr\n", 4);
	else
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}
