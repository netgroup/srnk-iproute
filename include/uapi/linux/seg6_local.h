/*
 *  SR-IPv6 implementation
 *
 *  Author:
 *  David Lebrun <david.lebrun@uclouvain.be>
 *
 *
 *  This program is free software; you can redistribute it and/or
 *      modify it under the terms of the GNU General Public License
 *      as published by the Free Software Foundation; either version
 *      2 of the License, or (at your option) any later version.
 */

#ifndef _LINUX_SEG6_LOCAL_H
#define _LINUX_SEG6_LOCAL_H

#include <linux/seg6.h>
#include <linux/if_ether.h>

enum {
	SEG6_LOCAL_UNSPEC,
	SEG6_LOCAL_ACTION,
	SEG6_LOCAL_SRH,
	SEG6_LOCAL_TABLE,
	SEG6_LOCAL_NH4,
	SEG6_LOCAL_NH6,
	SEG6_LOCAL_IIF,
	SEG6_LOCAL_OIF,
	/* $Andrea */
	SEG6_LOCAL_NHETH,
	/* $Andrea */
	SEG6_LOCAL_TIMEOUT,
	__SEG6_LOCAL_MAX,
};
#define SEG6_LOCAL_MAX (__SEG6_LOCAL_MAX - 1)

enum {
	SEG6_LOCAL_ACTION_UNSPEC	= 0,
	/* node segment */
	SEG6_LOCAL_ACTION_END		= 1,
	/* adjacency segment (IPv6 cross-connect) */
	SEG6_LOCAL_ACTION_END_X		= 2,
	/* lookup of next seg NH in table */
	SEG6_LOCAL_ACTION_END_T		= 3,
	/* decap and L2 cross-connect */
	SEG6_LOCAL_ACTION_END_DX2	= 4,
	/* decap and IPv6 cross-connect */
	SEG6_LOCAL_ACTION_END_DX6	= 5,
	/* decap and IPv4 cross-connect */
	SEG6_LOCAL_ACTION_END_DX4	= 6,
	/* decap and lookup of DA in v6 table */
	SEG6_LOCAL_ACTION_END_DT6	= 7,
	/* decap and lookup of DA in v4 table */
	SEG6_LOCAL_ACTION_END_DT4	= 8,
	/* binding segment with insertion */
	SEG6_LOCAL_ACTION_END_B6	= 9,
	/* binding segment with encapsulation */
	SEG6_LOCAL_ACTION_END_B6_ENCAP	= 10,
	/* binding segment with MPLS encap */
	SEG6_LOCAL_ACTION_END_BM	= 11,
	/* lookup last seg in table */
	SEG6_LOCAL_ACTION_END_S		= 12,
	/* forward to SR-unaware VNF with static proxy */
	SEG6_LOCAL_ACTION_END_AS	= 13,
	/* forward to SR-unaware VNF with masquerading */
	SEG6_LOCAL_ACTION_END_AM	= 14,
	/*
	 * $Andrea
	 * forward to SR-unaware VNF with dinamic proxy
	 */
	SEG6_LOCAL_ACTION_END_AD	= 15,

	__SEG6_LOCAL_ACTION_MAX,
};

#define SEG6_LOCAL_ACTION_MAX (__SEG6_LOCAL_ACTION_MAX - 1)

/*
 * $Andrea
 * Those functions are exported in order to be accessible to other compilation
 * units, for instace iprules.c.
 */
const char *seg6local_format_action_type(int action);
int seg6local_read_action_type(const char *name);

#endif
