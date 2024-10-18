/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efaustin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:35:50 by efaustin          #+#    #+#             */
/*   Updated: 2024/08/28 15:35:53 by efaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdarg.h>

void	ft_put_base(unsigned long long number, int *num_caract,
			char *base, unsigned int base_len);
void	ft_putstr_pf(char *str, int *num_caract);
void	ft_putchar_pf(char c, int *num_caract);
void	ft_put_ptr(void *ptr, int *num_caract);
void	ft_putnbr(int number, int *num_caract);
int		ft_printf(const char *str, ...);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

#endif
