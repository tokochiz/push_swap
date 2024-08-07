/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 19:53:59 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/06 23:36:14 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_ps *ps)
{
	t_node	*first;

	if (ps->b->size < 1)
		put_error_and_exit(ERR_OP_P);
	first = ps->b->top;
	ps->b->top = first->next;
	ps->b->size--;
	first->next = ps->a->top;
	ps->a->top = first;
	ps->a->size++;
	(*ps->operation_count)++;
}
void	pb(t_ps *ps)
{
	t_node	*first;

	if (ps->a->size < 1)
		put_error_and_exit(ERR_OP_P);
	first = ps->a->top;
	ps->a->top = first->next;
	ps->a->size--;
	first->next = ps->b->top;
	ps->b->top = first;
	ps->b->size++;
	(*ps->operation_count)++;
}
