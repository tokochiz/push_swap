/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:47:52 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/17 22:03:25 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// stack_b を上方向に回転させ、stack_a を上方向に回転させる
void	calculate_costs1(t_ps *ps, int position, int target_p)
{
	int	cost_b;
	int	cost_a;

	if (position <= ps->b->size / 2)
		cost_b = position;
	else
		cost_b = ps->b->size - position;
	if (target_p <= ps->a->size / 2)
		cost_a = target_p;
	else
		cost_a = ps->a->size - target_p;
	ps->costs->cost1 = cost_a + cost_b;
}

void	calculate_costs2(t_ps *ps, int position, int target_p)
{
	int	cost_b;
	int	cost_a;

	if (position <= ps->b->size / 2)
		cost_b = position;
	else
		cost_b = ps->b->size - position;
	if (target_p <= ps->a->size / 2)
		cost_a = ps->a->size - target_p;
	else
		cost_a = target_p;
	ps->costs->cost2 = cost_a + cost_b;
}

void	calculate_costs3(t_ps *ps, int position, int target_p)
{
	int	cost_b;
	int	cost_a;

	if (position <= ps->b->size / 2)
		cost_b = ps->b->size - position;
	else
		cost_b = position;
	if (target_p <= ps->a->size / 2)
		cost_a = target_p;
	else
		cost_a = ps->a->size - target_p;
	ps->costs->cost3 = cost_a + cost_b;
}

void	calculate_costs4(t_ps *ps, int position, int target_p)
{
	int	cost_b;
	int	cost_a;

	if (position <= ps->b->size / 2)
		cost_b = ps->b->size - position;
	else
		cost_b = position;
	if (target_p <= ps->a->size / 2)
		cost_a = ps->a->size - target_p;
	else
		cost_a = target_p;
	ps->costs->cost4 = cost_a + cost_b;
}
