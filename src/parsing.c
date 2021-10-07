/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaleb <ctaleb@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:15:36 by ctaleb            #+#    #+#             */
/*   Updated: 2021/06/14 14:35:52 by ctaleb           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	overunder(int nb, const char *str, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		len;
	char	*tmp;

	tmp = ft_itoa(nb);
	i = 0;
	while (str[i] == ' ')
		i++;
	len = ft_strlen(tmp) - 1;
	if (len <= 0)
		len = 1;
	if (ft_strncmp(tmp, &str[i], len))
	{
		free(tmp);
		error(9, stack_a, stack_b);
	}
	free(tmp);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	symbol_set(char symbol)
{
	if (symbol == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str, t_stack *stack_a, t_stack *stack_b)
{
	unsigned long long	nb;
	int					i;
	int					sym;

	i = 0;
	sym = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sym = symbol_set(str[i++]);
	nb = 0;
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	if ((nb > 2147483648 && sym < 0) || (nb > 2147483647 && sym > 0))
		error(9, stack_a, stack_b);
	overunder(nb * sym, str, stack_a, stack_b);
	return (nb * sym);
}

void	parser(int ac, char **av, t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			tmp = ft_atoi(&av[i][j], stack_a, stack_b);
			while (av[i][j] && av[i][j] == ' ')
				j++;
			if (av[i][j] && av[i][j] == '-')
				j++;
			if ((av[i][j] && !ft_isdigit(av[i][j])) || !av[i][j])
				error(3, stack_a, stack_b);
			while (av[i][j] && ft_isdigit(av[i][j]))
				j++;
			if (av[i][j] && av[i][j] != ' ')
				error(3, stack_a, stack_b);
			list_addback(stack_a, list_new(tmp, stack_a, stack_b));
		}
		i++;
	}
}
