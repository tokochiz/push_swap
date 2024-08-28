/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:05:12 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/28 21:30:08 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/include/libft.h"
# include <stdbool.h>
# include <stdio.h>

# define ERR_ARGC "Invalid number of arguments\n"
# define ERR_MALLOC "Error malloc "
# define ERR_LST1 "Error list1"
# define ERR_LST2 "Error list2"
# define ERR_STACK "ERROR stack "
# define ERR_OP "ERROR operations "
# define ERR_OP_P "ERROR operations pa,pb"

# define EXIT_FAILURE 1
# define TRUE 1
# define FALSE 0

typedef t_list	t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
	int			*array;
}				t_stack;

typedef struct s_costs
{
	int			cost1;
	int			cost2;
	int			cost3;
	int			cost4;
	int			type;
}				t_costs;

typedef struct s_ps
{
	t_stack		*a;
	t_stack		*b;
	t_costs		*costs;
	char		**operation;
	int			*operation_count;
	int			group1;
	int			group2;
	int			group3;
	int			group4;
	int			min_b;
	int			max_b;
}				t_ps;

// main
void			printf_stack(t_stack *stack, char stack_name);
void			parse_args(int argc, char *argv[], t_ps *ps);
void			initialize(t_ps *ps);
void			check_argc(int argc, t_ps *ps);
void			free_ps(t_ps *ps);

// errorprint_stack
void			put_error_and_exit(t_ps *ps);
void			normal_exit(void);

// checker
bool			is_sorted(t_ps *ps);
int				is_valid_number(const char *str);

// find_median
void			swap(int *a, int *b);
int				partition(int *array, int left, int right);
int				quick_sort(int *array, int left, int right, int k);
int				find_median(t_stack *stack);

// sort_small_stack
void			sort_two(t_ps *ps);
void			sort_three(t_ps *ps);
void			sort_four(t_ps *ps);
void			sort_five(t_ps *ps);
void			sort_small_stack(t_ps *ps);

// min_max
int				find_min_position(t_stack *stack, t_ps *ps);
int				find_max_position(t_stack *stack, t_ps *ps);
int				find_min(t_stack *stack, t_ps *ps);
int				find_max(t_stack *stakc, t_ps *ps);

// sort_stack
void			final_rotate(t_ps *ps);
void			optimize_and_move_b_to_a(t_ps *ps);
void			sort_stack(t_ps *ps);

// cost_pattern
void			calculate_costs1(t_ps *ps, int position, int target_p);
void			calculate_costs2(t_ps *ps, int position, int target_p);
void			calculate_costs3(t_ps *ps, int position, int target_p);
void			calculate_costs4(t_ps *ps, int position, int target_p);

// cost
void			find_current_min_costs(t_ps *ps, t_node *current);
int				find_target_position(t_stack *stack, int value, t_ps *ps);
void			calculate_move_costs(t_ps *ps);
t_node			*find_min_cost(t_stack *stack, t_ps *ps);

// move
void			insert_value_in_a(t_ps *ps, int value);
void			move_top_of_b(t_ps *ps, t_node *target);
void			move_a_to_b(t_ps *ps);

// sa, sb, ss
void			stack_swap(t_node **top, t_ps *ps);
void			sa(t_ps *ps);
void			sb(t_ps *ps);
void			ss(t_ps *ps);

// pa, pb
void			pa(t_ps *ps);
void			pb(t_ps *ps);

// ra, rb, rr
void			rotate_top_to_bottom(t_stack *stack, t_ps *ps);
void			ra(t_ps *ps);
void			rb(t_ps *ps);
void			rr(t_ps *ps);

// rra, rrb, rrr
void			rotate_bottom_to_top(t_stack *stack, t_ps *ps);
void			rra(t_ps *ps);
void			rrb(t_ps *ps);
void			rrr(t_ps *ps);

#endif