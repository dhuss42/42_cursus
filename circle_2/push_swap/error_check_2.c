/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:10:00 by dhuss             #+#    #+#             */
/*   Updated: 2024/06/24 14:35:48 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

const char	*trim_zeros(const char *str)
{
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	return (str);
}

int	is_equal(const char *s1, const char *s2)
{
	const char	*trim1;
	const char	*trim2;

	trim1 = trim_zeros(s1);
	trim2 = trim_zeros(s2);
	while (*trim1 && *trim2 && *trim1 == *trim2)
	{
		trim1++;
		trim2++;
	}
	if (*trim1 == '\0' && *trim2 == '\0')
		return (1);
	return (0);
}

int	is_duplicate(char **split_values, int count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (is_equal(split_values[i], split_values[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_in_range(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (result * sign > (2147483647 / 10)
			|| (result * sign == 2147483647 / 10
				&& (*str - 48) > (2147483647 % 10)))
			return (1);
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((result * sign > 2147483647) || (result * sign < -2147483648))
		return (1);
	return (0);
}
