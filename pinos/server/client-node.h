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

#ifndef __PINOS_CLIENT_NODE_H__
#define __PINOS_CLIENT_NODE_H__

#include <pinos/server/node.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PINOS_CLIENT_NODE_URI                            "http://pinos.org/ns/client-node"
#define PINOS_CLIENT_NODE_PREFIX                         PINOS_CLIENT_NODE_URI "#"

typedef struct _PinosClientNode PinosClientNode;

/**
 * PinosClientNode:
 *
 * Pinos client node interface
 */
struct _PinosClientNode {
  PinosNode *node;

  PinosClient *client;
  PinosResource *resource;

  PINOS_SIGNAL (destroy_signal, (PinosListener   *listener,
                                 PinosClientNode *node));
};

PinosClientNode *  pinos_client_node_new              (PinosClient     *client,
                                                       uint32_t         id,
                                                       const char      *name,
                                                       PinosProperties *properties);
SpaResult          pinos_client_node_destroy          (PinosClientNode *node);

SpaResult          pinos_client_node_get_data_socket  (PinosClientNode *node, int *fd);

SpaResult          pinos_client_node_dispatch_message (PinosClientNode  *node,
                                                       PinosMessageType  type,
                                                       void             *message);

#ifdef __cplusplus
}
#endif

#endif /* __PINOS_CLIENT_NODE_H__ */
