/* Pinos
 * Copyright (C) 2015 Wim Taymans <wim.taymans@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __PINOS_H__
#define __PINOS_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <pinos/client/context.h>
#include <pinos/client/introspect.h>
#include <pinos/client/log.h>
#include <pinos/client/loop.h>
#include <pinos/client/mem.h>
#include <pinos/client/thread-mainloop.h>
#include <pinos/client/properties.h>
#include <pinos/client/stream.h>
#include <pinos/client/subscribe.h>
#include <pinos/client/utils.h>

#include <spa/include/spa/id-map.h>

#define PINOS_DBUS_SERVICE "org.pinos"
#define PINOS_DBUS_OBJECT_PREFIX "/org/pinos"
#define PINOS_DBUS_OBJECT_SERVER PINOS_DBUS_OBJECT_PREFIX "/server"
#define PINOS_DBUS_OBJECT_CLIENT PINOS_DBUS_OBJECT_PREFIX "/client"
#define PINOS_DBUS_OBJECT_NODE PINOS_DBUS_OBJECT_PREFIX "/node"
#define PINOS_DBUS_OBJECT_LINK PINOS_DBUS_OBJECT_PREFIX "/link"

void pinos_init (int *argc, char **argv[]);

char * pinos_client_name (void);

void   pinos_fill_context_properties (PinosProperties *properties);
void   pinos_fill_stream_properties  (PinosProperties *properties);

PinosDirection pinos_direction_reverse (PinosDirection direction);

SpaIDMap * pinos_id_map_get_default (void);

#ifdef __cplusplus
}
#endif

#endif /* __PINOS_H__ */
