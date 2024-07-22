/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:49:24 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/22 23:03:13 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_a_to_b(t_ps *ps)
{
	t_node	*node_to_move;

	if (ps == NULL || ps->a == NULL || ps->a->top == NULL)
		put_error_and_exit(ERR_STACK);
	while (ps->a->size > 3)
	{
		if(ps->a->top->content < find_median(ps->a))	
			pb(ps);
	}
	else{
		ra(ps);
	}
	sort_three(ps->a);
}

void calculate_move_costs(t_ps *ps)
{
	
}

// optimize 最適化する
void	optimize_and_move_b_to_a(t_ps *ps)
{
	calculate_move_costs(ps);
	calculate_optimal_target(ps);
	set_best_move_method(ps);
	execute_move_method(ps);
	optimize_stack_a(ps);
}

void	sort_stack(t_ps *ps)
{
	if (ps->a->size <= 5)
	{
		//sort_small(ps);
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
	//optimize_final_stack_a(ps);
}
