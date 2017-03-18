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
    iPhone41_iOS910,
    iPhone41_iOS920,
    iPhone41_iOS921,
    iPhone41_iOS930,
    iPhone41_iOS931,
    iPhone41_iOS932,
    iPhone41_iOS933,
    iPhone41_iOS934,
    iPhone51_iOS910,
    iPhone51_iOS920,
    iPhone51_iOS921,
    iPhone51_iOS930,
    iPhone51_iOS931,
    iPhone51_iOS932,
    iPhone51_iOS933,
    iPhone51_iOS934,
    iPhone52_iOS910,
    iPhone52_iOS920,
    iPhone52_iOS921,
    iPhone52_iOS930,
    iPhone52_iOS931,
    iPhone52_iOS932,
    iPhone52_iOS933,
    iPhone52_iOS934,
    iPhone53_iOS910,
    iPhone53_iOS920,
    iPhone53_iOS921,
    iPhone53_iOS930,
    iPhone53_iOS931,
    iPhone53_iOS932,
    iPhone53_iOS933,
    iPhone53_iOS934,
    iPhone54_iOS910,
    iPhone54_iOS920,
    iPhone54_iOS921,
    iPhone54_iOS930,
    iPhone54_iOS931,
    iPhone54_iOS932,
    iPhone54_iOS933,
    iPhone54_iOS934,
    iPad21_iOS910,
    iPad21_iOS920,
    iPad21_iOS921,
    iPad21_iOS930,
    iPad21_iOS931,
    iPad21_iOS932,
    iPad21_iOS933,
    iPad21_iOS934,
    iPad22_iOS910,
    iPad22_iOS920,
    iPad22_iOS921,
    iPad22_iOS930,
    iPad22_iOS931,
    iPad22_iOS932,
    iPad22_iOS933,
    iPad22_iOS934,
    iPad23_iOS910,
    iPad23_iOS920,
    iPad23_iOS921,
    iPad23_iOS930,
    iPad23_iOS931,
    iPad23_iOS932,
    iPad23_iOS933,
    iPad23_iOS934,
    iPad24_iOS910,
    iPad24_iOS920,
    iPad24_iOS921,
    iPad24_iOS930,
    iPad24_iOS931,
    iPad24_iOS932,
    iPad24_iOS933,
    iPad24_iOS934,
    iPad25_iOS910,
    iPad25_iOS920,
    iPad25_iOS921,
    iPad25_iOS930,
    iPad25_iOS931,
    iPad25_iOS932,
    iPad25_iOS933,
    iPad25_iOS934,
    iPad26_iOS910,
    iPad26_iOS920,
    iPad26_iOS921,
    iPad26_iOS930,
    iPad26_iOS931,
    iPad26_iOS932,
    iPad26_iOS933,
    iPad26_iOS934,
    iPad27_iOS910,
    iPad27_iOS920,
    iPad27_iOS921,
    iPad27_iOS930,
    iPad27_iOS931,
    iPad27_iOS932,
    iPad27_iOS933,
    iPad27_iOS934,
    iPad31_iOS910,
    iPad31_iOS920,
    iPad31_iOS921,
    iPad31_iOS930,
    iPad31_iOS931,
    iPad31_iOS932,
    iPad31_iOS933,
    iPad31_iOS934,
    iPad32_iOS910,
    iPad32_iOS920,
    iPad32_iOS921,
    iPad32_iOS930,
    iPad32_iOS931,
    iPad32_iOS932,
    iPad32_iOS933,
    iPad32_iOS934,
    iPad33_iOS910,
    iPad33_iOS920,
    iPad33_iOS921,
    iPad33_iOS930,
    iPad33_iOS931,
    iPad33_iOS932,
    iPad33_iOS933,
    iPad33_iOS934,
    iPad34_iOS910,
    iPad34_iOS920,
    iPad34_iOS921,
    iPad34_iOS930,
    iPad34_iOS931,
    iPad34_iOS932,
    iPad34_iOS933,
    iPad34_iOS934,
    iPad35_iOS910,
    iPad35_iOS920,
    iPad35_iOS921,
    iPad35_iOS930,
    iPad35_iOS931,
    iPad35_iOS932,
    iPad35_iOS933,
    iPad35_iOS934,
    iPad36_iOS910,
    iPad36_iOS920,
    iPad36_iOS921,
    iPad36_iOS930,
    iPad36_iOS931,
    iPad36_iOS932,
    iPad36_iOS933,
    iPad36_iOS934,
    iPod51_iOS910,
    iPod51_iOS920,
    iPod51_iOS921,
    iPod51_iOS930,
    iPod51_iOS931,
    iPod51_iOS932,
    iPod51_iOS933,
    iPod51_iOS934
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

// setreuid cred update
uint32_t find_setreuid_cred_update(void);

// pid_check_addr offset
uint32_t find_pid_check(void);

// posix_check_ret_addr offset
uint32_t find_posix_check(void);

// mac_proc_check_ret_addr offset
uint32_t find_mac_proc_check(void);

#endif /* offsetfinder_h */
