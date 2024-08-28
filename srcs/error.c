/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:45:07 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/28 21:38:54 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_ps(t_ps *ps)
{
	if (ps != NULL)
	{
		if (ps->a != NULL)
		{
			if (ps->a->top != NULL)
				ft_lstclear(&(ps->a->top), NULL);
			free(ps->a);
			ps->a = NULL;
		}
		if (ps->b != NULL)
		{
			if (ps->b->top != NULL)
				ft_lstclear(&(ps->b->top), NULL);
			free(ps->b);
			ps->b = NULL;
		}
		if (ps->operation_count != NULL)
			free(ps->operation_count);
		if (ps->costs != NULL)
			free(ps->costs);
	}
}

void	put_error_and_exit(t_ps *ps)
{
	free_ps(ps);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	normal_exit(void)
{
	exit(EXIT_FAILURE);
}
