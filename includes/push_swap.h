/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:05:12 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/08 21:45:44 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdbool.h>
# include <stdio.h>

# define ERR_ARGS "Invalid number of arguments\n"
# define ERR_MALLOC "Error malloc "
# define ERR_LST1 "Error list1"
# define ERR_LST2 "Error list2"

# define EXIT_FAILUREÏ 1
# define TRUE 1
# define FALSE 0

typedef t_list		t_node;
/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}
*/

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct s_ps
{
	t_stack			*a;
	t_stack			*b;
	char			**operation;
	int				*operation_count;
}					t_ps;

// main
void				parse_args(int argc, char *argv[], t_ps *stack);
void				initialize(t_ps *stack);
void				check_argc(int argc);

// error
void				put_error_and_exit(const char *msg);

// sort
bool				is_sorted(t_ps *stack);

#endif