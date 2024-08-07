/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:52:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/06 23:34:27 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_swap(t_node **top)
{
	t_node		*first;
	t_node		*second;
	intptr_t	tmp;

	if (*top == NULL || (*top)->next == NULL)
		put_error_and_exit(ERR_OP);
	first = *top;
	second = first->next;
	tmp = (intptr_t)first->content;
	first->content = second->content;
	second->content = (void *)(intptr_t)tmp;
}

void	sa(t_ps *ps)
{
	if (ps->a->size < 2)
		put_error_and_exit(ERR_OP);
	stack_swap(&ps->a->top);
	(*ps->operation_count)++;
}

void	sb(t_ps *ps)
{
	if (ps->b->size < 2)
		put_error_and_exit(ERR_OP);
	stack_swap(&ps->b->top);
	(*ps->operation_count)++;
}

void	ss(t_ps *ps)
{
	if (ps->a->size >= 2 && ps->b->size >= 2)
	{
		stack_swap(&ps->a->top);
		stack_swap(&ps->b->top);
		(*ps->operation_count)++;
	}
	else
		put_error_and_exit(ERR_OP);
}
