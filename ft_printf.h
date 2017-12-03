/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 12:05:27 by dhill             #+#    #+#             */
/*   Updated: 2017/12/02 23:55:26 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

# define MIN(a, b) ((a) > (b) ? (b) : (a))
# define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef enum	e_length
{
	unset,
	hh,
	h,
	ll,
	l,
	j,
	t,
	z
}				t_length;

typedef struct	s_flags
{
	int			p_prefix_f;
	int			upper_f;
	int			neg_f;
	int			sp_f;
	int			plus_f;
	int			zero_f;
	int			pound_f;
	int			width_f;
	int			pre_f;
}				t_fl;

typedef struct	s_info
{
	int			base;
	int			width;
	int			pre;
	t_length	length;
	char		type;
	int			total_len;
	int			str_len;
	int			num_len;
	t_fl		fl;
}				t_info;

/*
** handle.c && ft_printf.c
*/
int		ft_printf(char *string, ...);
int		handle_c(t_info *var, va_list ap);
int		handle_s(t_info *var, va_list ap);
int		handle_d_i(t_info *var, va_list ap);
int		handle_u_x_o_p(t_info *var, va_list ap);

/*
** parsing.c
*/
int		parse_flags(t_info *var, char *s);
int     parse_width(t_info *var, char *s);
int     parse_precision(t_info *var, char *s);
int     parse_length(t_info *var, char *s);
int     parse_type(t_info *var, char *s);

/*
** helper.c
*/
char	*create_str(t_info *var, char *str);
char	*create_padding(t_info *var, char *str);
char	*create_signed(t_info *var, long long num);
char	*create_unsigned(t_info *var, unsigned long long num);
char	*create_num_padding(t_info *var);

/*
** signed_utility.c
*/
int		ll_len(long long n);
int		prefix_len(t_info *var, long long num);
char	*itoa_helper(t_info *var, long long n, char *new_s, int num_len);
void	sign_help(t_info *var, long long n, char *padding, char *num);

/*
** unsigned_utility.c
*/
int		ll_u_len(t_info *var, unsigned long long n);
int		u_prefix_len(t_info *var, unsigned long long num);
char	*itoa_u_helper(t_info *var, unsigned long long n, char *n_s, int n_len);
#endif
