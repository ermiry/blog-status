#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <signal.h>

#include <cerver/version.h>
#include <cerver/cerver.h>

#include <cerver/http/http.h>
#include <cerver/http/route.h>

#include <cerver/utils/log.h>
#include <cerver/utils/utils.h>

#include "blog.h"
#include "version.h"

#include "routes/service.h"

static Cerver *blog_api = NULL;

void end (int dummy) {
	
	if (blog_api) {
		cerver_stats_print (blog_api, false, false);
		cerver_log_msg ("\nHTTP Cerver stats:\n");
		http_cerver_all_stats_print ((HttpCerver *) blog_api->cerver_data);
		cerver_log_line_break ();
		cerver_teardown (blog_api);
	}

	(void) blog_end ();

	cerver_end ();

	exit (0);

}

static void blog_set_blog_routes (HttpCerver *http_cerver) {

	/* register top level route */
	// GET /api/status
	HttpRoute *blog_route = http_route_create (REQUEST_METHOD_GET, "api/status", blog_handler);
	http_cerver_route_register (http_cerver, blog_route);

	/* register blog children routes */
	// GET api/status/version
	HttpRoute *blog_version_route = http_route_create (REQUEST_METHOD_GET, "version", blog_version_handler);
	http_route_child_add (blog_route, blog_version_route);

}

static void start (void) {

	blog_api = cerver_create (
		CERVER_TYPE_WEB,
		"blog-api",
		PORT,
		PROTOCOL_TCP,
		false,
		CERVER_CONNECTION_QUEUE
	);

	if (blog_api) {
		/*** cerver configuration ***/
		cerver_set_receive_buffer_size (blog_api, CERVER_RECEIVE_BUFFER_SIZE);
		cerver_set_thpool_n_threads (blog_api, CERVER_TH_THREADS);
		cerver_set_handler_type (blog_api, CERVER_HANDLER_TYPE_THREADS);

		/*** web cerver configuration ***/
		HttpCerver *http_cerver = (HttpCerver *) blog_api->cerver_data;

		blog_set_blog_routes (http_cerver);

		// add a catch all route
		http_cerver_set_catch_all_route (http_cerver, blog_catch_all_handler);

		if (cerver_start (blog_api)) {
			cerver_log_error (
				"Failed to start %s!",
				blog_api->info->name->str
			);

			cerver_delete (blog_api);
		}
	}

	else {
		cerver_log_error ("Failed to create cerver!");

		cerver_delete (blog_api);
	}

}

int main (int argc, char const **argv) {

	srand (time (NULL));

	// register to the quit signal
	(void) signal (SIGINT, end);
	(void) signal (SIGTERM, end);

	// to prevent SIGPIPE when writting to socket
	(void) signal (SIGPIPE, SIG_IGN);

	cerver_init ();

	cerver_version_print_full ();

	blog_version_print_full ();

	if (!blog_init ()) {
		start ();
	}

	else {
		cerver_log_error ("Failed to init blog!");
	}

	(void) blog_end ();

	cerver_end ();

	return 0;

}