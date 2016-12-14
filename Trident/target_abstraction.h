//
//  target_abstraction.h
//  Trident
//
//  Created by Simone Ferrini on 14/12/2016.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#ifndef target_abstraction_h
#define target_abstraction_h

typedef struct {
    
    uint8_t *clock_ops_overwrite;
    uint8_t clock_ops_overwrite_size;
    
    uint8_t *uaf_payload_buffer;
    uint8_t uaf_payload_buffer_size;
    
    uint32_t *addresses_pool;
    uint32_t *check_offsets_pool;
    
} target_t;

#endif /* target_abstraction_h */
