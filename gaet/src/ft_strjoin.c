/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmanique <gmanique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 22:31:00 by gmanique          #+#    #+#             */
/*   Updated: 2025/08/08 22:37:36 by gmanique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

char	*ft_strdup(char	*src)
{
	char	*rep;
	int		i;

	if (!src)
		return (NULL);
	rep = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!rep)
		return (NULL);
	i = 0;
	while (src[i])
	{
		rep[i] = src[i];
		i++;
	}
	rep[i] = '\0';
	return (rep);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rep;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (ft_strdup((char *)s1));
	rep = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (rep == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		rep[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		rep[i + j] = s2[j];
		j++;
	}
	rep[i + j] = '\0';
	return (rep);
}

char	*free_join(char *s1, char *s2, int free_type)
{
	char	*rep;

	rep = ft_strjoin(s1, s2);
	if ((free_type & 1) && s1)
	{
		free(s1);
		s1 = NULL;
	}
	if ((free_type & 2) && s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (rep);
}

