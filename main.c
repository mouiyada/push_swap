/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:11:01 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/10 15:15:00 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	error_exit(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = create_stack();
	b = create_stack();
	if (!a || !b || !init_stack_from_args(a, argc, argv))
		return (error_exit(a, b));
	if (has_duplicates(a))
		return (error_exit(a, b));
	assign_indices(a);
	sort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
