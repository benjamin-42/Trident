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

void init_target_environment(const char *device_model, const char *system_version) {
    if (!strcmp(device_model, "iPad3,1")) {
        if (!strcmp(system_version, "9.3.4")) {
            target_environment = iPad31_iOS934;
        }
    }
}

uint32_t find_OSSerializer_serialize(void) {
    switch (target_environment) {
        case iPad31_iOS934: return 0x318388;
        default: abort();
    }
}
