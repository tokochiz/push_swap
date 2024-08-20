/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:45:07 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/20 23:29:31 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_error_and_exit(const char *msg)
{
	perror(msg);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
