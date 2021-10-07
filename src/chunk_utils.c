/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 10:13:45 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/13 11:17:47 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_chunk	chunk_init(t_stack *stack)
{
	t_chunk	chunk;

	chunk.min = 0;
	chunk.max = 0;
	chunk.top = 0;
	chunk.bot = 0;
	chunk.size = stack->size;
	chunk.rank = chunk.size - 1;
	return (chunk);
}

void	chunk_size(t_chunk *chunk, int chunk_qtt, int chunk_nb)
{
	int	div;
	int	mod;

	div = chunk->size / chunk_qtt;
	mod = chunk->size % chunk_qtt;
	chunk->min = div * chunk_nb;
	chunk->max = chunk->min + div - 1;
	if (chunk_nb == chunk_qtt - 1)
		chunk->max += mod;
}

void	chunk_set(t_chunk *chunk)
{
	chunk->top = 0;
	chunk->bot = 0;
}
