#ifndef _BLOG_H_
#define _BLOG_H_

#include "runtime.h"

#define DEFAULT_PORT					5000

struct _HttpResponse;

extern RuntimeType RUNTIME;

extern unsigned int PORT;

extern unsigned int CERVER_RECEIVE_BUFFER_SIZE;
extern unsigned int CERVER_TH_THREADS;
extern unsigned int CERVER_CONNECTION_QUEUE;

// inits blog main values
extern unsigned int blog_init (void);

// ends blog main values
extern unsigned int blog_end (void);

#endif