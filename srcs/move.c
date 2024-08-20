/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:02:22 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/20 22:27:04 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_operations(t_ps *ps, int ra_count, int rra_count)
{
	int	ra_op;
	int	rra_op;

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
	int		position;

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_STACK);
	current = stack->top;
	position = 0;
	if (value < (int)(intptr_t)current->content)
		return (0);
	while (current->next != NULL)
	{
		if (value > (int)(intptr_t)current->content
			&& value < (int)(intptr_t)current->next->content)
			return (position + 1);
		current = current->next;
		position++;
	}
	return (position + 1);
}

void	move_to_a_target(t_ps *ps, int value, int pattern)
{
	int	target_p;
	int	a_size;
	int	ra_count;
	int	rra_count;
	int	originaltarget_p;

	ra_count = 0;
	rra_count = 0;
	pattern = 0;
	//	target_p = find_insertion_position(ps->a, value);
	target_p = find_target_position(ps->a, value);
	// printf("~~~~~~~~~~~target :%d \n", target_p);
	// printf_stack(ps->a, 'A');
	// printf_stack(ps->b, 'B');
	originaltarget_p = target_p;
	a_size = ps->a->size;
	if (target_p <= a_size / 2)
	{
		while (target_p > 0)
		{
			ra(ps);
			ra_count++;
			target_p--;
		}
	}
	else
	{
		while (target_p < a_size)
		{
			rra(ps);
			rra_count++;
			target_p++;
		}
	}
	pa(ps);
	printf_stack(ps->a, 'A');
	printf_stack(ps->b, 'B');
	printf("value :%d target_p %d size %d p %d\n", value, target_p, a_size,
		pattern);
	printf("~~~~~~~~~~~o :%d ra_c:%d rra_c:%d\n", originaltarget_p, ra_count,
		rra_count);
	// if ((originaltarget_p == 0 && value == find_max(ps->a)))
	// reverse_operations(ps, ra_count, rra_count);
	// if ((originaltarget_p == a_size - 1) && !is_sorted(ps))
	// ra(ps);
}
// 	printf("value :%d target_p %d size %d p %d\n", value, target_p, a_size / 2,
//		pattern);
// 	printf("~~a_target~~~~~~~~~~~~~\n");
// 	printf_stack(ps->a, 'A');
// 	printf_stack(ps->b, 'B');
// 	pa(ps);
// 	printf("~~ps~~~~~~~~~~~~~\n");
// 	printf_stack(ps->a, 'A');
// 	printf_stack(ps->b, 'B');

// 	reverse_operations(ps, ra_count, rra_count);
// printf("~~reverse~~~~~~~~~~~~~\n");
// 	printf_stack(ps->a, 'A');
// 	printf_stack(ps->b, 'B');

void	move_to_b_top(t_ps *ps, t_node *target, int pattern)
{
	int		position;
	t_node	*current;

	pattern = 0;
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
		{
			rb(ps);
		}
	}
	else
	{
		while (position++ < ps->b->size)
		{
			rrb(ps);
		}
	}
}
