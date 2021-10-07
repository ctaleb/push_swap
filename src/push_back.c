/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 14:36:54 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 11:15:06 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_len(t_stack *stack_b, t_chunk *chunk)
{
	t_list	*tmp;

	chunk->top = 0;
	tmp = stack_b->list;
	while (chunk->top < stack_b->size)
	{
		if (chunk->rank == tmp->rank)
			return ;
		tmp = tmp->next;
		chunk->top++;
	}
	chunk->top = -1;
}

void	bot_len(t_stack *stack_b, t_chunk *chunk)
{
	t_list	*tmp;

	chunk->bot = 0;
	tmp = stack_b->list;
	while (chunk->bot < stack_b->size)
	{
		if (chunk->rank == tmp->rank)
			return ;
		tmp = tmp->prev;
		chunk->bot++;
	}
	chunk->bot = -1;
}

void	push_back(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	while (chunk->rank >= 0)
	{
		top_len(stack_b, chunk);
		bot_len(stack_b, chunk);
		if (chunk->top <= chunk->bot)
		{
			while (chunk->top > 0)
			{
				rotate_b(stack_b);
				chunk->top--;
			}
			push_a(stack_a, stack_b);
		}
		else if (chunk->top > chunk->bot)
		{
			while (chunk->bot > 0)
			{
				reverse_rotate_b(stack_b);
				chunk->bot--;
			}
			push_a(stack_a, stack_b);
		}
		chunk->rank--;
	}
}
