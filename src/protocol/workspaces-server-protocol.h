/* Generated by wayland-scanner 1.12.0 */

#ifndef WORKSPACES_SERVER_PROTOCOL_H
#define WORKSPACES_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_workspaces The workspaces protocol
 * @section page_ifaces_workspaces Interfaces
 * - @subpage page_iface_workspace_manager - workspaces manager
 */
struct wl_surface;
struct workspace_manager;

/**
 * @page page_iface_workspace_manager workspace_manager
 * @section page_iface_workspace_manager_desc Description
 *
 * An interface for managing surfaces in workspaces.
 * @section page_iface_workspace_manager_api API
 * See @ref iface_workspace_manager.
 */
/**
 * @defgroup iface_workspace_manager The workspace_manager interface
 *
 * An interface for managing surfaces in workspaces.
 */
extern const struct wl_interface workspace_manager_interface;

/**
 * @ingroup iface_workspace_manager
 * @struct workspace_manager_interface
 */
struct workspace_manager_interface {
	/**
	 * move surface to workspace
	 *
	 * Move the given surface to the specified workspace.
	 */
	void (*move_surface)(struct wl_client *client,
			     struct wl_resource *resource,
			     struct wl_resource *surface,
			     uint32_t workspace);
};

#define WORKSPACE_MANAGER_STATE 0

/**
 * @ingroup iface_workspace_manager
 */
#define WORKSPACE_MANAGER_STATE_SINCE_VERSION 1

/**
 * @ingroup iface_workspace_manager
 */
#define WORKSPACE_MANAGER_MOVE_SURFACE_SINCE_VERSION 1

/**
 * @ingroup iface_workspace_manager
 * Sends an state event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
workspace_manager_send_state(struct wl_resource *resource_, uint32_t current, uint32_t count)
{
	wl_resource_post_event(resource_, WORKSPACE_MANAGER_STATE, current, count);
}

#ifdef  __cplusplus
}
#endif

#endif
