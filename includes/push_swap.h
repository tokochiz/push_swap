/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:05:12 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/18 21:17:29 by  ctokoyod        ###   ########.fr       */
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
# define ERR_OP "ERROR operations "
# define ERR_OP_P "ERROR operations pa,pb"

# define EXIT_FAILURE 1
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
	int				*array;
}					t_stack;

typedef struct s_ps
{
	t_stack			*a;
	t_stack			*b;
	char			**operation;
	int				*operation_count;
	int				min_b;
	int				max_b;
}					t_ps;

// main
//!!~~~~~~~~~~~~debag ~~~~~~~~~~~~
void				printf_stack(t_stack *stack, char stack_name);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void				parse_args(int argc, char *argv[], t_ps *ps);
void				initialize(t_ps *ps);
void				check_argc(int argc);

// errorprint_stack
void				put_error_and_exit(const char *msg);

// is_sorted
bool				is_sorted(t_ps *ps);

// sort_stack
void				move_a_to_b(t_ps *ps);
void				sort_stack(t_ps *ps);

// min_max
void				update_min_max_b(t_ps *ps);
int					find_min(t_stack *stack);
int					find_max(t_stack *stakc);

// sort_stack
void				calculate_move_costs(t_ps *ps);
void				calculate_optimal_target(t_ps *ps);
void				set_best_move_method(t_ps *ps);
void				execute_move_method(t_ps *ps);
void				optimize_stack_a(t_ps *ps);

void				optimize_and_move_b_to_a(t_ps *ps);

// sa, sb, ss
void				stack_swap(t_list **top);
void				sa(t_ps *ps);
void				sb(t_ps *ps);
void				ss(t_ps *ps);

// pa, pb
void				pa(t_ps *ps);
void				pb(t_ps *ps);

// ra, rb, rr
void				stack_shift(t_stack *stack);
void				ra(t_ps *ps);
void				rb(t_ps *ps);
void				rr(t_ps *ps);

// rra, rrb, rrr
void				rra(t_ps *ps);
void				rrb(t_ps *ps);
void				rrr(t_ps *ps);

#endif