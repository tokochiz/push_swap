/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:05:12 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/15 19:53:25 by  ctokoyod        ###   ########.fr       */
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
# define ERR_STACK "ERROR stack "

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
//!!~~~~~~~~~~~~debag ~~~~~~~~~~~~
void	print_stack(t_stack *stack, char stack_name);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void				parse_args(int argc, char *argv[], t_ps *stack);
void				initialize(t_ps *stack);
void				check_argc(int argc);

// error
void				put_error_and_exit(const char *msg);

// is_sorted
bool				is_sorted(t_ps *stack);

// sort_stack
void	move_a_to_b(t_ps *ps);
void	sort_stack(t_ps *ps);


void        sa(t_ps *stack);
void        sb(t_ps *stack);
void        ss(t_ps *stack);
void        pa(t_ps *stack);
void        pb(t_ps *stack);
void        ra(t_ps *stack);
void        rb(t_ps *stack);
void        rr(t_ps *stack);
void        rra(t_ps *stack);
void        rrb(t_ps *stack);
void        rrr(t_ps *stack);

#endif