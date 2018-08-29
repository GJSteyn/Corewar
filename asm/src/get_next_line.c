/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsteyn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 07:50:03 by gsteyn            #+#    #+#             */
/*   Updated: 2018/07/28 11:36:53 by gsteyn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file	*ft_new_file(const int fd)
{
	t_file	*new_file;

	new_file = (t_file*)malloc(sizeof(t_file));
	new_file->store = ft_strnew(BUFF_SIZE);
	new_file->index = 0;
	new_file->buffsize = 0;
	new_file->fd = fd;
	return (new_file);
}

static int		ft_read_buffer(char **line, t_file *file)
{
	int		ret_i;
	char	*temp;

	ret_i = 0;
	while ((*line)[ret_i - 1] != '\n')
	{
		if (file->index == file->buffsize)
		{
			ft_strclr(file->store);
			file->buffsize = read(file->fd, file->store, BUFF_SIZE);
			file->index = 0;
			if (file->buffsize == 0 && ft_strlen(*line) == 0)
				return (0);
			else if (file->buffsize == 0 && !(ft_strlen(*line) == 0))
				return (1);
			temp = ft_strnew(ft_strlen(*line) + file->buffsize);
			ft_strcpy(temp, *line);
			ft_strdel(line);
			*line = temp;
		}
		(*line)[ret_i++] = file->store[file->index++];
	}
	if ((*line)[ret_i - 1] == '\n')
		(*line)[ret_i - 1] = '\0';
	return (1);
}

static t_file	*ft_get_file(t_list *list, const int fd)
{
	t_file			*new;

	if (!list->content)
	{
		list->content = ft_new_file(fd);
		return (list->content);
	}
	while (list->content)
	{
		if (((t_file*)list->content)->fd == fd)
			return ((t_file*)list->content);
		else if (list->next)
			list = list->next;
		else
		{
			new = ft_new_file(fd);
			list->next = ft_lstnew(new, sizeof(t_file));
			ft_memdel((void**)(&new));
			return ((t_file*)(list->next->content));
		}
	}
	return (NULL);
}

static int		ft_remove_empty_links(t_list **list)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *list;
	if (!(t_file*)temp1->content)
		return (0);
	while (temp1->next)
	{
		if (((t_file*)temp1->next->content)->buffsize == 0)
		{
			temp2 = temp1->next;
			temp1->next = temp1->next->next;
			free(((t_file*)temp2->content)->store);
			free(temp2);
		}
		else
			temp1 = temp1->next;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	t_file			*curr_file;
	static t_list	*list;

	if (!line || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!list)
		list = ft_lstnew(NULL, sizeof(t_file));
	curr_file = ft_get_file(list, fd);
	if (!curr_file)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	ret = ft_read_buffer(line, curr_file);
	ft_remove_empty_links(&list);
	return (ret);
}
