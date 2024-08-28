/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 20:37:45 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/28 21:29:19 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_top_to_bottom(t_stack *stack, t_ps *ps)
{
	t_list	*first;
	t_list	*last;

	if (stack->size < 2 || stack->top == NULL || (stack->top->next == NULL))
		put_error_and_exit(ps);
	first = stack->top;
	last = ft_lstlast(first);
	stack->top = first->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_ps *ps)
{
	if (ps->a->size < 2)
		put_error_and_exit(ps);
	rotate_top_to_bottom(ps->a, ps);
	ft_printf("ra\n");
	(*ps->operation_count)++;
}

void	rb(t_ps *ps)
{
	if (ps->b->size < 2)
		put_error_and_exit(ps);
	rotate_top_to_bottom(ps->b, ps);
	ft_printf("rb\n");
	(*ps->operation_count)++;
}

void	rr(t_ps *ps)
{
	if (ps->a->size >= 2 && ps->b->size >= 2)
	{
		rotate_top_to_bottom(ps->a, ps);
		rotate_top_to_bottom(ps->b, ps);
		ft_printf("rra\n");
		(*ps->operation_count)++;
	}
	else
		put_error_and_exit(ps);
}
