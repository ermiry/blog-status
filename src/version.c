#include <cerver/utils/log.h>

#include "version.h"

// print full blog version information
void blog_version_print_full (void) {

	cerver_log_msg ("\nBlog Status Version: %s\n", BLOG_VERSION_NAME);
	cerver_log_msg ("Release Date & time: %s - %s\n", BLOG_VERSION_DATE, BLOG_VERSION_TIME);
	cerver_log_msg ("Author: %s\n", BLOG_VERSION_AUTHOR);

}

// print the version id
void blog_version_print_version_id (void) {

	cerver_log_msg ("\nBlog Status Version ID: %s\n", BLOG_VERSION);

}

// print the version name
void blog_version_print_version_name (void) {

	cerver_log_msg ("\nBlog Status Version: %s\n", BLOG_VERSION_NAME);

}