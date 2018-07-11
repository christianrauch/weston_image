/* Generated by wayland-scanner 1.12.0 */

#ifndef DESKTOP_SERVER_PROTOCOL_H
#define DESKTOP_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_desktop The desktop protocol
 * @section page_ifaces_desktop Interfaces
 * - @subpage page_iface_desktop_shell - create desktop widgets and helpers
 * - @subpage page_iface_screensaver - interface for implementing screensavers
 */
struct desktop_shell;
struct screensaver;
struct wl_output;
struct wl_surface;

/**
 * @page page_iface_desktop_shell desktop_shell
 * @section page_iface_desktop_shell_desc Description
 *
 * Traditional user interfaces can rely on this interface to define the
 * foundations of typical desktops. Currently it's possible to set up
 * background, panels and locking surfaces.
 * @section page_iface_desktop_shell_api API
 * See @ref iface_desktop_shell.
 */
/**
 * @defgroup iface_desktop_shell The desktop_shell interface
 *
 * Traditional user interfaces can rely on this interface to define the
 * foundations of typical desktops. Currently it's possible to set up
 * background, panels and locking surfaces.
 */
extern const struct wl_interface desktop_shell_interface;
/**
 * @page page_iface_screensaver screensaver
 * @section page_iface_screensaver_desc Description
 *
 * Only one client can bind this interface at a time.
 * @section page_iface_screensaver_api API
 * See @ref iface_screensaver.
 */
/**
 * @defgroup iface_screensaver The screensaver interface
 *
 * Only one client can bind this interface at a time.
 */
extern const struct wl_interface screensaver_interface;

#ifndef DESKTOP_SHELL_CURSOR_ENUM
#define DESKTOP_SHELL_CURSOR_ENUM
enum desktop_shell_cursor {
	DESKTOP_SHELL_CURSOR_NONE = 0,
	DESKTOP_SHELL_CURSOR_RESIZE_TOP = 1,
	DESKTOP_SHELL_CURSOR_RESIZE_BOTTOM = 2,
	DESKTOP_SHELL_CURSOR_ARROW = 3,
	DESKTOP_SHELL_CURSOR_RESIZE_LEFT = 4,
	DESKTOP_SHELL_CURSOR_RESIZE_TOP_LEFT = 5,
	DESKTOP_SHELL_CURSOR_RESIZE_BOTTOM_LEFT = 6,
	DESKTOP_SHELL_CURSOR_MOVE = 7,
	DESKTOP_SHELL_CURSOR_RESIZE_RIGHT = 8,
	DESKTOP_SHELL_CURSOR_RESIZE_TOP_RIGHT = 9,
	DESKTOP_SHELL_CURSOR_RESIZE_BOTTOM_RIGHT = 10,
	DESKTOP_SHELL_CURSOR_BUSY = 11,
};
#endif /* DESKTOP_SHELL_CURSOR_ENUM */

#ifndef DESKTOP_SHELL_PANEL_POSITION_ENUM
#define DESKTOP_SHELL_PANEL_POSITION_ENUM
enum desktop_shell_panel_position {
	DESKTOP_SHELL_PANEL_POSITION_TOP = 0,
	DESKTOP_SHELL_PANEL_POSITION_BOTTOM = 1,
	DESKTOP_SHELL_PANEL_POSITION_LEFT = 2,
	DESKTOP_SHELL_PANEL_POSITION_RIGHT = 3,
};
#endif /* DESKTOP_SHELL_PANEL_POSITION_ENUM */

#ifndef DESKTOP_SHELL_ERROR_ENUM
#define DESKTOP_SHELL_ERROR_ENUM
enum desktop_shell_error {
	/**
	 * an invalid argument was provided in a request
	 */
	DESKTOP_SHELL_ERROR_INVALID_ARGUMENT = 0,
};
#endif /* DESKTOP_SHELL_ERROR_ENUM */

/**
 * @ingroup iface_desktop_shell
 * @struct desktop_shell_interface
 */
struct desktop_shell_interface {
	/**
	 */
	void (*set_background)(struct wl_client *client,
			       struct wl_resource *resource,
			       struct wl_resource *output,
			       struct wl_resource *surface);
	/**
	 */
	void (*set_panel)(struct wl_client *client,
			  struct wl_resource *resource,
			  struct wl_resource *output,
			  struct wl_resource *surface);
	/**
	 */
	void (*set_lock_surface)(struct wl_client *client,
				 struct wl_resource *resource,
				 struct wl_resource *surface);
	/**
	 */
	void (*unlock)(struct wl_client *client,
		       struct wl_resource *resource);
	/**
	 * set grab surface
	 *
	 * The surface set by this request will receive a fake
	 * pointer.enter event during grabs at position 0, 0 and is
	 * expected to set an appropriate cursor image as described by the
	 * grab_cursor event sent just before the enter event.
	 */
	void (*set_grab_surface)(struct wl_client *client,
				 struct wl_resource *resource,
				 struct wl_resource *surface);
	/**
	 * desktop is ready to be shown
	 *
	 * Tell the server, that enough desktop elements have been drawn
	 * to make the desktop look ready for use. During start-up, the
	 * server can wait for this request with a black screen before
	 * starting to fade in the desktop, for instance. If the client
	 * parts of a desktop take a long time to initialize, we avoid
	 * showing temporary garbage.
	 * @since 2
	 */
	void (*desktop_ready)(struct wl_client *client,
			      struct wl_resource *resource);
	/**
	 * set panel position
	 *
	 * Tell the shell which side of the screen the panel is located.
	 * This is so that new windows do not overlap the panel and
	 * maximized windows maximize properly.
	 * @since 3
	 */
	void (*set_panel_position)(struct wl_client *client,
				   struct wl_resource *resource,
				   uint32_t position);
};

#define DESKTOP_SHELL_CONFIGURE 0
#define DESKTOP_SHELL_PREPARE_LOCK_SURFACE 1
#define DESKTOP_SHELL_GRAB_CURSOR 2

/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_CONFIGURE_SINCE_VERSION 1
/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_PREPARE_LOCK_SURFACE_SINCE_VERSION 1
/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_GRAB_CURSOR_SINCE_VERSION 1

/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_SET_BACKGROUND_SINCE_VERSION 1
/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_SET_PANEL_SINCE_VERSION 1
/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_SET_LOCK_SURFACE_SINCE_VERSION 1
/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_UNLOCK_SINCE_VERSION 1
/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_SET_GRAB_SURFACE_SINCE_VERSION 1
/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_DESKTOP_READY_SINCE_VERSION 2
/**
 * @ingroup iface_desktop_shell
 */
#define DESKTOP_SHELL_SET_PANEL_POSITION_SINCE_VERSION 3

/**
 * @ingroup iface_desktop_shell
 * Sends an configure event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
desktop_shell_send_configure(struct wl_resource *resource_, uint32_t edges, struct wl_resource *surface, int32_t width, int32_t height)
{
	wl_resource_post_event(resource_, DESKTOP_SHELL_CONFIGURE, edges, surface, width, height);
}

/**
 * @ingroup iface_desktop_shell
 * Sends an prepare_lock_surface event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
desktop_shell_send_prepare_lock_surface(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, DESKTOP_SHELL_PREPARE_LOCK_SURFACE);
}

/**
 * @ingroup iface_desktop_shell
 * Sends an grab_cursor event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
desktop_shell_send_grab_cursor(struct wl_resource *resource_, uint32_t cursor)
{
	wl_resource_post_event(resource_, DESKTOP_SHELL_GRAB_CURSOR, cursor);
}

/**
 * @ingroup iface_screensaver
 * @struct screensaver_interface
 */
struct screensaver_interface {
	/**
	 * set the surface type as a screensaver
	 *
	 * A screensaver surface is normally hidden, and only visible
	 * after an idle timeout.
	 */
	void (*set_surface)(struct wl_client *client,
			    struct wl_resource *resource,
			    struct wl_resource *surface,
			    struct wl_resource *output);
};


/**
 * @ingroup iface_screensaver
 */
#define SCREENSAVER_SET_SURFACE_SINCE_VERSION 1

#ifdef  __cplusplus
}
#endif

#endif
