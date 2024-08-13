/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:49:24 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/06 22:48:53 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	move_group(t_ps *ps, int min, int max)
// {
// 	int	value;
// 	int	i;

// 	i = 0;
// 	while (i < ps->a->size)
// 	{
// 		value = (int)(intptr_t)ps->a->top->content;
// 		if (value > min && value <= max)
// 		{
// 			pb(ps);
// 			if (ps->b->size > 1
// 				&& value < (int)(intptr_t)ps->b->top->next->content)
// 				sb(ps);
// 		}
// 		else
// 		{
// 			ra(ps);
// 		}
// 		i++;
// 	}
// }
//  void	move_a_to_b(t_ps *ps) が何回も呼び出されてしまうので、	while (i++ < a_size)のなかで
// グループを呼び出す形にするのが良さそう
void	move_group(t_ps *ps, int min, int max)
{
	int	value;
	int	i;
	int	target_p;
	int	a_size;
	// int	ra_count;
	// int	rra_count;

	i = 0;
	// ra_count = 0;
	// rra_count = 0;
	a_size = ps->a->size - 5;
	while (i++ < a_size)
	{
		value = (int)(intptr_t)ps->a->top->content;
		if (value > min && value <= max)
		{
			target_p = find_insertion_position(ps->a, value);
			printf("~stackA~ target_p %d size %d\n", target_p, a_size / 2);
				printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
			if (target_p <= a_size / 2) // スタックの半分より上にあるか下にあるかで回転方向を決定
			{
				while (target_p > 0)
				{
					ra(ps); // ra: スタックAを上に1つシフト（一番上が一番下に）
					target_p--;
				}
			}
			else
			{
				while (target_p < a_size)
				{
					rra(ps); // rra: スタックAを下に1つシフト（一番下が一番上に）
					target_p++;
				}
			}
			pb(ps);
		}
	}

}

void	move_a_to_b(t_ps *ps)
{
	int	min;
	int	max;
	int	range;

	if (ps == NULL || ps->a == NULL || ps->a->top == NULL)
		put_error_and_exit(ERR_STACK);
	while (ps->a->size > 5)
	{
		min = find_min(ps->a);
		max = find_max(ps->a);
		range = max - min;
		ps->group1 = min + range / 4;
		ps->group2 = min + 2 * range / 4;
		ps->group3 = min + 3 * range / 4;
		move_group(ps, ps->group3, max + 1);
			printf("~group1~!!!!!!!!!!!!!!!!!\n");
		move_group(ps, ps->group2, ps->group3);
				printf("~group2~!!!!!!!!!!!!!!!!!\n");
		move_group(ps, ps->group1, ps->group2);
				printf("~group3~!!!!!!!!!!!!!!!!!\n");
		move_group(ps, min - 1, ps->group1);
				printf("~group4~!!!!!!!!!!!!!!!!!\n");
	}
	sort_small_stack(ps);
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
}

void	optimize_and_move_b_to_a(t_ps *ps)
{
	t_node	*inserted_p;
	int		inserted_value;

	if (ps->b->size == 0)
	{
		return ; // Bスタックが空の場合、何もしない
	}
	calculate_move_costs(ps);
	inserted_p = find_best_element(ps->b);
	inserted_value = (int)(intptr_t)inserted_p->content;
	move_to_b_top(ps, inserted_p);
	move_to_a_target(ps, (int)(intptr_t)inserted_p->content);
}

void	sort_stack(t_ps *ps)
{
	if (ps->a->size <= 5)
	{
		sort_small_stack(ps);
		return ;
	}
	move_a_to_b(ps);
	update_min_max_b(ps);
	while (ps->b->size > 0)
	{
		optimize_and_move_b_to_a(ps);
		if (ps->b->size == 0)
			break ;
	}
}
