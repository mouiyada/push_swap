/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:46:41 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/10 16:17:31 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->index;
	mid = a->top->next->index;
	bot = a->bottom->index;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

static void	rotate_to_min(t_stack *a, int min, int pos)
{
	while (a->top->index != min)
	{
		if (pos <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	push_min_to_b(t_stack *a, t_stack *b)
{
	t_node	*cur;
	int		pos;
	int		min;

	cur = a->top;
	pos = 0;
	min = cur->index;
	while (cur)
	{
		if (cur->index < min)
			min = cur->index;
		cur = cur->next;
	}
	cur = a->top;
	while (cur->index != min)
	{
		pos++;
		cur = cur->next;
	}
	rotate_to_min(a, min, pos);
	pb(a, b);
}

void	sort_four(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	pa(a, b);
	pa(a, b);
}
