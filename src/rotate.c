/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:24:51 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 11:14:58 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	stack->list = stack->list->next;
	return (1);
}

void	rotate_a(t_stack *stack)
{
	if (rotate(stack))
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack)
{
	if (rotate(stack))
		write(1, "rb\n", 3);
}

void	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	if (rotate(stack_a) && rotate(stack_b))
		write(1, "rr\n", 3);
	else
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}
