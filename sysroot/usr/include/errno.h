#ifndef ERRNO_H
#define ERRNO_H

#include <stddef.h>

#define EOVERFLOW 75  // Example error code for overflow
#define EPERM       1   // Operation not permitted
#define ENOENT      2   // No such file or directory
#define ESRCH       3   // No such process
#define EINTR       4   // Interrupted system call
#define EIO         5   // I/O error
#define ENXIO       6   // No such device or address
#define E2BIG       7   // Argument list too long
#define ENOEXEC     8   // Exec format error
#define EBADF       9   // Bad file descriptor
#define ECHILD     10   // No child processes
// Add more as needed...

extern int errno;

#endif // ERRNO_H
