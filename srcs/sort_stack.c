/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:49:24 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/16 20:03:28 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_a_to_b(t_ps *ps)
{
	t_node	*node_to_move;

	if (ps == NULL || ps->a == NULL || ps->a->top == NULL)
		put_error_and_exit(ERR_STACK);
	while (ps->a->top != NULL)
	{
		node_to_move = ps->a->top;
		ps->a->top = node_to_move->next;
		node_to_move->next = ps->b->top;
		ps->b->top = node_to_move;
		ps->a->size--;
		ps->b->size++;
	}
}


void	sort_stack(t_ps *ps)
{

	// AからBに移動させる
	move_a_to_b(ps);
	print_stack(ps->a, 'A');
	print_stack(ps->b, 'B');

	update_min_max_b(ps);
	printf("stack b min:%d max:%d\n", ps->min_b, ps->max_b);
	// Bスタックの最小最大を探す、入れ替える、一番上もしくは一番したからpushする関数
	// Aスタックに積んだ時に、ルールが保たれているか
	// stackBの最大と最小を特定する
}
