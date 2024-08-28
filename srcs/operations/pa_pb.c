/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:53:59 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/28 21:12:22 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_ps *ps)
{
	t_node	*first;

	if (ps->b->size < 1)
		put_error_and_exit(ps);
	first = ps->b->top;
	ps->b->top = first->next;
	ps->b->size--;
	first->next = ps->a->top;
	ps->a->top = first;
	ps->a->size++;
	ft_printf("pa\n");
	(*ps->operation_count)++;
}

void	pb(t_ps *ps)
{
	t_node	*first;

	if (ps->a->size < 1)
		put_error_and_exit(ps);
	first = ps->a->top;
	ps->a->top = first->next;
	ps->a->size--;
	first->next = ps->b->top;
	ps->b->top = first;
	ps->b->size++;
	ft_printf("pb\n");
	(*ps->operation_count)++;
}
