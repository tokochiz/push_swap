/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:54:11 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/16 19:55:07 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (INT_MIN);
	current = stack->top;
	min = (intptr_t)(current->content);
	while (current != NULL)
	{
		if ((intptr_t)(current->content) < min)
			min = (intptr_t)(current->content);
		current = current->next;
	}
	return (min);
}

int	find_max(t_stack *stack)
{
	int		max;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (INT_MIN);
	current = stack->top;
	max = (intptr_t)(current->content);
	while (current != NULL)
	{
		if ((intptr_t)(current->content) > max)
			max = (intptr_t)(current->content);
		current = current->next;
	}
	return (max);
}

void	update_min_max_b(t_ps *ps)
{
	ps->min_b = find_min(ps->b);
	ps->max_b = find_max(ps->b);
}
