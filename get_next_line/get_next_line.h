/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:43:20 by hongbaki          #+#    #+#             */
/*   Updated: 2023/01/03 11:43:24 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*read_save_all(int fd, char *static_buffer);
char	*oneline(char *static_buffer);
char	*next_line(char *static_buffer);
char	*get_next_line(int fd);
char	*ft_strjoin(char *left_str, char *buff);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);

#endif
