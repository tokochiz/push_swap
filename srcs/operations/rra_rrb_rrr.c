/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:37:23 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/06 23:36:26 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_bottom_to_top(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
    t_node *second_last;

	if (stack->size < 2  || stack->top == NULL || stack->top->next == NULL)
		put_error_and_exit(ERR_OP);
	first = stack->top;
	last = ft_lstlast(first);
    second_last = first;
	while(second_last->next != last)
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
		put_error_and_exit(ERR_OP);
	rotate_bottom_to_top(ps->a);
	(*ps->operation_count)++;
}

void	rrb(t_ps *ps)
{
	if (ps->b->size < 2)
		put_error_and_exit(ERR_OP);
	rotate_bottom_to_top(ps->b);
	(*ps->operation_count)++;
}

void	rrr(t_ps *ps)
{
	if (ps->a->size >= 2 && ps->b->size >= 2)
	{
		rotate_bottom_to_top(ps->a);
		rotate_bottom_to_top(ps->b);
		(*ps->operation_count)++;
	}
	else
		put_error_and_exit(ERR_OP);
}
