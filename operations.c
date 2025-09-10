/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:25:28 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/10 15:30:28 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*f;
	t_node	*s;

	f = stack->top;
	if (stack->size < 2)
		return ;
	s = f->next;
	f->next = s->next;
	if (s->next)
		s->next->prev = f;
	s->prev = NULL;
	s->next = f;
	f->prev = s;
	stack->top = s;
	if (stack->size == 2)
		stack->bottom = f;
}

void	push(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (from->size == 0)
		return ;
	node = from->top;
	from->top = node->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;
	node->next = to->top;
	if (to->top)
		to->top->prev = node;
	else
		to->bottom = node;
	node->prev = NULL;
	to->top = node;
	to->size++;
}

void	rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = stack->top;
	stack->top = node->next;
	stack->top->prev = NULL;
	stack->bottom->next = node;
	node->prev = stack->bottom;
	node->next = NULL;
	stack->bottom = node;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return ;
	node = stack->bottom;
	stack->bottom = node->prev;
	stack->bottom->next = NULL;
	node->next = stack->top;
	stack->top->prev = node;
	node->prev = NULL;
	stack->top = node;
}
