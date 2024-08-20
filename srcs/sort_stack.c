/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:49:24 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/20 23:51:42 by ctokoyod         ###   ########.fr       */
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

void	optimize_and_move_b_to_a(t_ps *ps)
{
	t_node	*inserted_p;
	int		inserted_value;

	if (ps->b->size == 0)
		return ;
	calculate_move_costs(ps);
	inserted_p = find_min_cost(ps->b);
	inserted_value = (int)(intptr_t)inserted_p->content;
	move_top_of_b(ps, inserted_p);
	insert_value_in_a(ps, (int)(intptr_t)inserted_p->content);
}

void	sort_stack(t_ps *ps)
{
	if (ps->a->size <= 5)
	{
		sort_small_stack(ps);
		return ;
	}
	move_a_to_b(ps);
	sort_small_stack(ps);
	while (ps->b->size > 0)
	{
		optimize_and_move_b_to_a(ps);
		if (ps->b->size == 0)
			break ;
	}
	final_rotate(ps);
}
