/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamada <kyamada@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 21:16:31 by kyamada           #+#    #+#             */
/*   Updated: 2025/09/11 21:16:34 by kyamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_node_bottom(t_stack *stack, t_node *new)
{
	if (!stack || !new)
		return ;
	if (stack->size == 0)
	{
		stack->top = new;
		stack->bottom = new;
	}
	else
	{
		stack->bottom->next = new;
		new->prev = stack->bottom;
		stack->bottom = new;
	}
	stack->size++;
}

int	init_stack(t_stack *stack, int count, char **args)
{
	int		i;
	long	num;
	t_node	*node;

	i = 0;
	while (i < count)
	{
		if (!is_valid_number(args[i]))
			return (0);
		num = ft_atol(args[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		node = create_node((int)num);
		if (!node)
			return (0);
		add_node_bottom(stack, node);
		i++;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*cur;
	t_node	*next;

	if (!stack)
		return ;
	cur = stack->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(stack);
}
