/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:37:23 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/28 21:29:59 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_bottom_to_top(t_stack *stack, t_ps *ps)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (stack->size < 2 || stack->top == NULL || stack->top->next == NULL)
		put_error_and_exit(ps);
	first = stack->top;
	last = ft_lstlast(first);
	second_last = first;
	while (second_last->next != last)
	{
		second_last = second_last->next;
	}
	last->next = first;
	stack->top = last;
	second_last->next = NULL;
}

void	rra(t_ps *ps)
{
	if (ps->a->size < 2)
		put_error_and_exit(ps);
	rotate_bottom_to_top(ps->a, ps);
	ft_printf("rra\n");
	(*ps->operation_count)++;
}

void	rrb(t_ps *ps)
{
	if (ps->b->size < 2)
		put_error_and_exit(ps);
	rotate_bottom_to_top(ps->b, ps);
	ft_printf("rrb\n");
	(*ps->operation_count)++;
}

void	rrr(t_ps *ps)
{
	if (ps->a->size >= 2 && ps->b->size >= 2)
	{
		rotate_bottom_to_top(ps->a, ps);
		rotate_bottom_to_top(ps->b, ps);
		ft_printf("rrr\n");
		(*ps->operation_count)++;
	}
	else
		put_error_and_exit(ps);
}
