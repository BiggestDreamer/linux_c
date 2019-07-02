## what is file descriptor(fd)
sysio: open, close, read, write, lseek

# stdio rely on sysio

comparison of sysio and stdio

file shared

redirect: dup, dup2

atomic operation

sync, fsync, fdatasync

fcntl();
ioctl();

/dev/fd/


FILE   fopen() ----->  open()

# what is fd: index of array that stores the file address

ulimit -a : to check the max number of files that can be opened in one *process*   

0 ... 1023: 0 ---> stdin; 1 ---> stdout; 2 ---> stderr

r ---> O_RDONLY
r+ ---> O_RDWR

w ---> O_WRONLY | O_CREAT | O_TRUNC
w+ ---> O_RDWR | O_TRUNC | O_CREAT

-Wall

open() uses variable parameters

# comparison of *stdio* and *sysio*

## example:
difference: 
- speed: sysio faster
- throughput: stdio higher

interview: how to make a program faster:
1. speed:...
2. throughput:...  *

# so we should use stdio more to make the program faster

## tips:

can not mix the *stdio* and *sysio*!

convert: fileno, fdopen

to see a program how to sys call: strace



to see how long a program takes:
time ...


## atomic operation: solve comflict

can not divided!

## dup, dup2

fcntl(): fd manager
ioctl(): device manager

/dev/fd/  : a visual directory, shows the fd infos of current process
