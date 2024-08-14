/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:02 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/06 23:33:15 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~途中なので修正する
/*
挿入位置は以下のルールで決定：

value が現在の要素より大きく、かつスタックの先頭要素よりも小さい場合
value が現在の要素より小さく、かつ次の要素よりも大きい場合
*/
int	find_current_min_costs(t_ps *ps)
{
	int	min;

	if(ps->costs == NULL)
		return 0;

	min = ps->costs->cost1;
	if (ps->costs->cost2 < min)
		min = ps->costs->cost2;
	if (ps->costs->cost3 < min)
		min = ps->costs->cost3;
	if (ps->costs->cost4 < min)
		min = ps->costs->cost4;
	return (min);
}

int	find_target_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;
	int		min;
	int		max;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
	current = stack->top;
	pos = 0;
	min = find_min(stack);
	max = find_max(stack);
	// 値がスタックの最小値より小さいとき、最小値の直前（最大値の後）に挿入
	if (value < min)
	{
		// 最大値の次の位置（つまり先頭）に挿入する
		return ((find_max_position(stack) + 1) % stack->size);
	}
	if (value > max)
		return (0); //スタックの先頭にある
	while (current->next != NULL)
	{
		if (value > (int)(intptr_t)current->content
			&& value < (int)(intptr_t)current->next)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	return (pos + 1); 
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
		
		target_p = find_target_position(ps->a, (int)(intptr_t)current->content);
		printf("calculate costs target_p:%d\n", target_p);
		calculate_costs1(ps, position, target_p);
		calculate_costs2(ps, position, target_p);
		calculate_costs3(ps, position, target_p);
		calculate_costs4(ps, position, target_p);
		current->cost = find_current_min_costs(ps);
		position++;
		current = current->next;
	}
}

t_node	*find_min_cost(t_stack *stack)
{
	t_node	*cost_min;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
	current = stack->top;
	cost_min = current;
	while (current != NULL)
	{
		if (cost_min == NULL || current->cost < cost_min->cost)
			cost_min = current;
		current = current->next;
	}
	if (cost_min == NULL)
		put_error_and_exit(ERR_STACK);
	return (cost_min);
}
