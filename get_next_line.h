/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 16:56:19 by jobject           #+#    #+#             */
/*   Updated: 2022/02/15 18:17:37 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
size_t	ft_strlen(const char	*str);
void	*ft_memcpy(void	*dest, const void	*src, size_t	num);
char	*ft_strjoin(char	*s1, char const	*s2);
char	*ft_strdup(const char	*str);

#endif