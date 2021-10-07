/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 12:15:47 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 12:17:51 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	reverse_rotate(t_stack *stack)
{
	if (stack->size == 0)
		return (0);
	stack->list = stack->list->prev;
	return (1);
}

void	reverse_rotate_a(t_stack *stack)
{
	reverse_rotate(stack);
}

void	reverse_rotate_b(t_stack *stack)
{
	reverse_rotate(stack);
}

void	reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		return ;
	else
	{
		rotate(stack_a);
		rotate(stack_b);
	}
}
