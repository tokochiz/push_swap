/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:49:24 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/19 23:52:34 by ctokoyod         ###   ########.fr       */
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

int	rotate_stack(t_ps *ps, int position, int found)
{
	int	i;

	i = 0;
	found = 1;
	if (position <= ps->a->size / 2)
	{
		while (i < position)
		{
			ra(ps);
			i++;
		}
	}
	else
	{
		while (i < ps->a->size - position)
		{
			rra(ps);
			i++;
		}
	}
	return (found);
}

void	move_group(t_ps *ps, int min, int max)
{
	int		value;
	int		position;
	t_node	*current;
	int		found;

	while (ps->a->size > 5)
	{
		found = 0;
		current = ps->a->top;
		position = 0;
		while (current != NULL)
		{
			value = (int)(intptr_t)current->content;
			if (value > min && value <= max)
			{
				found = rotate_stack(ps, position, found);
				pb(ps);
				break ;
			}
			current = current->next;
			position++;
		}
		if (found != 1)
			break ;
	}
}

void	move_a_to_b(t_ps *ps)
{
	// int	min;
	// int	max;
	// int	range;

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
	// if (ps == NULL || ps->a == NULL || ps->a->top == NULL)
	// 	put_error_and_exit(ERR_STACK);
	// min = find_min(ps->a);
	// max = find_max(ps->a);
	// // range = max - min;
	// // ps->group1 = min + range / 4;
	// // ps->group2 = min + 2 * range / 4;
	// // ps->group3 = min + 3 * range / 4;
	// range = max - min;
	// ps->group1 = min + range / 5;
	// ps->group2 = min + 2 * range / 5;
	// ps->group3 = min + 3 * range / 5;
	// ps->group4 = min + 4 * range / 5;
	// while (ps->a->size > 5)
	// {
	// 	move_group(ps, ps->group4, max + 1);
	// 	move_group(ps, ps->group3, ps->group4);
	// 	move_group(ps, ps->group2, ps->group3);
	// 	move_group(ps, ps->group1, ps->group2);
	// 	move_group(ps, min - 1, ps->group1);
	// }
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
