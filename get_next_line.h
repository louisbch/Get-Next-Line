/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbouchon <lbouchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:24:38 by lbouchon          #+#    #+#             */
/*   Updated: 2022/08/14 14:30:04 by lbouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# include <sys/types.h>
# include <limits.h>

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_read(int fd, char *stash);
char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*get_line(char *stash);
char	*ft_strdup(const char *src);
char	*ft_next(char *stash);

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

#endif