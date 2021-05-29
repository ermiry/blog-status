#ifndef _BLOG_ROUTES_SERVICE_H_
#define _BLOG_ROUTES_SERVICE_H_

struct _HttpReceive;
struct _HttpRequest;

// GET /api/blog
extern void blog_handler (
	const struct _HttpReceive *http_receive,
	const struct _HttpRequest *request
);

// GET /api/blog/version
extern void blog_version_handler (
	const struct _HttpReceive *http_receive,
	const struct _HttpRequest *request
);

// GET *
extern void blog_catch_all_handler (
	const struct _HttpReceive *http_receive,
	const struct _HttpRequest *request
);

#endif