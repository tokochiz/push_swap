/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:02 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/20 00:21:24 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_current_min_costs(t_ps *ps, t_node *current)
{
	int	min;

	if (ps == NULL || ps->costs == NULL || current == NULL
		|| current->content == NULL)
		put_error_and_exit(ERR_STACK);
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

int	find_target_position(t_stack *stack, int value)
{
	t_node	*current;
	int		position;
	int		min;
	int		max;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
	current = stack->top;
	position = 0;
	min = find_min(stack);
	max = find_max(stack);
	if (value < min)
	{
		if (find_min_position(stack) == 0)
			return (0);
		else
			return (find_max_position(stack));
	}
	if (value > max)
		return (find_min_position(stack));
	while (current->next != NULL)
	{
		if (value >= (int)(intptr_t)current->content
			&& value < (int)(intptr_t)current->next->content)
			return (position + 1);
		current = current->next;
		position++;
	}
	return (position + 1);
}

void	calculate_move_costs(t_ps *ps)
{
	t_node	*current;
	int		position;
	int		target_p;

	// int		min_cost_type;
	current = ps->b->top;
	position = 0;
	while (current != NULL)
	{
		target_p = find_target_position(ps->a, (int)(intptr_t)current->content);
		calculate_costs1(ps, position, target_p);
		calculate_costs2(ps, position, target_p);
		calculate_costs3(ps, position, target_p);
		calculate_costs4(ps, position, target_p);
		find_current_min_costs(ps, current);
		printf("cost 1 : %d \n", ps->costs->cost1);
		printf("cost 2 : %d \n", ps->costs->cost2);
		printf("cost 3 : %d \n", ps->costs->cost3);
		printf("cost 4 : %d \n", ps->costs->cost4);
		printf("!![%d] target_p ;%d current->cost;%d type:%d\n",
			(int)(intptr_t)current->content, target_p, current->cost,
			current->type);
		position++;
		current = current->next;
	}
}

t_node	*find_min_cost(t_stack *stack)
{
	int		cost_min;
	t_node	*cost_min_p;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
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
