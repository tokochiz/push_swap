/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:49:24 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/16 20:20:36 by  ctokoyod        ###   ########.fr       */
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

void	optimize_and_move_b_to_a(t_ps *ps)
{
	calculate_move_costs(ps);
	calculate_optimal_target(ps);
	set_best_move_method(ps);
	ececute_move_method(ps);
	optimize_stack_a(ps);
}

void	sort_stack(t_ps *ps)
{
	if (ps->a->size <= 5)
	{
		sort_small(ps);
		return ;
	}
	// AからBに移動させる
	move_a_to_b(ps);
	print_stack(ps->a, 'A');
	print_stack(ps->b, 'B');
	update_min_max_b(ps);
	printf("stack b min:%d max:%d\n", ps->min_b, ps->max_b);
	while (ps->b->size > 0)
	{
		optimize_and_move_b_to_a(ps);
		adjust_stack_b(ps);
		update_min_max_b(ps);
		printf("stack b min:%d max:%d\n", ps->min_b, ps->max_b);
	}
	optimize_final_stack_a(ps);
}
