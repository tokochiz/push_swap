/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/28 21:16:10 by ctokoyod         ###   ########.fr       */
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
t_list	*make_new_node(char **split_args, t_ps *ps)
{
	int		value;
	int		is_error;
	t_list	*new_node;

	printf("argv %s\n", *split_args);
	if (!is_valid_number(*split_args))
	{
		//free_ps(ps);
		put_error_and_exit(ps);
	}
	value = ft_atoi_with_error(*split_args, &is_error);
	if (is_error != 0)
	{
		//free_ps(ps);
		put_error_and_exit(ps);
	}
	new_node = ft_lstnew((void *)(intptr_t)value);
	if (new_node == NULL)
	{
		free_ps(ps);
		put_error_and_exit(ps);
	}
	return (new_node);
}

void	parse_args(int argc, char *argv[], t_ps *ps)
{
	int		i;
	int		j;
	t_list	*new_node;
	char	**split_args;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '"')
			split_args = ft_split(argv[i] + 1, ' ');
		else
			split_args = ft_split(argv[i], ' ');
		if (split_args == NULL)
		{
			free_ps(ps);
			put_error_and_exit(ps);
		}
		j = 0;
		while (split_args[j] != NULL)
		{
			if (ft_strlen(split_args[j]) == 0)
				continue ;
			new_node = make_new_node(&split_args[j], ps);
			ft_lstadd_back(&(ps->a->top), new_node);
			j++;
		}
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
