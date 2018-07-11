/* Generated by wayland-scanner 1.12.0 */

#ifndef LINUX_DMABUF_SERVER_PROTOCOL_H
#define LINUX_DMABUF_SERVER_PROTOCOL_H

#include <stdint.h>
#include <stddef.h>
#include "wayland-server.h"

#ifdef  __cplusplus
extern "C" {
#endif

struct wl_client;
struct wl_resource;

/**
 * @page page_linux_dmabuf The linux_dmabuf protocol
 * @section page_ifaces_linux_dmabuf Interfaces
 * - @subpage page_iface_zlinux_dmabuf - factory for creating dmabuf-based wl_buffers
 * - @subpage page_iface_zlinux_buffer_params - parameters for creating a dmabuf-based wl_buffer
 * @section page_copyright_linux_dmabuf Copyright
 * <pre>
 *
 * Copyright © 2014, 2015 Collabora, Ltd.
 *
 * Permission to use, copy, modify, distribute, and sell this
 * software and its documentation for any purpose is hereby granted
 * without fee, provided that the above copyright notice appear in
 * all copies and that both that copyright notice and this permission
 * notice appear in supporting documentation, and that the name of
 * the copyright holders not be used in advertising or publicity
 * pertaining to distribution of the software without specific,
 * written prior permission.  The copyright holders make no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied
 * warranty.
 *
 * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS
 * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS, IN NO EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
 * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
 * THIS SOFTWARE.
 * </pre>
 */
struct wl_buffer;
struct zlinux_buffer_params;
struct zlinux_dmabuf;

/**
 * @page page_iface_zlinux_dmabuf zlinux_dmabuf
 * @section page_iface_zlinux_dmabuf_desc Description
 *
 * Following the interfaces from:
 * https://www.khronos.org/registry/egl/extensions/EXT/EGL_EXT_image_dma_buf_import.txt
 * and the Linux DRM sub-system's AddFb2 ioctl.
 *
 * This interface offers a way to create generic dmabuf-based
 * wl_buffers. Immediately after a client binds to this interface,
 * the set of supported formats is sent with 'format' events.
 *
 * The following are required from clients:
 *
 * - Clients must ensure that either all data in the dma-buf is
 * coherent for all subsequent read access or that coherency is
 * correctly handled by the underlying kernel-side dma-buf
 * implementation.
 *
 * - Don't make any more attachments after sending the buffer to the
 * compositor. Making more attachments later increases the risk of
 * the compositor not being able to use (re-import) an existing
 * dmabuf-based wl_buffer.
 *
 * The underlying graphics stack must ensure the following:
 *
 * - The dmabuf file descriptors relayed to the server will stay valid
 * for the whole lifetime of the wl_buffer. This means the server may
 * at any time use those fds to import the dmabuf into any kernel
 * sub-system that might accept it.
 *
 * To create a wl_buffer from one or more dmabufs, a client creates a
 * zlinux_dmabuf_params object with zlinux_dmabuf.create_params
 * request. All planes required by the intended format are added with
 * the 'add' request. Finally, 'create' request is issued. The server
 * will reply with either 'created' event which provides the final
 * wl_buffer or 'failed' event saying that it cannot use the dmabufs
 * provided.
 * @section page_iface_zlinux_dmabuf_api API
 * See @ref iface_zlinux_dmabuf.
 */
/**
 * @defgroup iface_zlinux_dmabuf The zlinux_dmabuf interface
 *
 * Following the interfaces from:
 * https://www.khronos.org/registry/egl/extensions/EXT/EGL_EXT_image_dma_buf_import.txt
 * and the Linux DRM sub-system's AddFb2 ioctl.
 *
 * This interface offers a way to create generic dmabuf-based
 * wl_buffers. Immediately after a client binds to this interface,
 * the set of supported formats is sent with 'format' events.
 *
 * The following are required from clients:
 *
 * - Clients must ensure that either all data in the dma-buf is
 * coherent for all subsequent read access or that coherency is
 * correctly handled by the underlying kernel-side dma-buf
 * implementation.
 *
 * - Don't make any more attachments after sending the buffer to the
 * compositor. Making more attachments later increases the risk of
 * the compositor not being able to use (re-import) an existing
 * dmabuf-based wl_buffer.
 *
 * The underlying graphics stack must ensure the following:
 *
 * - The dmabuf file descriptors relayed to the server will stay valid
 * for the whole lifetime of the wl_buffer. This means the server may
 * at any time use those fds to import the dmabuf into any kernel
 * sub-system that might accept it.
 *
 * To create a wl_buffer from one or more dmabufs, a client creates a
 * zlinux_dmabuf_params object with zlinux_dmabuf.create_params
 * request. All planes required by the intended format are added with
 * the 'add' request. Finally, 'create' request is issued. The server
 * will reply with either 'created' event which provides the final
 * wl_buffer or 'failed' event saying that it cannot use the dmabufs
 * provided.
 */
extern const struct wl_interface zlinux_dmabuf_interface;
/**
 * @page page_iface_zlinux_buffer_params zlinux_buffer_params
 * @section page_iface_zlinux_buffer_params_desc Description
 *
 * This temporary object is a collection of dmabufs and other
 * parameters that together form a single logical buffer. The temporary
 * object may eventually create one wl_buffer unless cancelled by
 * destroying it before requesting 'create'.
 *
 * Single-planar formats only require one dmabuf, however
 * multi-planar formats may require more than one dmabuf. For all
 * formats, 'add' request must be called once per plane (even if the
 * underlying dmabuf fd is identical).
 *
 * You must use consecutive plane indices ('plane_idx' argument for 'add')
 * from zero to the number of planes used by the drm_fourcc format code.
 * All planes required by the format must be given exactly once, but can
 * be given in any order. Each plane index can be set only once.
 * @section page_iface_zlinux_buffer_params_api API
 * See @ref iface_zlinux_buffer_params.
 */
/**
 * @defgroup iface_zlinux_buffer_params The zlinux_buffer_params interface
 *
 * This temporary object is a collection of dmabufs and other
 * parameters that together form a single logical buffer. The temporary
 * object may eventually create one wl_buffer unless cancelled by
 * destroying it before requesting 'create'.
 *
 * Single-planar formats only require one dmabuf, however
 * multi-planar formats may require more than one dmabuf. For all
 * formats, 'add' request must be called once per plane (even if the
 * underlying dmabuf fd is identical).
 *
 * You must use consecutive plane indices ('plane_idx' argument for 'add')
 * from zero to the number of planes used by the drm_fourcc format code.
 * All planes required by the format must be given exactly once, but can
 * be given in any order. Each plane index can be set only once.
 */
extern const struct wl_interface zlinux_buffer_params_interface;

/**
 * @ingroup iface_zlinux_dmabuf
 * @struct zlinux_dmabuf_interface
 */
struct zlinux_dmabuf_interface {
	/**
	 * unbind the factory
	 *
	 * Objects created through this interface, especially wl_buffers,
	 * will remain valid.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * create a temporary object for buffer parameters
	 *
	 * This temporary object is used to collect multiple dmabuf
	 * handles into a single batch to create a wl_buffer. It can only
	 * be used once and should be destroyed after an 'created' or
	 * 'failed' event has been received.
	 * @param params_id the new temporary
	 */
	void (*create_params)(struct wl_client *client,
			      struct wl_resource *resource,
			      uint32_t params_id);
};

#define ZLINUX_DMABUF_FORMAT 0

/**
 * @ingroup iface_zlinux_dmabuf
 */
#define ZLINUX_DMABUF_FORMAT_SINCE_VERSION 1

/**
 * @ingroup iface_zlinux_dmabuf
 */
#define ZLINUX_DMABUF_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zlinux_dmabuf
 */
#define ZLINUX_DMABUF_CREATE_PARAMS_SINCE_VERSION 1

/**
 * @ingroup iface_zlinux_dmabuf
 * Sends an format event to the client owning the resource.
 * @param resource_ The client's resource
 * @param format DRM_FORMAT code
 */
static inline void
zlinux_dmabuf_send_format(struct wl_resource *resource_, uint32_t format)
{
	wl_resource_post_event(resource_, ZLINUX_DMABUF_FORMAT, format);
}

#ifndef ZLINUX_BUFFER_PARAMS_ERROR_ENUM
#define ZLINUX_BUFFER_PARAMS_ERROR_ENUM
enum zlinux_buffer_params_error {
	/**
	 * the dmabuf_batch object has already been used to create a wl_buffer
	 */
	ZLINUX_BUFFER_PARAMS_ERROR_ALREADY_USED = 0,
	/**
	 * plane index out of bounds
	 */
	ZLINUX_BUFFER_PARAMS_ERROR_PLANE_IDX = 1,
	/**
	 * the plane index was already set
	 */
	ZLINUX_BUFFER_PARAMS_ERROR_PLANE_SET = 2,
	/**
	 * missing or too many planes to create a buffer
	 */
	ZLINUX_BUFFER_PARAMS_ERROR_INCOMPLETE = 3,
	/**
	 * format not supported
	 */
	ZLINUX_BUFFER_PARAMS_ERROR_INVALID_FORMAT = 4,
	/**
	 * invalid width or height
	 */
	ZLINUX_BUFFER_PARAMS_ERROR_INVALID_DIMENSIONS = 5,
	/**
	 * offset + stride * height goes out of dmabuf bounds
	 */
	ZLINUX_BUFFER_PARAMS_ERROR_OUT_OF_BOUNDS = 6,
};
#endif /* ZLINUX_BUFFER_PARAMS_ERROR_ENUM */

#ifndef ZLINUX_BUFFER_PARAMS_FLAGS_ENUM
#define ZLINUX_BUFFER_PARAMS_FLAGS_ENUM
enum zlinux_buffer_params_flags {
	/**
	 * contents are y-inverted
	 */
	ZLINUX_BUFFER_PARAMS_FLAGS_Y_INVERT = 1,
	/**
	 * content is interlaced
	 */
	ZLINUX_BUFFER_PARAMS_FLAGS_INTERLACED = 2,
	/**
	 * bottom field first
	 */
	ZLINUX_BUFFER_PARAMS_FLAGS_BOTTOM_FIRST = 4,
};
#endif /* ZLINUX_BUFFER_PARAMS_FLAGS_ENUM */

/**
 * @ingroup iface_zlinux_buffer_params
 * @struct zlinux_buffer_params_interface
 */
struct zlinux_buffer_params_interface {
	/**
	 * delete this object, used or not
	 *
	 * Cleans up the temporary data sent to the server for
	 * dmabuf-based wl_buffer creation.
	 */
	void (*destroy)(struct wl_client *client,
			struct wl_resource *resource);
	/**
	 * add a dmabuf to the temporary set
	 *
	 * This request adds one dmabuf to the set in this
	 * zlinux_buffer_params.
	 *
	 * The 64-bit unsigned value combined from modifier_hi and
	 * modifier_lo is the dmabuf layout modifier. DRM AddFB2 ioctl
	 * calls this the fb modifier, which is defined in drm_mode.h of
	 * Linux UAPI. This is an opaque token. Drivers use this token to
	 * express tiling, compression, etc. driver-specific modifications
	 * to the base format defined by the DRM fourcc code.
	 *
	 * This request raises the PLANE_IDX error if plane_idx is too
	 * large. The error PLANE_SET is raised if attempting to set a
	 * plane that was already set.
	 * @param fd dmabuf fd
	 * @param plane_idx plane index
	 * @param offset offset in bytes
	 * @param stride stride in bytes
	 * @param modifier_hi high 32 bits of layout modifier
	 * @param modifier_lo low 32 bits of layout modifier
	 */
	void (*add)(struct wl_client *client,
		    struct wl_resource *resource,
		    int32_t fd,
		    uint32_t plane_idx,
		    uint32_t offset,
		    uint32_t stride,
		    uint32_t modifier_hi,
		    uint32_t modifier_lo);
	/**
	 * create a wl_buffer from the given dmabufs
	 *
	 * This asks for creation of a wl_buffer from the added dmabuf
	 * buffers. The wl_buffer is not created immediately but returned
	 * via the 'created' event if the dmabuf sharing succeeds. The
	 * sharing may fail at runtime for reasons a client cannot predict,
	 * in which case the 'failed' event is triggered.
	 *
	 * The 'format' argument is a DRM_FORMAT code, as defined by the
	 * libdrm's drm_fourcc.h. The Linux kernel's DRM sub-system is the
	 * authoritative source on how the format codes should work.
	 *
	 * The 'flags' is a bitfield of the flags defined in enum "flags".
	 * 'y_invert' means the that the image needs to be y-flipped.
	 *
	 * Flag 'interlaced' means that the frame in the buffer is not
	 * progressive as usual, but interlaced. An interlaced buffer as
	 * supported here must always contain both top and bottom fields.
	 * The top field always begins on the first pixel row. The temporal
	 * ordering between the two fields is top field first, unless
	 * 'bottom_first' is specified. It is undefined whether
	 * 'bottom_first' is ignored if 'interlaced' is not set.
	 *
	 * This protocol does not convey any information about field rate,
	 * duration, or timing, other than the relative ordering between
	 * the two fields in one buffer. A compositor may have to estimate
	 * the intended field rate from the incoming buffer rate. It is
	 * undefined whether the time of receiving wl_surface.commit with a
	 * new buffer attached, applying the wl_surface state,
	 * wl_surface.frame callback trigger, presentation, or any other
	 * point in the compositor cycle is used to measure the frame or
	 * field times. There is no support for detecting missed or late
	 * frames/fields/buffers either, and there is no support whatsoever
	 * for cooperating with interlaced compositor output.
	 *
	 * The composited image quality resulting from the use of
	 * interlaced buffers is explicitly undefined. A compositor may use
	 * elaborate hardware features or software to deinterlace and
	 * create progressive output frames from a sequence of interlaced
	 * input buffers, or it may produce substandard image quality.
	 * However, compositors that cannot guarantee reasonable image
	 * quality in all cases are recommended to just reject all
	 * interlaced buffers.
	 *
	 * Any argument errors, including non-positive width or height,
	 * mismatch between the number of planes and the format, bad
	 * format, bad offset or stride, may be indicated by fatal protocol
	 * errors: INCOMPLETE, INVALID_FORMAT, INVALID_DIMENSIONS,
	 * OUT_OF_BOUNDS.
	 *
	 * Dmabuf import errors in the server that are not obvious client
	 * bugs are returned via the 'failed' event as non-fatal. This
	 * allows attempting dmabuf sharing and falling back in the client
	 * if it fails.
	 *
	 * This request can be sent only once in the object's lifetime,
	 * after which the only legal request is destroy. This object
	 * should be destroyed after issuing 'create' request. Attempting
	 * to use this object after issuing 'create' raises ALREADY_USED
	 * protocol error.
	 *
	 * It is not mandatory to issue 'create'. If a client wants to
	 * cancel the buffer creation, it can just destroy this object.
	 * @param width base plane width in pixels
	 * @param height base plane height in pixels
	 * @param format DRM_FORMAT code
	 * @param flags see enum flags
	 */
	void (*create)(struct wl_client *client,
		       struct wl_resource *resource,
		       int32_t width,
		       int32_t height,
		       uint32_t format,
		       uint32_t flags);
};

#define ZLINUX_BUFFER_PARAMS_CREATED 0
#define ZLINUX_BUFFER_PARAMS_FAILED 1

/**
 * @ingroup iface_zlinux_buffer_params
 */
#define ZLINUX_BUFFER_PARAMS_CREATED_SINCE_VERSION 1
/**
 * @ingroup iface_zlinux_buffer_params
 */
#define ZLINUX_BUFFER_PARAMS_FAILED_SINCE_VERSION 1

/**
 * @ingroup iface_zlinux_buffer_params
 */
#define ZLINUX_BUFFER_PARAMS_DESTROY_SINCE_VERSION 1
/**
 * @ingroup iface_zlinux_buffer_params
 */
#define ZLINUX_BUFFER_PARAMS_ADD_SINCE_VERSION 1
/**
 * @ingroup iface_zlinux_buffer_params
 */
#define ZLINUX_BUFFER_PARAMS_CREATE_SINCE_VERSION 1

/**
 * @ingroup iface_zlinux_buffer_params
 * Sends an created event to the client owning the resource.
 * @param resource_ The client's resource
 * @param buffer the newly created wl_buffer
 */
static inline void
zlinux_buffer_params_send_created(struct wl_resource *resource_, struct wl_resource *buffer)
{
	wl_resource_post_event(resource_, ZLINUX_BUFFER_PARAMS_CREATED, buffer);
}

/**
 * @ingroup iface_zlinux_buffer_params
 * Sends an failed event to the client owning the resource.
 * @param resource_ The client's resource
 */
static inline void
zlinux_buffer_params_send_failed(struct wl_resource *resource_)
{
	wl_resource_post_event(resource_, ZLINUX_BUFFER_PARAMS_FAILED);
}

#ifdef  __cplusplus
}
#endif

#endif
