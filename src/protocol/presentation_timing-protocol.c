/* Generated by wayland-scanner 1.12.0 */

/*
 * Copyright © 2013-2014 Collabora, Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include <stdlib.h>
#include <stdint.h>
#include "wayland-util.h"

extern const struct wl_interface presentation_feedback_interface;
extern const struct wl_interface wl_output_interface;
extern const struct wl_interface wl_surface_interface;

static const struct wl_interface *types[] = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&wl_surface_interface,
	&presentation_feedback_interface,
	&wl_output_interface,
};

static const struct wl_message presentation_requests[] = {
	{ "destroy", "", types + 0 },
	{ "feedback", "on", types + 7 },
};

static const struct wl_message presentation_events[] = {
	{ "clock_id", "u", types + 0 },
};

WL_EXPORT const struct wl_interface presentation_interface = {
	"presentation", 1,
	2, presentation_requests,
	1, presentation_events,
};

static const struct wl_message presentation_feedback_events[] = {
	{ "sync_output", "o", types + 9 },
	{ "presented", "uuuuuuu", types + 0 },
	{ "discarded", "", types + 0 },
};

WL_EXPORT const struct wl_interface presentation_feedback_interface = {
	"presentation_feedback", 1,
	0, NULL,
	3, presentation_feedback_events,
};

