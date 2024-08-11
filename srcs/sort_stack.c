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
	while (ps->a->size > 5 && moved < elm_to_move)
	{
		if ((int)(intptr_t)ps->a->top->content < median)
		{
			pb(ps);
			moved++;
		}
		else
			ra(ps);
	}
	printf("!!!\n");
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
	while (ps->a->size > 5 && ps->a->size > 0)
	{
		pb(ps);
	}
	sort_small_stack(ps);
}


void	sort_stack(t_ps *ps)
{
	if (ps->a->size <= 5)
	{
		sort_small_stack(ps);
		return ;
	}
	move_a_to_b(ps);
	update_min_max_b(ps);
	while (ps->b->size > 0)
		{
		optimize_and_move_b_to_a(ps);
		printf("~~~~~~sort!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		if(ps->b->size == 0)
			break ;
	 }
	// 	optimize_final_stack_a(ps);
}
