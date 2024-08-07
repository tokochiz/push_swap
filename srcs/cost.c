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

int find_max_position(t_stack *stack)
{
	t_node *current;
	int max_value;
	int max_pos;
	int current_pos;

	if(stack ==NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
		
	current = stack->top;
	max_value = (int)(intptr_t)current->content;
	max_pos = 0;
	current_pos = 0;
	
	while(current != NULL)
	{
		if((int)(intptr_t)current->content > max_value)
		{
			max_value = (int)(intptr_t)current->content;
			max_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (max_pos + 1) % stack->size; // stack内で最大の次の位置を返す
	//max_pos 最大が見つかった位置　+１
	// もしmax_posが最大の要素だった場合に、stak->size-1　単純に＋１するとスタックサイズを超えてしまう、モジュロ演算を使うことで回避
}

int	find_target_position(t_stack *stack, int value)
{
	t_node	*current;
    int pos;
	int min;
	int max;
	
	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
	current = stack->top;
    pos = 0;
    min = find_min(stack);
	max = find_max(stack);
	// 値がスタックの最小値より小さいとき、最小値の直前（最大値の後）に挿入
	if(value < min)
		return  find_max_position(stack);
	if(value > max)
		return  0; //スタックの先頭に村有
	while (current->next != NULL)
	{
		if (value > (int)(intptr_t)current->content && value < (int)(intptr_t)current->next)
			return pos+1;
		current = current->next;
		pos++;
	}
	return 0;
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
		if (current->cost < cost_min->cost)
			cost_min = current;
		current = current->next;
	}
	return (cost_min);
}

void	optimize_and_move_b_to_a(t_ps *ps)
{
	t_node	*best_element;

	calculate_move_costs(ps);
	//最小コストの要素を見つける
	best_element = find_best_element(ps->b);
	printf("best_element %lld\n", (intptr_t)best_element);
	//その要素をB内の先頭に移動
	//move_to_top(ps, 'b', best_element);
	// A内の適切な位置に移動
	//move_to_target(ps, 'a', (int)(intptr_t)best_element->content);
	pa(ps);
}
