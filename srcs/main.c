/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/09/01 17:37:27 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_new_node(char **split_args, t_ps *ps)
{
	int		value;
	int		is_error;
	t_list	*new_node;

	if (!is_valid_number(*split_args))
		put_error_and_exit(ps);
	value = ft_atoi_with_error(*split_args, &is_error);
	if (is_error != 0 || value < INT_MIN || value > INT_MAX)
		put_error_and_exit(ps);
	new_node = ft_lstnew((void *)(intptr_t)value);
	if (new_node == NULL)
		put_error_and_exit(ps);
	ft_lstadd_back((&ps->a->top), new_node);
}

void	parse_args(int argc, char *argv[], t_ps *ps)
{
	int		i;
	int		j;
	char	**split_args;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '"')
			split_args = ft_split(argv[i] + 1, ' ');
		else
			split_args = ft_split(argv[i], ' ');
		if (split_args == NULL)
			put_error_and_exit(ps);
		j = 0;
		while (split_args[j] != NULL)
		{
			if (ft_strlen(split_args[j]) != 0)
				make_new_node(&split_args[j], ps);
			j++;
		}
		free_string_array(split_args);
		i++;
	}
	ps->a->size = ft_lstsize(ps->a->top);
}

void	initialize(t_ps *ps)
{
	ps->a = (t_stack *)malloc(sizeof(t_stack));
	ps->b = (t_stack *)malloc(sizeof(t_stack));
	ps->operation_count = malloc(sizeof(int));
	ps->costs = (t_costs *)malloc(sizeof(t_costs));
	if (ps->a == NULL || ps->b == NULL || ps->operation_count == NULL
		|| ps->costs == NULL)
		put_error_and_exit(ps);
	ps->a->top = NULL;
	ps->a->size = 0;
	ps->b->top = NULL;
	ps->b->size = 0;
	*ps->operation_count = 0;
	ps->costs->type = 1;
}

void	check_argc(int argc, t_ps *ps)
{
	if (argc == 1)
		normal_exit();
	if (argc < 2)
		put_error_and_exit(ps);
}

int	main(int argc, char *argv[])
{
	t_ps	ps;

	check_argc(argc, &ps);
	initialize(&ps);
	parse_args(argc - 1, argv + 1, &ps);
	if (is_sorted(&ps) != TRUE)
		sort_stack(&ps);
	free_ps(&ps);
	return (0);
}
