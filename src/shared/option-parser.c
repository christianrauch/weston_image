/*
 * Copyright © 2012 Kristian Høgsberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "config.h"

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "config-parser.h"

static int
handle_option(const struct weston_option *option, char *value)
{
	char* p;

	switch (option->type) {
	case WESTON_OPTION_INTEGER:
		* (int32_t *) option->data = strtol(value, &p, 0);
		return *value && !*p;
	case WESTON_OPTION_UNSIGNED_INTEGER:
		* (uint32_t *) option->data = strtoul(value, &p, 0);
		return *value && !*p;
	case WESTON_OPTION_STRING:
		* (char **) option->data = strdup(value);
		return 1;
	default:
		assert(0);
	}
}

static int
long_option(const struct weston_option *options, int count, char *arg)
{
	int k, len;

	for (k = 0; k < count; k++) {
		if (!options[k].name)
			continue;

		len = strlen(options[k].name);
		if (strncmp(options[k].name, arg + 2, len) != 0)
			continue;

		if (options[k].type == WESTON_OPTION_BOOLEAN) {
			if (!arg[len + 2]) {
				* (int32_t *) options[k].data = 1;

				return 1;
			}
		} else if (arg[len+2] == '=') {
			return handle_option(options + k, arg + len + 3);
		}
	}

	return 0;
}

static int
short_option(const struct weston_option *options, int count, char *arg)
{
	int k;

	if (!arg[1])
		return 0;

	for (k = 0; k < count; k++) {
		if (options[k].short_name != arg[1])
			continue;

		if (options[k].type == WESTON_OPTION_BOOLEAN) {
			if (!arg[2]) {
				* (int32_t *) options[k].data = 1;

				return 1;
			}
		} else {
			return handle_option(options + k, arg + 2);
		}
	}

	return 0;
}

int
parse_options(const struct weston_option *options,
	      int count, int *argc, char *argv[])
{
	int i, j;

	for (i = 1, j = 1; i < *argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][1] == '-') {
				if (long_option(options, count, argv[i]))
					continue;
			} else if (short_option(options, count, argv[i]))
				continue;
		}
		argv[j++] = argv[i];
	}
	argv[j] = NULL;
	*argc = j;

	return j;
}
