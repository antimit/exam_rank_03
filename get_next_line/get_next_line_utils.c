#include "get_next_line.h"

int	found_new_line(char *line)
{
  
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
	{
		return (0);
	}
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void copy_string(char *buffer,char * line, char * result)
{
    size_t i;
    size_t j;
    i = 0;
    j = 0;
    while(buffer[i])
    {
        result[i] = buffer[i];
        i++;
    }
    while(line[j])
        result[i++] = line[j++];

    result[i] = '\0';
}

char	*append_line(char *buffer, char *line)
{
	size_t	len;
	char	*result;

	if (!buffer)
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	len = ft_strlen(buffer) + ft_strlen(line);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	copy_string(buffer,line,result);
    free(buffer);
    return result;

}
