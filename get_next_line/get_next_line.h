#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*get_new_line(int fd, char * buffer);
char	*get_before_new_line(char *buffer);
char	*get_after_new_line(char *buffer);
int		found_new_line(char *line);
char*	append_line(char *buffer, char *line);
void copy_string(char *buffer,char * line, char * result);
int	ft_strlen(char *str);
#endif

// #include "get_next_line.h"

// int	found_new_line(char *line)
// {
// 	size_t	i;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == '\n')
// 		{
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	ft_strlen(char *str)
// {
// 	size_t	i;

// 	if (!str)
// 	{
// 		return (0);
// 	}
// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// void copy_string(char *buffer,char * line, char * result)
// {
//     size_t i;
//     size_t j;
//     i = 0;
//     j = 0;
//     while(buffer[i])
//     {
//         result[i] = buffer[i];
//         i++;
//     }
//     while(line[j])
//         result[i++] = line[j++];

//     result[i] = '\0';
// }

// char	*append_line(char *buffer, char *line)
// {
// 	size_t	len;
// 	size_t	i;
// 	char	*result;
// 	size_t	j;

// 	if (!buffer)
// 	{
// 		buffer = malloc(1);
// 		if (!buffer)
// 			return (NULL);
// 		buffer = '\0';
// 	}
// 	len = ft_strlen(buffer) + ft_strlen(line);
// 	result = malloc(len + 1);
// 	if (!result)
// 		return (NULL);
// 	copy_string(buffer,line,result);
//     free(buffer);
//     return result;

// }










// #include "get_next_line.h"


// char	*get_new_line(int fd, char * buffer)
// {
//     char * line;
//     int char_read;
//     char_read = 1;
//     line  = malloc(BUFFER_SIZE+1);
//     if(!line)
//         return NULL;
//     while(!found_new_line(line) && char_read > 0)
//     {
//         char_read = read(fd,line,BUFFER_SIZE);
//         if(char_read = -1)
//         {
//             free(line);
//             free(buffer);
//             buffer = NULL;
//             return NULL;
//         }
//         line[char_read] = '\0';
//         buffer = append_line(buffer,line);
//     }
//     free(line);
//     return buffer;
// }


// char	  *get_next_line(int fd)
// {
//     static char  *buffer = NULL;
//     char * line;
//     if((fd < 0) || (BUFFER_SIZE <= 0))
//     {
//         return NULL;   
//     }
//     buffer = get_new_line(fd,buffer);
//     // line  = get_before_new_line(buffer);
//     // buffer = get_after_new_line(buffer);
//     printf("%s\n",buffer);
//     line = NULL;
//     return line;
// }

// int main()
// {
//     int fd = open("sample.txt", O_RDWR| O_CREAT | O_TRUNC, 0644);
//     write(fd,"Hello World",11);
//     lseek(fd,SEEK_SET,0);
//     char * result;
//     result = get_next_line(fd);
//     close(fd);
//     free(result);
// }