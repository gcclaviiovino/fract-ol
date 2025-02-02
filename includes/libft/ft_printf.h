/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liovino <liovino@student.42.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:38:57 by liovino           #+#    #+#             */
/*   Updated: 2025/01/27 21:52:10 by liovino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		print_me(va_list args, const char arg);
int		print_c(int c);
int		print_str(char *str);
int		print_num(int n);
int		print_unum(unsigned int n);
int		print_hex(unsigned int num, char arg);
int		print_point(void *pointer);
int		fill_ptr(char **pointer, uintptr_t num);
int		prefix(char **pointer);
int		usize(unsigned long int nb, size_t base);
char	*ft_uitoa_base(unsigned long int n_l, int base);
char	*ft_case_changer(char *str, char type);
char	*ft_itoa_hex(unsigned long int n_l, int base);

#endif