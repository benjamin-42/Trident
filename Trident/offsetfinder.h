//
//  offsetfinder.h
//  Trident
//
//  Created by Benjamin Randazzo on 14/12/2016.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#ifndef offsetfinder_h
#define offsetfinder_h

#include <stdio.h>

typedef enum {
	NotSupported,
	iPhone41_iOS921,
	iPhone41_iOS930,
	iPhone41_iOS931,
	iPhone41_iOS932,
	iPhone41_iOS933,
	iPhone41_iOS934,
	iPhone52_iOS920,
	iPhone52_iOS921,
	iPhone52_iOS932,
	iPhone53_iOS921,
	iPhone53_iOS932,
	iPhone53_iOS933,
    iPad21_iOS920,
	iPad21_iOS921,
	iPad21_iOS930,
	iPad21_iOS931,
	iPad21_iOS932,
	iPad21_iOS933,
	iPad21_iOS934,
	iPad22_iOS920,
	iPad22_iOS921,
	iPad22_iOS930,
	iPad22_iOS931,
	iPad22_iOS932,
	iPad22_iOS933,
	iPad22_iOS934,
	iPad23_iOS920,
	iPad23_iOS921,
	iPad23_iOS930,
	iPad23_iOS931,
	iPad23_iOS932,
	iPad23_iOS933,
	iPad23_iOS934,
	iPad24_iOS920,
	iPad24_iOS921,
	iPad24_iOS930,
	iPad24_iOS931,
	iPad24_iOS932,
	iPad24_iOS933,
	iPad24_iOS934,
	iPad31_iOS934,
	iPad32_iOS931,
	iPad33_iOS933,
	iPod51_iOS932
} t_target_environment;

extern t_target_environment target_environment;

// Initializer
void init_target_environment(const char *device_model, const char *system_version);

// OSSerializer::serialize
uint32_t find_OSSerializer_serialize(void);

// OSSymbol::getMetaClass
uint32_t find_OSSymbol_getMetaClass(void);

// calend_gettime
uint32_t find_calend_gettime(void);

// _bufattr_cpx
uint32_t find_bufattr_cpx(void);

// clock_ops
uint32_t find_clock_ops(void);

// _copyin
uint32_t find_copyin(void);

// BX LR
uint32_t find_bx_lr(void);

// write_gadget: str r1, [r0, #0xc] ; bx lr
uint32_t find_write_gadget(void);

// vm_kernel_addrperm
uint32_t find_vm_kernel_addrperm(void);

// kernel_pmap
uint32_t find_kernel_pmap(void);

// flush_dcache
uint32_t find_flush_dcache(void);

// invalidate_tlb
uint32_t find_invalidate_tlb(void);

// task_for_pid
uint32_t find_task_for_pid(void);

// setreuid
uint32_t find_setreuid(void);

// pid_check_addr offset
uint32_t find_pid_check(void);

// posix_check_ret_addr offset
uint32_t find_posix_check(void);

// mac_proc_check_ret_addr offset
uint32_t find_mac_proc_check(void);

#endif /* offsetfinder_h */
