/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:24:16 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/03 18:41:27 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int	n;

	n = 0;
	while (str1[n] == str2[n] != '\0' && str1[n] != '\0')
		n++;
	return (str1[n] - str2[n]);
}
