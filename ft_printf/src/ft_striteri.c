/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yohya <yohya@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 18:27:06 by yohya             #+#    #+#             */
/*   Updated: 2025/10/26 12:11:02 by yohya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// static void	to_upper(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = (char)toupper((unsigned char)*c);
// }

// int main(void)
// {
// 	char s[] = "helloworld";
// 	ft_striteri(s, to_upper);
// 	printf("%s\n", s);
// 	return (0);
// }
