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
** Opens file and saves the file descriptor (fd).
** Then passes fd to get_next_line 2! times and print it out.
** You can change amount of read lines just copying 3 lines of code.
** I also added i to show return values.
** Feel free to edit;)
*/

int        main(int argc, char **argv)
{
    int        fd;
    char    *line;
    int i;

    if (argc == 2) 
    {
       fd = open(argv[1], O_RDONLY);
    }
    else
        return (0);
    i = get_next_line(fd, &line);
    printf("|%s| :::::::ret fd:%d\n", line, i);
    free(line);
    i = get_next_line(fd, &line);
    printf("|%s| :::::::ret fd:%d\n", line, i);
    free(line);
    close(fd);
    return 0;
}
