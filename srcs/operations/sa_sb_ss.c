/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:52:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/28 21:28:37 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_swap(t_node **top, t_ps *ps)
{
	t_node		*first;
	t_node		*second;
	intptr_t	tmp;

	if (*top == NULL || (*top)->next == NULL)
		put_error_and_exit(ps);
	first = *top;
	second = first->next;
	tmp = (intptr_t)first->content;
	first->content = second->content;
	second->content = (void *)(intptr_t)tmp;
}

void	sa(t_ps *ps)
{
	if (ps->a->size < 2)
		put_error_and_exit(ps);
	stack_swap(&ps->a->top, ps);
	ft_printf("sa\n");
	(*ps->operation_count)++;
}

void	sb(t_ps *ps)
{
	if (ps->b->size < 2)
		put_error_and_exit(ps);
	stack_swap(&ps->b->top, ps);
	ft_printf("sb\n");
	(*ps->operation_count)++;
}

void	ss(t_ps *ps)
{
	if (ps->a->size >= 2 && ps->b->size >= 2)
	{
		stack_swap(&ps->a->top, ps);
		stack_swap(&ps->b->top, ps);
		ft_printf("ss\n");
		(*ps->operation_count)++;
	}
	else
		put_error_and_exit(ps);
}
