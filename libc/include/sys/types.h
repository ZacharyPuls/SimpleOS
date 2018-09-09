/**
 * Copyright 2018 Zachary Puls <zach@zachpuls.com>
 */

#ifndef __SIMPLEOS_TYPES_H__
#define __SIMPLEOS_TYPES_H__

#include <stdint.h>

typedef int32_t blkcnt_t;
typedef int32_t blksize_t;
typedef int32_t clock_t;
typedef uint32_t clockid_t;
typedef uint32_t dev_t;
typedef uint32_t fsblkcnt_t;
typedef uint32_t fsfilcnt_t;
typedef int32_t gid_t;
typedef uint32_t ino_t;
typedef uint32_t key_t;
typedef int32_t mode_t;
typedef int32_t nlink_t;
typedef int32_t off_t;
typedef int32_t pid_t;
typedef uint32_t pthread_attr_t;
typedef uint32_t pthread_barrier_t;
typedef uint32_t pthread_barrierattr_t;
typedef uint32_t pthread_cont_t;
typedef uint32_t pthread_condattr_t;
typedef uint32_t pthread_key_t;
typedef uint32_t pthread_mutex_t;
typedef uint32_t pthread_mutexattr_t;
typedef uint32_t pthread_once_t;
typedef uint32_t pthread_rwlock_t;
typedef uint32_t pthread_rwlockattr_t;
typedef uint32_t pthread_spinlock_t;
typedef uint32_t pthread_t;
typedef uint32_t size_t;
typedef int32_t ssize_t;
typedef int32_t suseconds_t;
typedef int32_t time_t;
typedef uint32_t timer_t;
typedef uint32_t trace_attr_t;
typedef uint32_t trace_event_id_t;
typedef uint32_t trace_event_set_t;
typedef uint32_t trace_id_t;
typedef int32_t uid_t;

union id_t {
    pid_t pid;
    uid_t uid;
    gid_t gid;  
};

#endif  // __SIMPLEOS_TYPES_H__
