/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:49:24 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/20 22:36:10 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	final_rotate(t_ps *ps)
{
	int	min_p;
	int	a_size;

	min_p = find_min_position(ps->a);
	a_size = ps->a->size;
	if (min_p <= a_size / 2)
	{
		while (min_p > 0)
		{
			ra(ps);
			min_p--;
		}
	}
	else
	{
		while (min_p < a_size)
		{
			rra(ps);
			min_p++;
		}
	}
}

void	move_a_to_b(t_ps *ps)
{
	t_node	*current;
	int		value;
	int		i;

	current = ps->a->top;
	i = 0;
	while (ps->a->size > 5)
	{
		value = (int)(intptr_t)ps->a->top->content;
		pb(ps);
		i++;
	}
}

void	optimize_and_move_b_to_a(t_ps *ps)
{
	t_node	*inserted_p;
	int		inserted_value;
	int		pattern;

	if (ps->b->size == 0)
		return ;
	calculate_move_costs(ps);
	inserted_p = find_min_cost(ps->b);
	inserted_value = (int)(intptr_t)inserted_p->content;
	pattern = inserted_p->type;
	move_to_b_top(ps, inserted_p, pattern);
	move_to_a_target(ps, (int)(intptr_t)inserted_p->content, pattern);
}

void	sort_stack(t_ps *ps)
{
	if (ps->a->size <= 5)
	{
		sort_small_stack(ps);
		return ;
	}
	move_a_to_b(ps);
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
	sort_small_stack(ps);
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
	while (ps->b->size > 0)
	{
		optimize_and_move_b_to_a(ps);
		printf_stack(ps->a, 'A');
		printf_stack(ps->b, 'B');
		if (ps->b->size == 0)
			break ;
	}
	final_rotate(ps);
}
