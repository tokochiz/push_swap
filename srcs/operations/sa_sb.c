/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:52:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/17 21:03:45 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_ps *ps)
{
	int		tmp;
	t_list	*first;
	t_list	*second;

	if (ps->a->size < 2)
		return ;
	first = ps->a->top;
	second = first->next;
	tmp = (intptr_t)first->content;
	first->content = second->content;
	second->content = (void *)(intptr_t)tmp;
	(*ps->operation_count)++;
}
