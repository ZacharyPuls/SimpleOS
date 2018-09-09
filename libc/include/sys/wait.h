/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_WAIT_H__
#define __SIMPLEOS_WAIT_H__

#include <sys/types.h>
#include <signal.h>

#define WCONTINUED      0x0001
#define WNOHANG         0x0002
#define WUNTRACED       0x0004

#define WEXITSTATUS     0x0008
#define WIFCONTINUED    0x0010
#define WIFEXITED       0x0020
#define WIFSIGNALED     0x0040
#define WIFSTOPPED      0x0080
#define WSTOPSIG        0x0100
#define WTERMSIG        0x0200

#define WEXITED         0x0400
#define WNOWAIT         0x0800
#define WSTOPPED        0x1000

typedef enum idtype {
    P_ALL,
    P_PGID,
    P_PID
} idtype_t;

extern pid_t wait(int *);
extern int waitid(idtype_t, id_t, siginfo_t *, int);
extern pid_t waitpid(pid_t, int *, int);

#endif  // __SIMPLEOS_WAIT_H__
