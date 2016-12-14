//
//  target.h
//  Trident
//
//  Created by Simone Ferrini on 14/12/2016.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#ifndef target_h
#define target_h

#include <stdio.h>

extern uint8_t *t_clock_ops_overwrite;
extern uint8_t t_clock_ops_overwrite_size;

extern uint8_t *t_uaf_payload_buffer;
extern uint8_t t_uaf_payload_buffer_size;

enum {
    T_WRITE_GADGET,
    T_PMAP,
    T_FLUSH_DCACHE,
    T_INVALIDATE_TLB,
    T_TFP,
    T_SETREUID,
    T_SERIALIZE,
    T_ADDRPERM
};

extern uint32_t *t_addresses_pool;

enum {
    T_PID,
    T_POSIX,
    T_MAC_PROC,
};

extern uint32_t *t_check_offsets_pool;

void target_select(void);

#endif /* target_h */
