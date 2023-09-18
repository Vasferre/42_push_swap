/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:07:45 by vasferre          #+#    #+#             */
/*   Updated: 2023/08/03 15:08:11 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	size_t			pos;
	long			order;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	print_action(char c, char a, int i);
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack **stack, char c);
void	ft_push(t_stack **from, t_stack **to, char c);
void	push_swap(int size, char **argv);
int		main(int argc, char **argv);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int i);
void	ft_rotate(t_stack **stack, char c);
void	ft_rrotate(t_stack **stack, char c);
void	solve(t_stack **stack_a, int argc);
void	sort_three(t_stack **stack_a, int arr[3]);
void	push_to_b(t_stack **stack_a, t_stack **stack_b, size_t size);
void	sort(t_stack **stack_a, t_stack **stack_b, size_t size);
int		duo_verify(t_stack **stack_a, int num);
t_stack	*new_node(char *argv, size_t *pos);
void	find_lowest(t_stack **stack_a, size_t size);
t_stack	*fill_stack(size_t size, char **argv);
t_stack	*ft_stacknew(int content, size_t pos, long order);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_n_atoi(const char *str, long *ret);
int		check_order(t_stack *stack);
t_stack	*find_next_lowest_num(t_stack *stack);
t_stack	*find_lowest_num(t_stack *stack);

#endif