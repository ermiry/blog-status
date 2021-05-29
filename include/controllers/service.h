#ifndef _BLOG_SERVICE_H_
#define _BLOG_SERVICE_H_

struct _HttpResponse;

extern struct _HttpResponse *blog_works;
extern struct _HttpResponse *current_version;

extern struct _HttpResponse *catch_all;

extern unsigned int blog_service_init (void);

extern void blog_service_end (void);

#endif