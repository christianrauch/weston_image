/* Generated by wayland-scanner 1.12.0 */

#ifndef FULLSCREEN_SHELL_CLIENT_PROTOCOL_H
#define FULLSCREEN_SHELL_CLIENT_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-client.h"

#ifdef  __cplusplus
extern "C" {
#endif

/**
 * @page page_fullscreen_shell The fullscreen_shell protocol
 * @section page_ifaces_fullscreen_shell Interfaces
 * - @subpage page_iface__wl_fullscreen_shell - Displays a single surface per output
 * - @subpage page_iface__wl_fullscreen_shell_mode_feedback - 
 */
struct _wl_fullscreen_shell;
struct _wl_fullscreen_shell_mode_feedback;
struct wl_output;
struct wl_surface;

/**
 * @page page_iface__wl_fullscreen_shell _wl_fullscreen_shell
 * @section page_iface__wl_fullscreen_shell_desc Description
 *
 * Displays a single surface per output.
 *
 * This interface provides a mechanism for a single client to display
 * simple full-screen surfaces.  While there technically may be multiple
 * clients bound to this interface, only one of those clients should be
 * shown at a time.
 *
 * To present a surface, the client uses either the present_surface or
 * present_surface_for_mode requests.  Presenting a surface takes effect
 * on the next wl_surface.commit.  See the individual requests for
 * details about scaling and mode switches.
 *
 * The client can have at most one surface per output at any time.
 * Requesting a surface be presented on an output that already has a
 * surface replaces the previously presented surface.  Presenting a null
 * surface removes its content and effectively disables the output.
 * Exactly what happens when an output is "disabled" is
 * compositor-specific.  The same surface may be presented on multiple
 * outputs simultaneously.
 *
 * Once a surface is presented on an output, it stays on that output
 * until either the client removes it or the compositor destroys the
 * output.  This way, the client can update the output's contents by
 * simply attaching a new buffer.
 * @section page_iface__wl_fullscreen_shell_api API
 * See @ref iface__wl_fullscreen_shell.
 */
/**
 * @defgroup iface__wl_fullscreen_shell The _wl_fullscreen_shell interface
 *
 * Displays a single surface per output.
 *
 * This interface provides a mechanism for a single client to display
 * simple full-screen surfaces.  While there technically may be multiple
 * clients bound to this interface, only one of those clients should be
 * shown at a time.
 *
 * To present a surface, the client uses either the present_surface or
 * present_surface_for_mode requests.  Presenting a surface takes effect
 * on the next wl_surface.commit.  See the individual requests for
 * details about scaling and mode switches.
 *
 * The client can have at most one surface per output at any time.
 * Requesting a surface be presented on an output that already has a
 * surface replaces the previously presented surface.  Presenting a null
 * surface removes its content and effectively disables the output.
 * Exactly what happens when an output is "disabled" is
 * compositor-specific.  The same surface may be presented on multiple
 * outputs simultaneously.
 *
 * Once a surface is presented on an output, it stays on that output
 * until either the client removes it or the compositor destroys the
 * output.  This way, the client can update the output's contents by
 * simply attaching a new buffer.
 */
extern const struct wl_interface _wl_fullscreen_shell_interface;
/**
 * @page page_iface__wl_fullscreen_shell_mode_feedback _wl_fullscreen_shell_mode_feedback
 * @section page_iface__wl_fullscreen_shell_mode_feedback_api API
 * See @ref iface__wl_fullscreen_shell_mode_feedback.
 */
/**
 * @defgroup iface__wl_fullscreen_shell_mode_feedback The _wl_fullscreen_shell_mode_feedback interface
 */
extern const struct wl_interface _wl_fullscreen_shell_mode_feedback_interface;

#ifndef _WL_FULLSCREEN_SHELL_CAPABILITY_ENUM
#define _WL_FULLSCREEN_SHELL_CAPABILITY_ENUM
/**
 * @ingroup iface__wl_fullscreen_shell
 * capabilities advertised by the compositor
 *
 * Various capabilities that can be advertised by the compositor.  They
 * are advertised one-at-a-time when the wl_fullscreen_shell interface is
 * bound.  See the wl_fullscreen_shell.capability event for more details.
 *
 * ARBITRARY_MODE:
 * This is a hint to the client that indicates that the compositor is
 * capable of setting practically any mode on its outputs.  If this
 * capability is provided, wl_fullscreen_shell.present_surface_for_mode
 * will almost never fail and clients should feel free to set whatever
 * mode they like.  If the compositor does not advertise this, it may
 * still support some modes that are not advertised through wl_global.mode
 * but it is less likely.
 *
 * CURSOR_PLANE:
 * This is a hint to the client that indicates that the compositor can
 * handle a cursor surface from the client without actually compositing.
 * This may be because of a hardware cursor plane or some other mechanism.
 * If the compositor does not advertise this capability then setting
 * wl_pointer.cursor may degrade performance or be ignored entirely.  If
 * CURSOR_PLANE is not advertised, it is recommended that the client draw
 * its own cursor and set wl_pointer.cursor(NULL).
 */
enum _wl_fullscreen_shell_capability {
	/**
	 * compositor is capable of almost any output mode
	 */
	_WL_FULLSCREEN_SHELL_CAPABILITY_ARBITRARY_MODES = 1,
	/**
	 * compositor has a separate cursor plane
	 */
	_WL_FULLSCREEN_SHELL_CAPABILITY_CURSOR_PLANE = 2,
};
#endif /* _WL_FULLSCREEN_SHELL_CAPABILITY_ENUM */

#ifndef _WL_FULLSCREEN_SHELL_PRESENT_METHOD_ENUM
#define _WL_FULLSCREEN_SHELL_PRESENT_METHOD_ENUM
/**
 * @ingroup iface__wl_fullscreen_shell
 * different method to set the surface fullscreen
 *
 * Hints to indicate to the compositor how to deal with a conflict
 * between the dimensions of the surface and the dimensions of the
 * output. The compositor is free to ignore this parameter.
 */
enum _wl_fullscreen_shell_present_method {
	/**
	 * no preference, apply default policy
	 */
	_WL_FULLSCREEN_SHELL_PRESENT_METHOD_DEFAULT = 0,
	/**
	 * center the surface on the output
	 */
	_WL_FULLSCREEN_SHELL_PRESENT_METHOD_CENTER = 1,
	/**
	 * scale the surface, preserving aspect ratio, to the largest size that will fit on the output
	 */
	_WL_FULLSCREEN_SHELL_PRESENT_METHOD_ZOOM = 2,
	/**
	 * scale the surface, preserving aspect ratio, to fully fill the output cropping if needed
	 */
	_WL_FULLSCREEN_SHELL_PRESENT_METHOD_ZOOM_CROP = 3,
	/**
	 * scale the surface to the size of the output ignoring aspect ratio
	 */
	_WL_FULLSCREEN_SHELL_PRESENT_METHOD_STRETCH = 4,
};
#endif /* _WL_FULLSCREEN_SHELL_PRESENT_METHOD_ENUM */

#ifndef _WL_FULLSCREEN_SHELL_ERROR_ENUM
#define _WL_FULLSCREEN_SHELL_ERROR_ENUM
/**
 * @ingroup iface__wl_fullscreen_shell
 * wl_fullscreen_shell error values
 *
 * These errors can be emitted in response to wl_fullscreen_shell requests
 */
enum _wl_fullscreen_shell_error {
	/**
	 * present_method is not known
	 */
	_WL_FULLSCREEN_SHELL_ERROR_INVALID_METHOD = 0,
};
#endif /* _WL_FULLSCREEN_SHELL_ERROR_ENUM */

/**
 * @ingroup iface__wl_fullscreen_shell
 * @struct _wl_fullscreen_shell_listener
 */
struct _wl_fullscreen_shell_listener {
	/**
	 * advertises a capability of the compositor
	 *
	 * Advertises a single capability of the compositor.
	 *
	 * When the wl_fullscreen_shell interface is bound, this event is
	 * emitted once for each capability advertised. Valid capabilities
	 * are given by the wl_fullscreen_shell.capability enum. If clients
	 * want to take advantage of any of these capabilities, they should
	 * use a wl_display.sync request immediately after binding to
	 * ensure that they receive all the capability events.
	 */
	void (*capability)(void *data,
			   struct _wl_fullscreen_shell *_wl_fullscreen_shell,
			   uint32_t capabilty);
};

/**
 * @ingroup _wl_fullscreen_shell_iface
 */
static inline int
_wl_fullscreen_shell_add_listener(struct _wl_fullscreen_shell *_wl_fullscreen_shell,
				  const struct _wl_fullscreen_shell_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) _wl_fullscreen_shell,
				     (void (**)(void)) listener, data);
}

#define _WL_FULLSCREEN_SHELL_RELEASE 0
#define _WL_FULLSCREEN_SHELL_PRESENT_SURFACE 1
#define _WL_FULLSCREEN_SHELL_PRESENT_SURFACE_FOR_MODE 2

/**
 * @ingroup iface__wl_fullscreen_shell
 */
#define _WL_FULLSCREEN_SHELL_CAPABILITY_SINCE_VERSION 1

/**
 * @ingroup iface__wl_fullscreen_shell
 */
#define _WL_FULLSCREEN_SHELL_RELEASE_SINCE_VERSION 1
/**
 * @ingroup iface__wl_fullscreen_shell
 */
#define _WL_FULLSCREEN_SHELL_PRESENT_SURFACE_SINCE_VERSION 1
/**
 * @ingroup iface__wl_fullscreen_shell
 */
#define _WL_FULLSCREEN_SHELL_PRESENT_SURFACE_FOR_MODE_SINCE_VERSION 1

/** @ingroup iface__wl_fullscreen_shell */
static inline void
_wl_fullscreen_shell_set_user_data(struct _wl_fullscreen_shell *_wl_fullscreen_shell, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) _wl_fullscreen_shell, user_data);
}

/** @ingroup iface__wl_fullscreen_shell */
static inline void *
_wl_fullscreen_shell_get_user_data(struct _wl_fullscreen_shell *_wl_fullscreen_shell)
{
	return wl_proxy_get_user_data((struct wl_proxy *) _wl_fullscreen_shell);
}

static inline uint32_t
_wl_fullscreen_shell_get_version(struct _wl_fullscreen_shell *_wl_fullscreen_shell)
{
	return wl_proxy_get_version((struct wl_proxy *) _wl_fullscreen_shell);
}

/** @ingroup iface__wl_fullscreen_shell */
static inline void
_wl_fullscreen_shell_destroy(struct _wl_fullscreen_shell *_wl_fullscreen_shell)
{
	wl_proxy_destroy((struct wl_proxy *) _wl_fullscreen_shell);
}

/**
 * @ingroup iface__wl_fullscreen_shell
 *
 * Release the binding from the wl_fullscreen_shell interface
 *
 * This destroys the server-side object and frees this binding.  If
 * the client binds to wl_fullscreen_shell multiple times, it may wish
 * to free some of those bindings.
 */
static inline void
_wl_fullscreen_shell_release(struct _wl_fullscreen_shell *_wl_fullscreen_shell)
{
	wl_proxy_marshal((struct wl_proxy *) _wl_fullscreen_shell,
			 _WL_FULLSCREEN_SHELL_RELEASE);

	wl_proxy_destroy((struct wl_proxy *) _wl_fullscreen_shell);
}

/**
 * @ingroup iface__wl_fullscreen_shell
 *
 * Present a surface on the given output.
 *
 * If the output is null, the compositor will present the surface on
 * whatever display (or displays) it thinks best.  In particular, this
 * may replace any or all surfaces currently presented so it should
 * not be used in combination with placing surfaces on specific
 * outputs.
 *
 * The method parameter is a hint to the compositor for how the surface
 * is to be presented.  In particular, it tells the compositor how to
 * handle a size mismatch between the presented surface and the
 * output.  The compositor is free to ignore this parameter.
 *
 * The "zoom", "zoom_crop", and "stretch" methods imply a scaling
 * operation on the surface.  This will override any kind of output
 * scaling, so the buffer_scale property of the surface is effectively
 * ignored.
 */
static inline void
_wl_fullscreen_shell_present_surface(struct _wl_fullscreen_shell *_wl_fullscreen_shell, struct wl_surface *surface, uint32_t method, struct wl_output *output)
{
	wl_proxy_marshal((struct wl_proxy *) _wl_fullscreen_shell,
			 _WL_FULLSCREEN_SHELL_PRESENT_SURFACE, surface, method, output);
}

/**
 * @ingroup iface__wl_fullscreen_shell
 *
 * Presents a surface on the given output for a particular mode.
 *
 * If the current size of the output differs from that of the surface,
 * the compositor will attempt to change the size of the output to
 * match the surface.  The result of the mode-switch operation will be
 * returned via the provided wl_fullscreen_shell_mode_feedback object.
 *
 * If the current output mode matches the one requested or if the
 * compositor successfully switches the mode to match the surface,
 * then the mode_successful event will be sent and the output will
 * contain the contents of the given surface.  If the compositor
 * cannot match the output size to the surface size, the mode_failed
 * will be sent and the output will contain the contents of the
 * previously presented surface (if any).  If another surface is
 * presented on the given output before either of these has a chance
 * to happen, the present_cancelled event will be sent.
 *
 * Due to race conditions and other issues unknown to the client, no
 * mode-switch operation is guaranteed to succeed.  However, if the
 * mode is one advertised by wl_output.mode or if the compositor
 * advertises the ARBITRARY_MODES capability, then the client should
 * expect that the mode-switch operation will usually succeed.
 *
 * If the size of the presented surface changes, the resulting output
 * is undefined.  The compositor may attempt to change the output mode
 * to compensate.  However, there is no guarantee that a suitable mode
 * will be found and the client has no way to be notified of success
 * or failure.
 *
 * The framerate parameter specifies the desired framerate for the
 * output in mHz.  The compositor is free to ignore this parameter.  A
 * value of 0 indicates that the client has no preference.
 *
 * If the value of wl_output.scale differs from wl_surface.buffer_scale,
 * then the compositor may choose a mode that matches either the buffer
 * size or the surface size.  In either case, the surface will fill the
 * output.
 */
static inline struct _wl_fullscreen_shell_mode_feedback *
_wl_fullscreen_shell_present_surface_for_mode(struct _wl_fullscreen_shell *_wl_fullscreen_shell, struct wl_surface *surface, struct wl_output *output, int32_t framerate)
{
	struct wl_proxy *feedback;

	feedback = wl_proxy_marshal_constructor((struct wl_proxy *) _wl_fullscreen_shell,
			 _WL_FULLSCREEN_SHELL_PRESENT_SURFACE_FOR_MODE, &_wl_fullscreen_shell_mode_feedback_interface, surface, output, framerate, NULL);

	return (struct _wl_fullscreen_shell_mode_feedback *) feedback;
}

/**
 * @ingroup iface__wl_fullscreen_shell_mode_feedback
 * @struct _wl_fullscreen_shell_mode_feedback_listener
 */
struct _wl_fullscreen_shell_mode_feedback_listener {
	/**
	 * mode switch succeeded
	 *
	 * This event indicates that the attempted mode switch operation
	 * was successful. A surface of the size requested in the mode
	 * switch will fill the output without scaling.
	 *
	 * Upon receiving this event, the client should destroy the
	 * wl_fullscreen_shell_mode_feedback object.
	 */
	void (*mode_successful)(void *data,
				struct _wl_fullscreen_shell_mode_feedback *_wl_fullscreen_shell_mode_feedback);
	/**
	 * mode switch failed
	 *
	 * This event indicates that the attempted mode switch operation
	 * failed. This may be because the requested output mode is not
	 * possible or it may mean that the compositor does not want to
	 * allow it.
	 *
	 * Upon receiving this event, the client should destroy the
	 * wl_fullscreen_shell_mode_feedback object.
	 */
	void (*mode_failed)(void *data,
			    struct _wl_fullscreen_shell_mode_feedback *_wl_fullscreen_shell_mode_feedback);
	/**
	 * mode switch cancelled
	 *
	 * This event indicates that the attempted mode switch operation
	 * was cancelled. Most likely this is because the client requested
	 * a second mode switch before the first one completed.
	 *
	 * Upon receiving this event, the client should destroy the
	 * wl_fullscreen_shell_mode_feedback object.
	 */
	void (*present_cancelled)(void *data,
				  struct _wl_fullscreen_shell_mode_feedback *_wl_fullscreen_shell_mode_feedback);
};

/**
 * @ingroup _wl_fullscreen_shell_mode_feedback_iface
 */
static inline int
_wl_fullscreen_shell_mode_feedback_add_listener(struct _wl_fullscreen_shell_mode_feedback *_wl_fullscreen_shell_mode_feedback,
						const struct _wl_fullscreen_shell_mode_feedback_listener *listener, void *data)
{
	return wl_proxy_add_listener((struct wl_proxy *) _wl_fullscreen_shell_mode_feedback,
				     (void (**)(void)) listener, data);
}

/**
 * @ingroup iface__wl_fullscreen_shell_mode_feedback
 */
#define _WL_FULLSCREEN_SHELL_MODE_FEEDBACK_MODE_SUCCESSFUL_SINCE_VERSION 1
/**
 * @ingroup iface__wl_fullscreen_shell_mode_feedback
 */
#define _WL_FULLSCREEN_SHELL_MODE_FEEDBACK_MODE_FAILED_SINCE_VERSION 1
/**
 * @ingroup iface__wl_fullscreen_shell_mode_feedback
 */
#define _WL_FULLSCREEN_SHELL_MODE_FEEDBACK_PRESENT_CANCELLED_SINCE_VERSION 1


/** @ingroup iface__wl_fullscreen_shell_mode_feedback */
static inline void
_wl_fullscreen_shell_mode_feedback_set_user_data(struct _wl_fullscreen_shell_mode_feedback *_wl_fullscreen_shell_mode_feedback, void *user_data)
{
	wl_proxy_set_user_data((struct wl_proxy *) _wl_fullscreen_shell_mode_feedback, user_data);
}

/** @ingroup iface__wl_fullscreen_shell_mode_feedback */
static inline void *
_wl_fullscreen_shell_mode_feedback_get_user_data(struct _wl_fullscreen_shell_mode_feedback *_wl_fullscreen_shell_mode_feedback)
{
	return wl_proxy_get_user_data((struct wl_proxy *) _wl_fullscreen_shell_mode_feedback);
}

static inline uint32_t
_wl_fullscreen_shell_mode_feedback_get_version(struct _wl_fullscreen_shell_mode_feedback *_wl_fullscreen_shell_mode_feedback)
{
	return wl_proxy_get_version((struct wl_proxy *) _wl_fullscreen_shell_mode_feedback);
}

/** @ingroup iface__wl_fullscreen_shell_mode_feedback */
static inline void
_wl_fullscreen_shell_mode_feedback_destroy(struct _wl_fullscreen_shell_mode_feedback *_wl_fullscreen_shell_mode_feedback)
{
	wl_proxy_destroy((struct wl_proxy *) _wl_fullscreen_shell_mode_feedback);
}

#ifdef  __cplusplus
}
#endif

#endif
