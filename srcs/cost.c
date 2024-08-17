/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:27:02 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/17 22:29:21 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~途中なので修正する
/*
挿入位置は以下のルールで決定：

value が現在の要素より大きく、かつスタックの先頭要素よりも小さい場合
value が現在の要素より小さく、かつ次の要素よりも大きい場合
*/
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
		return (0);
	if (value > max)
		return (0); //スタックの先頭にある
	while (current->next != NULL)
	{
		if (value >= (int)(intptr_t)current->content
			&& value < (int)(intptr_t)current->next->content)
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
