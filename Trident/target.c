//
//  target.c
//  Trident
//
//  Created by Simone Ferrini on 14/12/2016.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#include "target.h"

#include "target_ipad_3_1_ios_9_3_4.h"
#include "target_iphone_5_2_ios_9_2_1.h"

uint8_t *t_clock_ops_overwrite;
uint8_t t_clock_ops_overwrite_size;

uint8_t *t_uaf_payload_buffer;
uint8_t t_uaf_payload_buffer_size;

uint32_t *t_addresses_pool;
uint32_t *t_check_offsets_pool;

void target_select(void)
{
    target_t target;
    
    // target_ipad_3_1_ios_9_3_4_init(&target);
    target_iphone_5_2_ios_9_2_1_init(&target);
    
    t_clock_ops_overwrite = target.clock_ops_overwrite;
    t_clock_ops_overwrite_size = target.clock_ops_overwrite_size;
    t_uaf_payload_buffer = target.uaf_payload_buffer;
    t_uaf_payload_buffer_size = target.uaf_payload_buffer_size;
    t_addresses_pool = target.addresses_pool;
    t_check_offsets_pool = target.check_offsets_pool;
}
