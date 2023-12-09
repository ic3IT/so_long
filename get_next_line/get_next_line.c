/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: yipzhang <yipzhang@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/24 22:11:50 by yipzhang      #+#    #+#                 */
/*   Updated: 2023/12/07 15:50:07 by yipzhang      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	not_valid_read(char **s, char **buffer)
{
	if (*s)
		free(*s);
	if (*buffer)
		free(*buffer);
	*s = NULL;
	*buffer = NULL;
}

char	*ft_read(int fd, char *s)
{
	int		i;
	char	*buffer;

	if (ft_newline(s))
		return (s);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		not_valid_read(&s, &buffer);
		return (NULL);
	}
	i = 1;
	while (i != 0 && !ft_newline(s))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if ((i == 0 && (!s || !s[0])) || i == -1)
		{
			not_valid_read(&s, &buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		s = ft_strjoin(s, buffer);
	}
	free(buffer);
	return (s);
}

char	*one_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	i = ft_count(s);
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*whats_left_str(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	i = ft_count(s);
	str = malloc(ft_strlen(s) - i + 1);
	if (!str)
	{
		free(s);
		return (NULL);
	}
	j = 0;
	while (s[i])
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*s = NULL;
	char		*str;

	if (!BUFFER_SIZE || fd < 0)
		return (NULL);
	s = ft_read(fd, s);
	if (!s || !*s)
	{
		free(s);
		s = NULL;
	}
	str = one_line(s);
	if (!str)
	{
		free(s);
		s = NULL;
	}
	s = whats_left_str(s);
	if (!s)
	{
		free(s);
		s = NULL;
	}
	return (str);
}

// #include <fcntl.h>      // for open()
// #include <unistd.h>     // for close()
// #include <stdio.h>      // for printf()
// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("1char.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening the file");
//         return (1);
//     }

//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);   // Free the line after using it
//     }
//     close(fd);
//     return (0);
// }
