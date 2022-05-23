/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygbouri <ygbouri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 07:57:24 by ygbouri           #+#    #+#             */
/*   Updated: 2022/05/19 00:37:59 by ygbouri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
int		check(char *tab);
char	*ft_strjoing(char *s1, char *s2);
size_t	ft_strlenge(char *str);
char	*ft_strdupe(char *s);

#endif
