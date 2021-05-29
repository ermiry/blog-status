#ifndef _BLOG_VERSION_H_
#define _BLOG_VERSION_H_

#define BLOG_VERSION				"0.1"
#define BLOG_VERSION_NAME			"Version 0.1"
#define BLOG_VERSION_DATE			"28/05/2021"
#define BLOG_VERSION_TIME			"23:30 CST"
#define BLOG_VERSION_AUTHOR			"Erick Salas"

// print full blog version information
extern void blog_version_print_full (void);

// print the version id
extern void blog_version_print_version_id (void);

// print the version name
extern void blog_version_print_version_name (void);

#endif