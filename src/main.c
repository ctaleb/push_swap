/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 09:30:53 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/14 12:47:56 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac <= 1)
		exit(0);
	stack_a = stack_init();
	stack_b = stack_init();
	parser(ac, av, &stack_a, &stack_b);
	stack_check(&stack_a, &stack_b);
	if (stack_a.size <= 3)
		sort_3(&stack_a);
	else if (stack_a.size <= 5)
		sort_5(&stack_a, &stack_b);
	else if (stack_a.size <= 100)
		sort_100(&stack_a, &stack_b);
	else if (stack_a.size <= 500)
		sort_500(&stack_a, &stack_b);
	else
		sort_infinity(&stack_a, &stack_b);
	list_clear(&stack_a);
	list_clear(&stack_b);
	return (0);
}
