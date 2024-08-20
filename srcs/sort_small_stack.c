/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:56:12 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/20 20:40:49 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_ps *ps)
{
	if ((int)(intptr_t)ps->a->top->content >
	(int)(intptr_t)ps->a->top->next->content)
		sa(ps);
}

void	sort_three(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = (int)(intptr_t)ps->a->top->content;
	b = (int)(intptr_t)ps->a->top->next->content;
	c = (int)(intptr_t)ps->a->top->next->next->content;
	if (a > b && b > c)
	{
		sa(ps);
		rra(ps);
	}
	else if (a > b && a < c)
		sa(ps);
	else if (a > b && b < c && a > c)
		ra(ps);
	else if (a < b && b > c && a < c)
	{
		sa(ps);
		ra(ps);
	}
	else if (a < b && b > c && a > c)
		rra(ps);
}

void	sort_four(t_ps *ps)
{
	int	min_pos;

	min_pos = find_min_position(ps->a);
	if (min_pos == 1)
		sa(ps);
	else if (min_pos == 2)
	{
		ra(ps);
		ra(ps);
	}
	else if (min_pos == 3)
		rra(ps);
	pb(ps);
	sort_three(ps);
	pa(ps);
}

void	sort_five(t_ps *ps)
{
	int	min_pos;

	min_pos = find_min_position(ps->a);
	if (min_pos == 1)
		sa(ps);
	else if (min_pos == 2)
	{
		ra(ps);
		ra(ps);
	}
	else if (min_pos == 3)
	{
		rra(ps);
		rra(ps);
	}
	else if (min_pos == 4)
		rra(ps);
	pb(ps);
	sort_four(ps);
	pa(ps);
}

void	sort_small_stack(t_ps *ps)
{
	int	a_size;

	a_size = ps->a->size;
	if (a_size == 2)
		sort_two(ps);
	else if (a_size == 3)
		sort_three(ps);
	else if (a_size == 4)
		sort_four(ps);
	else if (a_size == 5)
		sort_five(ps);
}
