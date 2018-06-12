/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amedvedi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 13:14:02 by amedvedi          #+#    #+#             */
/*   Updated: 2018/01/22 19:14:26 by amedvedi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

/*
** Opens both files and saves the file descriptor (fd).
** Then passes fd and fd2 to get_next_line in random order.
** You can change order of reading from files like you want to.
** I also added i to show return values.
** Feel free to edit;)
*/

int        main(int argc, char **argv)
{
    int        fd;
    int        fd2;
    char    *line;
    int i;

    if (argc == 3) 
    {
       fd = open(argv[1], O_RDONLY);
        fd2 = open(argv[2], O_RDONLY);
    }
    else
        return (0);
    i = get_next_line(fd, &line);
    printf("|%s| :::::::ret fd:%d\n", line, i);
    free(line);
    i = get_next_line(fd2, &line);
    printf("|%s| :::::::ret fd:%d\n", line, i);
    free(line);
    i = get_next_line(fd, &line);
    printf("|%s| :::::::ret fd:%d\n", line, i);
    free(line);
    i = get_next_line(fd2, &line);
    printf("|%s| :::::::ret fd:%d\n", line, i);
    free(line);
    if (argc == 2)
        close(fd);
    return 0;
}
