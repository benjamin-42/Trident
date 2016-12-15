//
//  offsetfinder.c
//  Trident
//
//  Created by Benjamin Randazzo on 14/12/2016.
//  Copyright © 2016 Benjamin Randazzo. All rights reserved.
//

#include "offsetfinder.h"

#include <stdlib.h>
#include <string.h>

t_target_environment target_environment = NotSupported;

t_target_environment info_to_target_environment(const char *device_model, const char *system_version) {
    if (!strcmp(device_model, "iPad3,1")) {
        if (!strcmp(system_version, "9.3.4")) {
            return iPad31_iOS934;
        }
    }
    return NotSupported;
}

void init_target_environment(const char *device_model, const char *system_version) {
    target_environment = info_to_target_environment(device_model, system_version);
}

uint32_t find_OSSerializer_serialize(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0x318388;
        default: abort();
    }
}

uint32_t find_OSSymbol_getMetaClass(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0x31ab90;
        default: abort();
    }
}

uint32_t find_calend_gettime(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0x1e200;
        default: abort();
    }
}

uint32_t find_bufattr_cpx(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0xd9838;
        default: abort();
    }
}

uint32_t find_clock_ops(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0x403428;
        default: abort();
    }
}

uint32_t find_copyin(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0xc76b4;
        default: abort();
    }
}

uint32_t find_bx_lr(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0xd983a;
        default: abort();
    }
}

uint32_t find_write_gadget(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0xc73e8;
        default: abort();
    }
}

uint32_t find_vm_kernel_addrperm(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0x455844;
        default: abort();
    }
}

uint32_t find_kernel_pmap(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0x3f6454;
        default: abort();
    }
}

uint32_t find_flush_dcache(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0xbc1d4;
        default: abort();
    }
}

uint32_t find_invalidate_tlb(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0xc7440;
        default: abort();
    }
}

uint32_t find_task_for_pid(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0x2fcec0;
        default: abort();
    }
}

uint32_t find_setreuid(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0x2a9988;
        default: abort();
    }
}
