/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:02:22 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/28 21:22:10 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	insert_value_in_a(t_ps *ps, int value)
{
	int	target_p;
	int	a_size;
	int	originaltarget_p;

	target_p = find_target_position(ps->a, value, ps);
	originaltarget_p = target_p;
	a_size = ps->a->size;
	if (target_p <= a_size / 2)
	{
		while (target_p > 0)
		{
			ra(ps);
			target_p--;
		}
	}
	else
	{
		while (target_p < a_size)
		{
			rra(ps);
			target_p++;
		}
	}
	pa(ps);
}

void	move_top_of_b(t_ps *ps, t_node *target)
{
	int		position;
	t_node	*current;

	position = 0;
	current = ps->b->top;
	while (current != target && current != NULL)
	{
		position++;
		current = current->next;
	}
	if (current == NULL)
		return ;
	if (position <= ps->b->size / 2)
	{
		while (position-- > 0)
			rb(ps);
	}
	else
	{
		while (position++ < ps->b->size)
			rrb(ps);
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
