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
    iPad31_iOS934
} t_target_environment;

extern t_target_environment target_environment;

void init_target_environment(const char *device_model, const char *system_version);

// OSSerializer::serialize
uint32_t find_OSSerializer_serialize(void);

#endif /* offsetfinder_h */
