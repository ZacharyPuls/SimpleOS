#ifndef __SIMPLEOS_SIGNAL_H__
#define __SIMPLEOS_SIGNAL_H__

#include <sys/types.h>

#define SIG_DFL     0x01
#define SIG_ERR     0x02
#define SIG_HOLD    0x04
#define SIG_IGN     0x08

typedef int sig_atomic_t;
typedef int sigset_t;

union sigval {
    int sival_int;
    void *sival_ptr;
};

typedef struct sigevent {
    int sigev_notify;
    int sigev_signo;
    union sigval sigev_value;
    void (*sigev_notify_function)(union sigval);
    pthread_attr_t *sigev_notify_attributes;
} sigevent_t;

#define SIGEV_NONE      0x10
#define SIGEV_SIGNAL    0x20
#define SIGEV_THREAD    0x40

#define SIGRTMIN
#define SIGRTMAX

// TODO: Finish

#endif