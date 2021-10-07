/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 09:34:46 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/14 13:39:56 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_chunk
{
	int	min;
	int	max;
	int	top;
	int	bot;
	int	rank;
	int	size;
}	t_chunk;

typedef struct s_list
{
	int				rank;
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_stack
{
	t_list	*list;
	int		size;
}	t_stack;

	//errors
void			error(int id, t_stack *stack_a, t_stack *stack_b);
void			mem_check(void *ptr, t_stack *stack_a, t_stack *stack_b);

	//parsing
char			*ft_itoa(int n);
void			parser(int ac, char **av, t_stack *stack_a, t_stack *stack_b);

	//operations
int				swap(t_stack *stack);
void			swap_a(t_stack *stack);
void			swap_b(t_stack *stack);
void			swap_ss(t_stack *stack_a, t_stack *stack_b);
int				push(t_stack *stack_1, t_stack *stack_2);
void			push_a(t_stack *stack_a, t_stack *stack_b);
void			push_b(t_stack *stack_a, t_stack *stack_b);
int				rotate(t_stack *stack);
void			rotate_a(t_stack *stack);
void			rotate_b(t_stack *stack);
void			rotate_rr(t_stack *stack_a, t_stack *stack_b);
int				reverse_rotate(t_stack *stack);
void			reverse_rotate_a(t_stack *stack);
void			reverse_rotate_b(t_stack *stack);
void			reverse_rotate_rrr(t_stack *stack_a, t_stack *stack_b);

	//sorting
void			sort_3(t_stack *stack_a);
void			sort_5(t_stack *stack_a, t_stack *stack_b);
void			sort_100(t_stack *stack_a, t_stack *stack_b);
void			sort_500(t_stack *stack_a, t_stack *stack_b);
void			sort_infinity(t_stack *stack_a, t_stack *stack_b);
void			top_check(t_stack *stack_a, t_chunk *chunk);
void			bot_check(t_stack *stack_a, t_chunk *chunk);
void			push_closest(t_stack *stack_a, t_stack *stack_b, \
				t_chunk *chunk);
void			push_back(t_stack *stack_a, t_stack *stack_b, t_chunk *chunk);

	//list utils
t_list			*list_new(int value, t_stack *stack_a, t_stack *stack_b);
t_list			*list_last(t_stack *stack);
void			list_addback(t_stack *stack, t_list *new);
void			list_addfront(t_stack *stack, t_list *new);
void			list_clear(t_stack *stack);

	//inits
t_stack			stack_init(void);
void			stack_check(t_stack *stack_a, t_stack *stack_b);
t_chunk			chunk_init(t_stack *stack);

	//chunking
void			chunk_size(t_chunk *chunk, int chunk_qtt, int chunk_nb);
void			chunk_set(t_chunk *chunk);

	//utils
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *ptr, size_t size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *str1, const char *str2, size_t size);

#endif