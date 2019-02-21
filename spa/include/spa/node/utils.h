/* Simple Plugin API
 *
 * Copyright © 2019 Wim Taymans
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

#ifndef SPA_NODE_UTILS_H
#define SPA_NODE_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <spa/node/node.h>

struct spa_result_node_enum_params_data {
	struct spa_pod_builder *builder;
	struct spa_result_node_enum_params data;
};

static inline int spa_result_func_node_enum_params(void *data,
		uint32_t count, const void *result)
{
	struct spa_result_node_enum_params_data *d =
		(struct spa_result_node_enum_params_data *)data;
	const struct spa_result_node_enum_params *r =
		(const struct spa_result_node_enum_params *)result;
	uint32_t offset = d->builder->state.offset;
	spa_pod_builder_raw_padded(d->builder, r->param, SPA_POD_SIZE(r->param));
	d->data.next = r->next;
	d->data.param = SPA_MEMBER(d->builder->data, offset, struct spa_pod);
	return 1;
}

static inline int spa_node_enum_params_sync(struct spa_node *node,
			uint32_t id, uint32_t *index,
			const struct spa_pod *filter,
			struct spa_pod **param,
			struct spa_pod_builder *builder)
{
	struct spa_result_node_enum_params_data data = { builder, };
	int res;

	if ((res = spa_node_enum_params(node, id, *index, 1,
			filter, spa_result_func_node_enum_params, &data)) != 1)
		return res;
	*index = data.data.next;
	*param = data.data.param;
	return res;
}

static inline int spa_node_port_enum_params_sync(struct spa_node *node,
			enum spa_direction direction, uint32_t port_id,
			uint32_t id, uint32_t *index,
			const struct spa_pod *filter,
			struct spa_pod **param,
			struct spa_pod_builder *builder)
{
	struct spa_result_node_enum_params_data data = { builder, };
	int res;

	if ((res = spa_node_port_enum_params(node, direction, port_id, id, *index, 1,
			filter, spa_result_func_node_enum_params, &data)) != 1)
		return res;
	*index = data.data.next;
	*param = data.data.param;
	return res;
}

#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif /* SPA_NODE_UTILS_H */
