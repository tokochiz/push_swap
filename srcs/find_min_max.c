/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:54:11 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/28 21:20:06 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min_position(t_stack *stack, t_ps *ps)
{
	t_node	*current;
	int		min_value;
	int		min_pos;
	int		current_pos;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ps);
	current = stack->top;
	min_value = (int)(intptr_t)current->content;
	min_pos = 0;
	current_pos = 0;
	while (current != NULL)
	{
		if ((int)(intptr_t)current->content < min_value)
		{
			min_value = (int)(intptr_t)current->content;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

int	find_max_position(t_stack *stack, t_ps *ps)
{
	t_node	*current;
	int		max_value;
	int		max_pos;
	int		current_pos;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ps);
	current = stack->top;
	max_value = (int)(intptr_t)current->content;
	max_pos = 0;
	current_pos = 0;
	while (current != NULL)
	{
		if ((int)(intptr_t)current->content > max_value)
		{
			max_value = (int)(intptr_t)current->content;
			max_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (max_pos);
}

int	find_min(t_stack *stack, t_ps *ps)
{
	int		min;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ps);
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

int	find_max(t_stack *stack, t_ps *ps)
{
	int		max;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ps);
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
