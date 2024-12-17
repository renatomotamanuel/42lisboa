/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:50:11 by rmota-ma          #+#    #+#             */
/*   Updated: 2024/12/17 18:34:12 by scorpot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

# define LC_HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"
# define DEC "0123456789"

typedef struct s_stack_node
{
	int		nbr;
	int		index;
	int		push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int		ft_printf(const char *s, ...);
int		ft_putchar_fd(int c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putunbr_base_fd(unsigned long bnb, int fd, char *base, unsigned int bs);
int		ft_putperc_fd(int fd);
int		ft_check_char(const char *s, va_list args);
int		ft_putnbr_base_fd(int n, int fd, char *base, int bs);
int		ft_putptr_fd(void *n, int fd, char *base, unsigned int bs);
char	**ft_split(char *s, char c);

#endif