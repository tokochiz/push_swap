/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:47:52 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/18 06:00:45 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_costs1(t_ps *ps, int position, int target_p)
{
	int	cost_b;
	int	cost_a;

	if (ps->b->size <= 1)
		cost_b = 0;
	else if (position <= ps->b->size / 2)
		cost_b = position;
	else
		cost_b = ps->b->size - position;
	if (target_p <= ps->a->size / 2)
		cost_a = target_p;
	else
		cost_a = ps->a->size - target_p;
	ps->costs->cost1 = cost_a + cost_b + 1;
}

void	calculate_costs2(t_ps *ps, int position, int target_p)
{
	int	cost_b;
	int	cost_a;

	if (ps->b->size <= 1)
		cost_b = 0;
	else if (position <= ps->b->size / 2)
		cost_b = position;
	else
		cost_b = ps->b->size - position;
	if (target_p <= ps->a->size / 2)
		cost_a = ps->a->size - target_p;
	else
		cost_a = target_p;
	ps->costs->cost2 = cost_a + cost_b + 1;
}

void	calculate_costs3(t_ps *ps, int position, int target_p)
{
	int	cost_b;
	int	cost_a;

	if (ps->b->size <= 1)
		cost_b = 0;
	else if (position <= ps->b->size / 2)
		cost_b = ps->b->size - position;
	else
		cost_b = position;
	if (target_p <= ps->a->size / 2)
		cost_a = target_p;
	else
		cost_a = ps->a->size - target_p;
	ps->costs->cost3 = cost_a + cost_b + 1;
}

void	calculate_costs4(t_ps *ps, int position, int target_p)
{
	int	cost_b;
	int	cost_a;

	if (ps->b->size <= 1)
		cost_b = 0;
	else if (position <= ps->b->size / 2)
		cost_b = ps->b->size - position;
	else
		cost_b = position;
	if (target_p <= ps->a->size / 2)
		cost_a = ps->a->size - target_p;
	else
		cost_a = target_p;
	ps->costs->cost4 = cost_a + cost_b + 1;
}
