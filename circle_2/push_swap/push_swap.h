/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:36:53 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/24 11:26:01 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_cost
{
	int		l_cost;
	int		c_cost;
	t_list	*tmp_b;
}	t_cost;

//--<>--error-checks--<>--//
void		error_check(char **split_values);
int			is_in_range(const char *str);
int			is_duplicate(char **split_values, int count);
int			is_equal(const char *s1, const char *s2);
int			is_integer(char *str);

//--<>--helpers--<>--//
const char	*trim_zeros(const char *str);
int			only_white_space(char *input);

//--<>--operations--<>--//
void		push(t_list **stack_a, t_list **stack_b);
void		push_a(t_list **stack_a, t_list **stack_b);
void		push_b(t_list **stack_a, t_list **stack_b);
void		swap(t_list **head);
void		swap_a(t_list **stack);
void		swap_b(t_list **stack);
void		ss(t_list **stack_a, t_list **stack_b);
void		rotate(t_list **stack);
void		rotate_a(t_list **stack);
void		rotate_b(t_list **stack);
void		rr(t_list **stack_a, t_list **stack_b);
void		reverse_rotate(t_list **stack);
void		reverse_rotate_a(t_list **stack);
void		reverse_rotate_b(t_list **stack);
void		rrr(t_list **stack_a, t_list **stack_b);

//--<>--clear--<>--//
void		clear_all(t_list **stack_a, t_list **stack_b, char **input);
void		clear_split_values(char **split_values);
void		delete_content(void *content);

//--<>--small-sort--<>--//
void		sort(t_list **stack_a, t_list **stack_b);
void		populate_list(char **input, t_list **stack_a);
int			lstsorted(t_list **stack_a);

//--<>--small-sort--<>--//
void		small_sort(int size, t_list **stack_a, t_list **stack_b);
void		sort_up_to_five(t_list **stack_a, t_list **stack_b);
void		move_min_to_top(t_list **stack_a, int smallest_index);
void		find_min(t_list **stack_a, int *smallest_index);
void		sort_three(t_list **stack_a);

//--<>--big-sort--<>--//
void		big_sort(t_list **stack_a, t_list **stack_b);
void		execute(t_list **stack_a, t_list **stack_b);
void		rotate_down(t_list **stack_a, t_list **stack_b, t_list *node);
void		algo_rrr(t_list **stack_a, t_list **stack_b, t_list *node);
void		rotate_up(t_list **stack_a, t_list **stack_b, t_list *node);
void		algo_rr(t_list **stack_a, t_list **stack_b, t_list *node);
void		final_rotate(t_list **stack_a);
t_list		*find_in_a(t_list **stack_a, int *j);

//--<>--temporary--<>--//
void		print_stack(t_list **stack);
void		print_position(t_list **stack);

//--<>--determine--<>--//
void		current_pos(t_list **stack_a);
void		targets(t_list **stack_a, t_list **stack_b);
void		target_loop(t_list **stack_a, t_list **pos_b);
t_list		*return_min(t_list **stack);
int			is_greater_than_all(t_list **stack_a, int value_b);

//--<>--cost-calculation-<>--//
void		calculate_price(t_list **stack_a, t_list **stack_b);
void		above_median(t_list **stack_a, t_list **stack_b, t_cost *cost);
void		rr_cost(t_list **stack_b, t_cost *cost);
void		below_median(t_list **stack_a, t_list **stack_b, t_cost *cost);
void		rrr_cost(t_list **stack_a, t_list **stack_b, t_cost *cost);
void		cheapest(int *c_cost, int *l_cost, t_list **pos, t_list **stack_b);

#endif