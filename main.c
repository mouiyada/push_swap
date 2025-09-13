/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:11:01 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/11 21:32:06 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	error_exit(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	return (1);
}

static char	**get_args(int argc, char **argv, int *count, int *is_split)
{
	char	**args;

	*is_split = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		*is_split = 1;
	}
	else
		args = argv + 1;
	*count = 0;
	while (args && args[*count])
		(*count)++;
	if (*count == 0)
	{
		if (*is_split)
			free_split_args(args);
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (args);
}

static int	pre_sort_checks(t_stack *a, t_stack *b)
{
	if (has_duplicates(a))
		return (error_exit(a, b));
	if (is_sorted(a))
	{
		free_stack(a);
		free_stack(b);
		return (1);
	}
	return (0);
}

static void	assign_and_sort(t_stack *a, t_stack *b)
{
	assign_indices(a);
	sort(a, b);
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	int		count;
	int		is_split;

	if (argc < 2)
		return (0);
	args = get_args(argc, argv, &count, &is_split);
	if (!args)
		return (1);
	a = create_stack();
	b = create_stack();
	if (!a || !b || !init_stack(a, count, args))
	{
		if (is_split)
			free_split_args(args);
		return (error_exit(a, b));
	}
	if (is_split)
		free_split_args(args);
	if (pre_sort_checks(a, b))
		return (0);
	assign_and_sort(a, b);
	return (0);
}
