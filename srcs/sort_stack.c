/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:49:24 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/06 22:48:53 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// 中央値を求める理由　動作ごとに回数を加算できているか　一旦、単純にA→Bの関数として使う
void	move_a_to_b(t_ps *ps)
{
	int	median;
	int	elm_to_move;
	int	moved;

	if (ps == NULL || ps->a == NULL || ps->a->top == NULL)
		put_error_and_exit(ERR_STACK);
	median = find_median(ps->a);
	printf("Debug: Allocating memory for values array4 %d\n", median);
	elm_to_move = ps->a->size / 2;
	moved = 0;
	while (ps->a->size > 3 && moved < elm_to_move)
	{
		if ((int)(intptr_t)ps->a->top->content < median)
		{
			pb(ps);
			moved++;
		}
		else
		{
			ra(ps);
		}
	}
	while (ps->a->size > 0)
	{
		pb(ps);
	}
	printf("Debug: Allocating memory for values array5\n");
	// sort_three(ps->a);
}

// optimize 最適化する
// void	optimize_and_move_b_to_a(t_ps *ps)
// {
// 	calculate_move_costs(ps);
// 	calculate_optimal_target(ps);
// 	set_best_move_method(ps);
// 	execute_move_method(ps);
// 	optimize_stack_a(ps);
// }

void	sort_stack(t_ps *ps)
{
	if (ps->a->size <= 5)
	{
		// sort_small(ps);
		return ;
	}
	// AからBに移動させる
	move_a_to_b(ps);
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
	update_min_max_b(ps);
	printf("stack b min:%d max:%d\n", ps->min_b, ps->max_b);
	while (ps->b->size > 0)
		{
		optimize_and_move_b_to_a(ps);
		update_min_max_b(ps);
		printf("stack b min:%d max:%d\n", ps->min_b, ps->max_b);
	 }
	// 	optimize_final_stack_a(ps);
}
