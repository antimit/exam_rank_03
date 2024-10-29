#include "get_next_line.h"

char	*get_new_line(int fd, char *buffer)
{
	char	*line;
	int		char_read;

	char_read = 1;
	line = malloc(BUFFER_SIZE + 1);
	line[0] = '\0';
	if (!line)
		return (NULL);
	while (!found_new_line(line) && char_read > 0)
	{
		char_read = read(fd, line, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		line[char_read] = '\0';
		buffer = append_line(buffer, line);
	}
	free(line);
	return (buffer);
}

char	*get_before_new_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	if (!buffer[i])
	{
		return (NULL);
	}
	while (buffer[i] && buffer[i] != '\n')
		i++;
	result = malloc(i + 2);
	if (!result)
		return (NULL);
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		result[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
	{
		result[j] = '\n';
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*get_after_new_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*result;

	j = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')	
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	result = malloc(ft_strlen(buffer) - i + 1);
	if (!result)
		return (NULL);
	while (buffer[++i])
		result[j++] = buffer[i];
	result[j] = '\0';
	free(buffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buffer = get_new_line(fd, buffer);
	if (!buffer)
	{
		return (NULL);
	}
	line = get_before_new_line(buffer);
	buffer = get_after_new_line(buffer);
	return (line);
}

// int	main(void)
// {
// 	int fd = open("sample.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	// write(fd, "Hello World\n", 12);
//     // write(fd, "Hello World", 11);
//     write(fd,"Hello World",11);
// 	lseek(fd, SEEK_SET, 0);
// 	char *result;
//     // char *result1;
// 	result = get_next_line(fd);
//     // result1 = get_next_line(fd);
//     printf("%s\n",result);
//     // printf("%s\n",result1);
// 	close(fd);
// 	free(result);
//     // free(result1);
// }
