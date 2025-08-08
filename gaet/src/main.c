/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmanique <gmanique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:13:26 by gmanique          #+#    #+#             */
/*   Updated: 2025/08/08 22:47:38 by gmanique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

size_t	full_read(int fd, char **dest)
{
	char	*tmp;
	size_t	rep;
	size_t	tmp_int;

	*dest = malloc(1);
	if (!dest)
		return (-1);
	*dest[0] = '\0';
	tmp = malloc(100);
	if (!tmp)
		return (free(tmp), -1);
	tmp[99] = '\0';
	rep = 0;
	tmp_int = read(fd, tmp, 99);
	while(tmp_int)
	{
		*dest = free_join(*dest, tmp, 3);
		tmp = malloc(100);
		if (!tmp)
			return (free(tmp), -1);
		tmp[99] = '\0';
		tmp_int = read(fd, tmp, 99);
		rep += tmp_int;
	}
	return (free(tmp), rep);
}

int	is_a_64_binary(char *str, int bytesread)
{
	if (!str || bytesread < 5)
		return (0);
	return (str[0] == 0x7F
		&& str[1] == 0x45
		&& str[2] == 0x4C
		&& str[3] == 0x46
		&& str[4] == 2);
}

int	is_print(int c)
{
	return (c >= 32 && c <= 126);
}

void	print_str(char *str, int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		if (is_print(str[i]))
			printf("%c", str[i]);
		else if (str[i] == 0)
			printf(" ");
		else
			printf(".");
		// printf("\\0x%02X", str[i]);
		i++;
	}
}

void	print_hexa_str(char *str, int len)
{
	int i;

	i = 0;
	while(i < len)
	{
		printf("\\0x%02X", str[i]);
		i++;
	}
}

int	check_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1 || read(fd, NULL, 0) == -1)
		return (perror(filename), -1);
	return (fd);
}

int main(int ac, char **av)
{
	int		fd;
	char	*buffer;
	int		bytesread;

	if (ac != 2)
		return (write(2, "Please enter one executable as argument.\n", 42), EXIT_FAILURE);
	fd = check_file(av[1]);
	if (fd == -1)
		return (1);

	buffer = NULL;
	bytesread = full_read(fd, &buffer);
	if (!is_a_64_binary(buffer, bytesread))
		return (write(2, "File architecture not suported. x86_64 only\n", 45), free(buffer), close(fd), -1);
	
	// print_hexa_str(buffer, bytesread);
	print_str(buffer, bytesread);
	
	/*do_the_encryption*/
	close(fd);
	free(buffer);
	return (0);
}