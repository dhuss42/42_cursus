/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:23:13 by dhuss             #+#    #+#             */
/*   Updated: 2024/07/04 12:37:31 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <stdint.h>
#include "push_swap.h"

/* void print_stack(t_list **stack)
{
	t_list *current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d -> ", *((int *)current_node->content));
		current_node = current_node->next;
	}
	printf("NULL\n"); // change to write with standard error
}

void	print_position(t_list **stack)
{
	t_list	*tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d [%d]\n", *((int *)tmp->content), tmp->index);
		// if (tmp->above_median == 0)
		// 	// printf("is in bottom half\n");
		// else
			// printf("is in top half\n");
		tmp = tmp->next;
	}
} */

void	populate_list(char **input, t_list **stack_a)
{
	t_list	*new_node;
	int		i;
	int		*p;

	i = 0;
	new_node = NULL;
	while (input[i] != NULL)
	{
		p = malloc(sizeof(int));
		if (p == NULL)
		{
			ft_lstclear(stack_a, delete_content);
			clear_split_values(input);
			exit(EXIT_FAILURE);
		}
		*p = ft_atoi(input[i]);
		new_node = ft_lstnew(p);
		ft_lstadd_back(stack_a, new_node);
		i++;
	}
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 5 && (lstsorted(stack_a) == 0))
		small_sort(size, stack_a, stack_b);
	else if ((lstsorted(stack_a) == 0))
		big_sort(stack_a, stack_b);
}

char	**multiple_args(int argc, char *argv[])
{
	int		i;
	int		j;
	char	**combined_args;

	i = 1;
	j = 0;
	combined_args = (char **)malloc(sizeof(char *) * argc); // + 1?
	if (!combined_args)
		return (NULL);
	while (i < argc)
	{
		combined_args[i - 1] = ft_strdup(argv[i]);
		if (!combined_args[i - 1])
		{
			while (j < i - 1)
				free(combined_args[j]);
			free(combined_args);
			return (NULL);
		}
		i++;
	}
	combined_args[argc - 1] = NULL;
	return (combined_args);
}

void	push_swap(char **input)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	error_check(input);
	populate_list(input, &stack_a);
	sort(&stack_a, &stack_b);
	clear_all(&stack_a, &stack_b, input);
}

int	main(int argc, char *argv[])
{
	char	**input;

	if (argc > 2)
	{
		input = multiple_args(argc, argv);
		push_swap(input);
	}
	else if (argc == 2)
	{
		if (!only_white_space(argv[1]))
		{
			input = ft_split(argv[1], ' ');
			push_swap(input);
		}
	}
	return (0);
}
