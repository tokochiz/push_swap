/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:45:07 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/28 21:10:52 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	put_error_and_exit(const char *msg)
// {
// 	(void)msg;
// 	free_ps(ps);
// 	ft_putendl_fd("Error", 2);
// 	exit(EXIT_FAILURE);
// }
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
