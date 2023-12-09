/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yipzhang <yipzhang@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/23 17:07:37 by yipzhang      #+#    #+#                 */
/*   Updated: 2023/11/29 19:34:27 by yipzhang      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_newline(char *s);
char	*ft_strdup(char *s);
int		ft_count(char *s);
char	*ft_free(char **s);
char	*ft_free_on_error(char **s);

#endif
