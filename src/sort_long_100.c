/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 16:44:56 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 11:14:32 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_closest(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk)
{
	if (chunk->bot >= chunk->top)
	{
		while (chunk->top > 0)
		{
			rotate_a(stack_a);
			chunk->top--;
		}
		push_b(stack_a, stack_b);
	}
	else if (chunk->bot < chunk->top)
	{
		while (chunk->bot > 0)
		{
			reverse_rotate_a(stack_a);
			chunk->bot--;
		}
		push_b(stack_a, stack_b);
	}
}

void	top_check(t_stack *stack_a, t_chunk *chunk)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a->list;
	while (i < stack_a->size)
	{
		if (tmp->rank >= chunk->min && tmp->rank <= chunk->max)
		{
			chunk->top = i;
			return ;
		}
		tmp = tmp->next;
		i++;
	}
	chunk->top = -1;
}

void	bot_check(t_stack *stack_a, t_chunk *chunk)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a->list;
	while (i < stack_a->size)
	{
		if (tmp->rank >= chunk->min && tmp->rank <= chunk->max)
		{
			chunk->bot = i;
			return ;
		}
		tmp = tmp->prev;
		i++;
	}
	chunk->bot = -1;
}

void	sort_100(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_chunk	chunk;

	chunk = chunk_init(stack_a);
	i = 0;
	while (i < 5)
	{
		chunk_size(&chunk, 5, i);
		chunk_set(&chunk);
		while (chunk.top >= 0 && chunk.bot >= 0)
		{
			top_check(stack_a, &chunk);
			bot_check(stack_a, &chunk);
			if (chunk.top >= 0 && chunk.top >= 0)
				push_closest(stack_a, stack_b, &chunk);
		}
		i++;
	}
	push_back(stack_a, stack_b, &chunk);
}
