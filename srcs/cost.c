/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-04 12:27:02 by ctokoyod          #+#    #+#             */
/*   Updated: 2024-08-04 12:27:02 by ctokoyod         ###   ########.fr       */
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
    int pos;

	if (stack == NULL || stack->top == NULL)
		return (INT_MIN);
	current = stack->top;
    pos = 0;
    min = find_min(stack);
	max = find_max(stack);
	cost_min = (intptr_t)(current->cost);
	while (current != NULL)
	{
		if ((intptr_t)(current->cost) < cost_min)
			cost_min = (intptr_t)(current->cost);
		current = current->next;
	}
	return (cost_min);
}

void	calculate_move_costs(t_ps *ps)
{
	t_list	*current;
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

int	find_best_element(t_stack *stack)
{
	int		cost_min;
	t_node	*current;

	if (stack == NULL || stack->top == NULL)
		return (INT_MIN);
	current = stack->top;
	cost_min = (intptr_t)(current->cost);
	while (current != NULL)
	{
		if ((intptr_t)(current->cost) < cost_min)
			cost_min = (intptr_t)(current->cost);
		current = current->next;
	}
	return (cost_min);
}

void	optimize_and_move_b_to_a(t_ps *ps)
{
	t_list	*best_element;

	calculate_move_costs(ps);
	//最小コストの要素を見つける
	best_element = find_best_element(ps->b);
	//その要素をB内の先頭に移動
	move_to_top(ps, 'b', best_element);
	// A内の適切な位置に移動
	move_to_target(ps, 'a', (int)(intptr_t)best_element->content);
	pa(ps);
}
