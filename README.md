# get_next_line
### A C function that reads any valid file line by line until the end.

get_next_line is a project at <a href="http://www.42.fr/">42</a> that basically reads a file line by line. This project is frequently used in further projects.

### What is it made for?

###### Disclaimer: There are so many easier methods of doing this by using standard C functions. 
###### But the goal here is to be able to do it by using any functions from my libft and only the standard functions read, malloc and free.

I added a main file called main.c, it takes a file name as an argument, opens it and passes the file descriptor (fd) to get_next_line until get_next_line returns -1 or 0.
Also I added main2.c, it takes two file names as an arguments, to show usage of multiple descriptors.

### Note from subject:
##### get_next_line returns:
- ![#f03c15](https://placehold.it/15/f03c15/000000?text=+) `-1  an error has occurred`
- ![#1589F0](https://placehold.it/15/1589F0/000000?text=+) `0  the reading of whole file has been completed`
- ![#c5f015](https://placehold.it/15/c5f015/000000?text=+) `1  one line has been read`
 
### Download/clone this repo:

``` git clone https://github.com/AnneMedvedeva/get_next_line_42.git ```

### Get into it and build the library:

```cd get_next_line```
```make -C libft/```

### Build the executables:

```gcc -Wall -Wextra -Werror -I./libft/includes/ -L./libft -lft -o gnl_1 get_next_line.c main.c```

```gcc -Wall -Wextra -Werror -I./libft/includes/ -L./libft -lft -o gnl_2 get_next_line.c main2.c```

*You can change main files at the end or write your own.*

### Usage:

```./gnl_1 test_1.txt```

```./gnl_2 test_1.txt text_2.txt```
