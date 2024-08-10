/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-10 11:02:22 by ctokoyod          #+#    #+#             */
/*   Updated: 2024-08-10 11:02:22 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_insertion_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
	current = stack->top;
	pos = 0;
	if (value < (int)(intptr_t)current->content)
		return (0);
	while (current->next != NULL)
	{
		if (value > (int)(intptr_t)current->content
			&& value < (int)(intptr_t)current->next->content)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	return (pos + 1);
}

//その要素をB内の先頭に移動
void	move_to_b_top(t_ps *ps, t_node *target)
{
	int		pos;
	t_node	*current;

	printf("m: target_element %d\n", (int)(intptr_t)target->content);
	pos = 0;
	current = ps->b->top;
	while (current != target && current != NULL)
	{
		pos++;
		current = current->next;
	}
	if (current == NULL)
		return ;
	if (pos <= ps->b->size / 2)
	{
		// 上半分にあるとき、rb: スタックBを上に1つシフト（一番上が一番下に）
		while (pos > 0)
		{
			rb(ps);
			pos--;
		}
	}
	else
	{
		while (pos < ps->b->size) // rrb: スタックBを下に1つシフト（一番下が一番上に）
		{
			rrb(ps);
			pos++;
		}
	}
	printf("~~b_top~~~~~~~~~~~~~\n");
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
}

// A内の適切な位置に移動
void	move_to_a_target(t_ps *ps, int value)
{
	int	target_pos;
	int	a_size;

	printf("m: value %d\n", value);
	target_pos = find_insertion_position(ps->a, value);
	printf("Calculated target position: %d\n", target_pos);
	a_size = ps->a->size;
	// スタックの半分より上にあるか下にあるかで回転方向を決定
	if (target_pos <= a_size / 2)
	{
		while (target_pos > 0)
		{
			ra(ps); // ra: スタックAを上に1つシフト（一番上が一番下に）
			target_pos--;
		}
	}
	else
	{
		while (target_pos < a_size)
		{
			rra(ps); // rra: スタックAを下に1つシフト（一番下が一番上に）
			target_pos++;
		}
	}
	printf("~~a_target~~~~~~~~~~~~~\n");
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
}

void	optimize_and_move_b_to_a(t_ps *ps)
{
	t_node	*best_element;

	calculate_move_costs(ps);
	//最小コストの要素を見つける
	best_element = find_best_element(ps->b);
	printf("m: best_element %d\n", (int)(intptr_t)best_element->content);
	//その要素をB内の先頭に移動
	move_to_b_top(ps, best_element);

	// A内の適切な位置に移動
	move_to_a_target(ps, (int)(intptr_t)best_element->content);
    pa(ps); // pa: スタックBの一番上の要素をスタックAに移動
	printf("~~ps~~~~~~~~~~~~~\n");
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
}
