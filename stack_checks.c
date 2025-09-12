/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:54:41 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/11 21:16:21 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_node	*curr;
	t_node	*runner;

	curr = stack->top;
	while (curr)
	{
		runner = curr->next;
		while (runner)
		{
			if (runner->value == curr->value)
				return (1);
			runner = runner->next;
		}
		curr = curr->next;
	}
	return (0);
}

void	assign_indices(t_stack *stack)
{
	t_node	*curr;
	t_node	*min;
	int		index;

	index = 0;
	while (index < stack->size)
	{
		curr = stack->top;
		min = NULL;
		while (curr)
		{
			if (curr->index == -1)
			{
				if (!min || curr->value < min->value)
					min = curr;
			}
			curr = curr->next;
		}
		if (min)
			min->index = index++;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*cur;

	if (stack->size < 2)
		return (1);
	cur = stack->top;
	while (cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}
