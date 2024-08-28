/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:02 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/28 21:26:50 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_current_min_costs(t_ps *ps, t_node *current)
{
	int	min;

	if (ps == NULL || ps->costs == NULL || current == NULL
		|| current->content == NULL)
		put_error_and_exit(ps);
	min = ps->costs->cost1;
	current->type = 1;
	if (ps->costs->cost2 < min)
	{
		current->type = 2;
		min = ps->costs->cost2;
	}
	if (ps->costs->cost3 < min)
	{
		current->type = 3;
		min = ps->costs->cost3;
	}
	if (ps->costs->cost4 < min)
	{
		current->type = 4;
		min = ps->costs->cost4;
	}
	current->cost = min;
}

int	find_target_position(t_stack *stack, int value, t_ps *ps)
{
	t_node	*current;
	int		position;
	int		min;
	int		max;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ps);
	current = stack->top;
	position = 0;
	min = find_min(stack, ps);
	max = find_max(stack, ps);
	if (value < min || value > max)
	{
		return (((find_max_position(stack, ps) + 1) % stack->size));
	}
	while (current->next != NULL)
	{
		if (value >= (int)(intptr_t)current->content
			&& value < (int)(intptr_t)current->next->content)
			return ((position + 1) % stack->size);
		current = current->next;
		position++;
	}
	return (0);
}

void	calculate_move_costs(t_ps *ps)
{
	t_node	*current;
	int		position;
	int		target_p;

	current = ps->b->top;
	position = 0;
	while (current != NULL)
	{
		target_p = find_target_position(ps->a, (int)(intptr_t)current->content,
				ps);
		calculate_costs1(ps, position, target_p);
		calculate_costs2(ps, position, target_p);
		calculate_costs3(ps, position, target_p);
		calculate_costs4(ps, position, target_p);
		find_current_min_costs(ps, current);
		position++;
		current = current->next;
	}
}

t_node	*find_min_cost(t_stack *stack, t_ps *ps)
{
	int		cost_min;
	t_node	*cost_min_p;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ps);
	current = stack->top;
	cost_min = current->cost;
	cost_min_p = current;
	while (current != NULL)
	{
		if (current->cost < cost_min)
		{
			cost_min = current->cost;
			cost_min_p = current;
		}
		current = current->next;
	}
	return (cost_min_p);
}
