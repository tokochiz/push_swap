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
挿入位置は以下のルールで決定します：

value が現在の要素より大きく、かつスタックの先頭要素よりも小さい場合
value が現在の要素より小さく、かつ次の要素よりも大きい場合

*/


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
	if (value < min){
 // 最大値の次の位置（つまり先頭）に挿入する
        return (find_max_position(stack) + 1) % stack->size;
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
	return (pos + 1); // 最後の位置を返す
}

void	calculate_move_costs(t_ps *ps)
{
	t_node	*current;
	int		position;
	int		b_size;
	int		cost_b;
	int		cost_a;
	int		target_pos;

	current = ps->b->top;
	position = 0;
	b_size = ps->b->size;
	while (current)
	{
		if (position <= b_size / 2)
			cost_b = position;
		else
			cost_b = b_size - position;
		target_pos = find_target_position(ps->a,
				(int)(intptr_t)current->content);
		//適切な挿入位置を見つけ
		if (target_pos <= ps->a->size / 2)
			cost_a = target_pos;
		else
			cost_a = ps->a->size - target_pos;
		current->cost = cost_a + cost_b;
		current = current->next;
		position++;
	}
}

t_node	*find_best_element(t_stack *stack)
{
	t_node	*cost_min;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
	current = stack->top;
	cost_min = current;
	while (current != NULL)
	{
		printf("current: %d  cost: %d\n", (int)(intptr_t)current->content,
			(int)(intptr_t)current->cost);
		if (cost_min == NULL || current->cost < cost_min->cost)
			cost_min = current;
		current = current->next;
	}
	if (cost_min == NULL)
		put_error_and_exit(ERR_STACK);
	printf("Best element: %d with cost: %d\n", (int)(intptr_t)cost_min->content,
		cost_min->cost);
	return (cost_min);
}

