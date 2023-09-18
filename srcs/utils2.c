/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:08:22 by vasferre          #+#    #+#             */
/*   Updated: 2023/08/03 15:09:03 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_n_atoi(const char *str, long *ret)
{
	int	p_n;
	int	i;

	i = 0;
	p_n = 1;
	if (*str == '-' && *str)
	{
		p_n *= -1;
		str++;
	}
	if (!*str)
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			*ret = (*ret * 10) + (str[i++] - '0');
		else
			return (1);
		if (*ret * p_n > 2147483647 || *ret * p_n < -2147483648)
			return (1);
	}
	*ret = *ret * p_n;
	return (0);
}

int	check_order(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->next->value > stack->value)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

t_stack	*find_next_lowest_num(t_stack *stack)
{
	t_stack	*lowest_num;
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->order < 0)
		{
			lowest_num = ft_stacknew(tmp->value, tmp->pos, tmp->order);
			break ;
		}
		tmp = tmp->next;
	}
	while (stack)
	{
		if (stack->value < lowest_num->value && stack->order < 0)
		{
			lowest_num->value = stack->value;
			lowest_num->pos = stack->pos;
			lowest_num->order = stack->order;
		}
		stack = stack->next;
	}
	return (lowest_num);
}

t_stack	*find_lowest_num(t_stack *stack)
{
	t_stack	*lowest_num;

	lowest_num = ft_stacknew(stack->value, stack->pos, stack->order);
	while (stack)
	{
		if (stack->value < lowest_num->value)
		{
			lowest_num->value = stack->value;
			lowest_num->pos = stack->pos;
		}
		stack = stack->next;
	}
	return (lowest_num);
}
