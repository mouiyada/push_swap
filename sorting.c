/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:39:06 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/10 16:14:16 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index_pos(t_stack *b)
{
	t_node	*cur;
	int		max;
	int		max_pos;
	int		i;

	cur = b->top;
	max = -1;
	max_pos = 0;
	i = 0;
	while (cur)
	{
		if (cur->index > max)
		{
			max = cur->index;
			max_pos = i;
		}
		cur = cur->next;
		i = i + 1;
	}
	return (max_pos);
}

static void	move_chunk_to_b(t_stack *a, t_stack *b, int start, int end)
{
	int	moved;

	moved = 0;
	while (moved < end - start)
	{
		if (a->top->index >= start && a->top->index < end)
		{
			pb (a, b);
			moved++;
		}
		else
			ra(a);
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;
	int	j;

	while (b->size)
	{
		max_pos = find_max_index_pos(b);
		if (max_pos <= b->size / 2)
		{
			j = 0;
			while (j++ < max_pos)
				rb(b);
		}
		else
		{
			j = max_pos;
			while (j++ < b->size)
				rrb(b);
		}
		pa(a, b);
	}
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	num_chunks;
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	size = a->size;
	if (size <= 100)
		num_chunks = 5;
	else
		num_chunks = 12;
	chunk_size = size / num_chunks;
	chunk_start = 0;
	while (chunk_start < size)
	{
		if ((chunk_start / chunk_size) == num_chunks - 1)
			chunk_end = size;
		else
			chunk_end = chunk_start + chunk_size;
		move_chunk_to_b(a, b, chunk_start, chunk_end);
		chunk_start = chunk_end;
	}
	push_back_to_a(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a);
	}
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
	else
		chunk_sort(a, b);
}
