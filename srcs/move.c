/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-08-10 11:02:22 by ctokoyod          #+#    #+#             */
/*   Updated: 2024-08-10 11:02:22 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_operations(t_ps *ps, int ra_count, int rra_count)
{
	int	ra_op;
	int	rra_op;

	printf("ra %d rra %d\n", ra_count, rra_count);
	ra_op = 0;
	rra_op = 0;
	if (rra_count >= 0 && ra_count == 0)
		ra_op = rra_count + 1;
	if (rra_count == 0 && ra_count > 0)
		rra_op = ra_count;
	if (is_sorted(ps) != TRUE)
	{
		while (ra_op > 0)
		{
			ra(ps);
			ra_op--;
		}
		while (rra_op > 0)
		{
			rra(ps);
			rra_op--;
		}
	}
}

int	find_insertion_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
	current = stack->top;
	pos = 0;
	if (value < (int)(intptr_t)current->content)
		return (0);
	while (current->next != NULL)
	{
		if (value > (int)(intptr_t)current->content
			&& value < (int)(intptr_t)current->next->content)
			return (pos + 1);
		current = current->next;
		pos++;
	}
	return (pos + 1);
}
void	move_to_a_target(t_ps *ps, int value)
{
	int	target_p;
	int	a_size;
	int	ra_count;
	int	rra_count;

	ra_count = 0;
	rra_count = 0;
	target_p = find_insertion_position(ps->a, value);
	a_size = ps->a->size;
	printf("target_p %d size %d\n", target_p, a_size / 2);
	if (target_p <= a_size / 2) // スタックの半分より上にあるか下にあるかで回転方向を決定
	{
		while (target_p > 0)
		{
			ra(ps); // ra: スタックAを上に1つシフト（一番上が一番下に）
			ra_count++;
			target_p--;
		}
	}
	else
	{
		while (target_p < a_size)
		{
			rra(ps); // rra: スタックAを下に1つシフト（一番下が一番上に）
			rra_count++;
			target_p++;
		}
	}
	// printf("~~a_target~~~~~~~~~~~~~\n");
	// printf_stack(ps->a, 'A');
	// printf_stack(ps->b, 'B');
	pa(ps);
	// printf("~~ps~~~~~~~~~~~~~\n");
	// printf_stack(ps->a, 'A');
	// printf_stack(ps->b, 'B');
	reverse_operations(ps, ra_count, rra_count);
	// printf("~~reverse~~~~~~~~~~~~~\n");
	// printf_stack(ps->a, 'A');
	// printf_stack(ps->b, 'B');
}

//その要素をB内の先頭に移動
void	move_to_b_top(t_ps *ps, t_node *target)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = ps->b->top;
	while (current != target && current != NULL)
	{
		pos++;
		current = current->next;
	}
	if (current == NULL)
		return ;
	if (pos <= ps->b->size / 2)
	{
		while (pos > 0) // 上半分にあるとき、rb: スタックBを上に1つシフト（一番上が一番下に）
		{
			rb(ps);
			pos--;
		}
	}
	else
	{
		while (pos < ps->b->size) // rrb: スタックBを下に1つシフト（一番下が一番上に）
		{
			rrb(ps);
			pos++;
		}
	}
}
