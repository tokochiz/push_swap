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
	int	moved;
	int	rotated;
	int	elements_to_move;

	if (ps == NULL || ps->a == NULL || ps->a->top == NULL)
		put_error_and_exit(ERR_STACK);
	while (ps->a->size > 5)
	{
		median = find_median(ps->a);
		printf("median %d\n", median);
		elements_to_move = ps->a->size / 2;
		moved = 0;
		rotated = 0;
		while (moved + rotated < ps->a->size && moved < elements_to_move)
		{
			if ((int)(intptr_t)ps->a->top->content < median
				&& moved < elements_to_move)
			{
				pb(ps);
				moved++;
			}
			else
			{
				ra(ps);
				rotated++;
			}
		}
		while (ps->a->size > 5)
			pb(ps);
	}
	sort_small_stack(ps);
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
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
		if (ps->b->size == 0)
			break ;
	}
}
