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

#define determineTarget(modelIdentifier, swVers, target) if (!strcmp(device_model, modelIdentifier)) { if (!strcmp(system_version, swVers)) { return target; }}

t_target_environment target_environment = NotSupported;

t_target_environment info_to_target_environment(const char *device_model, const char *system_version) {
	determineTarget("iPhone5,2", "9.2.1", iPhone52_iOS921);
	determineTarget("iPhone4,1", "9.3", iPhone41_iOS930);
	determineTarget("iPhone4,1", "9.2.1", iPhone41_iOS921);
	determineTarget("iPhone4,1", "9.3.1", iPhone41_iOS931);
	determineTarget("iPhone4,1", "9.3.2", iPhone41_iOS932);
	determineTarget("iPhone4,1", "9.3.3", iPhone41_iOS933);
	determineTarget("iPhone4,1", "9.3.4", iPhone41_iOS934);
	determineTarget("iPhone5,1", "9.3.2", iPhone51_iOS932);
	determineTarget("iPhone5,1", "9.3.3", iPhone51_iOS933);
	determineTarget("iPhone5,2", "9.3.2", iPhone52_iOS932);
	determineTarget("iPhone5,3", "9.3.2", iPhone53_iOS932);
	determineTarget("iPhone5,3", "9.3.3", iPhone53_iOS933);
    	determineTarget("iPad2,1", "9.2", iPad21_iOS920);
	determineTarget("iPad2,1", "9.3", iPad21_iOS930);
	determineTarget("iPad2,1", "9.3.1", iPad21_iOS931);
	determineTarget("iPad2,1", "9.3.2", iPad21_iOS932);
	determineTarget("iPad2,1", "9.3.3", iPad21_iOS933);
	determineTarget("iPad2,1", "9.3.4", iPad21_iOS934);
	determineTarget("iPad2,2", "9.3", iPad22_iOS930);
	determineTarget("iPad2,2", "9.3.1", iPad22_iOS931);
	determineTarget("iPad2,2", "9.3.2", iPad22_iOS932);
	determineTarget("iPad2,2", "9.3.3", iPad22_iOS933);
	determineTarget("iPad2,3", "9.3.2", iPad23_iOS932);
	determineTarget("iPad2,4", "9.3.2", iPad24_iOS932);
	determineTarget("iPad2,3", "9.3.3", iPad23_iOS933);
	determineTarget("iPad3,1", "9.3.4", iPad31_iOS934);
	determineTarget("iPad3,2", "9.3.1", iPad32_iOS931);
	determineTarget("iPad3,3", "9.3.3", iPad33_iOS933);
	determineTarget("iPod5,1", "9.3.2", iPod51_iOS932);
	return NotSupported;
}

void init_target_environment(const char *device_model, const char *system_version) {
	target_environment = info_to_target_environment(device_model, system_version);
}

uint32_t find_OSSerializer_serialize(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x317768;
		case iPhone52_iOS921: return 0x317868;
		case iPhone41_iOS921: return 0x3107fc;
		case iPhone41_iOS930: return 0x31812c;
		case iPhone41_iOS931: return 0x31812c;
		case iPhone41_iOS932: return 0x318264;
		case iPhone41_iOS933: return 0x318388;
		case iPhone41_iOS934: return 0x318388;
		case iPhone51_iOS932: return 0x31ef46;
		case iPhone51_iOS933: return 0x31f13c;
		case iPhone52_iOS932: return 0x31ef58;
		case iPhone53_iOS932: return 0x31ef58;
		case iPhone53_iOS933: return 0x31f13c;
        	case iPad21_iOS920: return 0x3106fc;
		case iPad21_iOS930: return 0x31812c;
		case iPad21_iOS931: return 0x31812c;
		case iPad21_iOS932: return 0x318264;
		case iPad21_iOS933: return 0x318388;
		case iPad21_iOS934: return 0x318388;
		case iPad22_iOS930: return 0x31812c;
		case iPad22_iOS931: return 0x31812c;
		case iPad22_iOS932: return 0x318264;
		case iPad22_iOS933: return 0x318388;
		case iPad23_iOS932: return 0x318264;
		case iPad24_iOS932: return 0x318264;
		case iPad23_iOS933: return 0x318388;
		case iPad31_iOS934: return 0x318388;
		case iPad32_iOS931: return 0x31812c;
		case iPad33_iOS933: return 0x318388;
		case iPod51_iOS932: return 0x318264;
		default: abort();
	}
}

uint32_t find_OSSymbol_getMetaClass(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x319ea0;
		case iPhone52_iOS921: return 0x319fa0;
		case iPhone41_iOS921: return 0x312f18;
		case iPhone41_iOS930: return 0x31a934;
		case iPhone41_iOS931: return 0x31a934;
		case iPhone41_iOS932: return 0x31aa6c;
		case iPhone41_iOS933: return 0x31ab90;
		case iPhone41_iOS934: return 0x31ab90;
		case iPhone51_iOS932: return 0x321818;
		case iPhone51_iOS933: return 0x3219fc;
		case iPhone52_iOS932: return 0x322818;
		case iPhone53_iOS932: return 0x322818;
		case iPhone53_iOS933: return 0x3219fc;
        	case iPad21_iOS920: return 0x312e18;
		case iPad21_iOS930: return 0x31a934;
		case iPad21_iOS931: return 0x31a934;
		case iPad21_iOS932: return 0x31aa6c;
		case iPad21_iOS933: return 0x31ab90;
		case iPad21_iOS934: return 0x31ab90;
		case iPad22_iOS930: return 0x31a934;
		case iPad22_iOS931: return 0x31a934;
		case iPad22_iOS932: return 0x31aa6c;
		case iPad22_iOS933: return 0x31ab90;
		case iPad23_iOS932: return 0x31aa6c;
		case iPad24_iOS932: return 0x31aa6c;
		case iPad23_iOS933: return 0x31ab90;
		case iPad31_iOS934: return 0x31ab90;
		case iPad32_iOS931: return 0x31a934;
		case iPad33_iOS933: return 0x31ab90;
		case iPod51_iOS932: return 0x31aa6c;
		default: abort();
	}
}

uint32_t find_calend_gettime(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x1ebac;
		case iPhone52_iOS921: return 0x1eb88;
		case iPhone41_iOS921: return 0x1de60;
		case iPhone41_iOS930: return 0x1e170;
		case iPhone41_iOS931: return 0x1e170;
		case iPhone41_iOS932: return 0x1e170;
		case iPhone41_iOS933: return 0x1e200;
		case iPhone41_iOS934: return 0x1e200;
		case iPhone51_iOS932: return 0x1ee6c;
		case iPhone51_iOS933: return 0x1eeac;
		case iPhone52_iOS932: return 0x1e170;
		case iPhone53_iOS932: return 0x1e170;
		case iPhone53_iOS933: return 0x1eeac;
        	case iPad21_iOS920: return 0x1de84;
		case iPad21_iOS930: return 0x1e170;
		case iPad21_iOS931: return 0x1e170;
		case iPad21_iOS932: return 0x1e170;
		case iPad21_iOS933: return 0x1e200;
		case iPad21_iOS934: return 0x1e200;
		case iPad22_iOS930: return 0x1e170;
		case iPad22_iOS931: return 0x1e170;
		case iPad22_iOS932: return 0x1e170;
		case iPad22_iOS933: return 0x1e200;
		case iPad23_iOS932: return 0x1e170;
		case iPad24_iOS932: return 0x1e170;
		case iPad23_iOS933: return 0x1e200;
		case iPad31_iOS934: return 0x1e200;
		case iPad32_iOS931: return 0x1e170;
		case iPad33_iOS933: return 0x1e200;
		case iPod51_iOS932: return 0x1e170;
		default: abort();
	}
}

uint32_t find_bufattr_cpx(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0xdd9dc;
		case iPhone52_iOS921: return 0xdd9dc;
		case iPhone41_iOS921: return 0xd8750;
		case iPhone41_iOS930: return 0xd9848;
		case iPhone41_iOS931: return 0xd9848;
		case iPhone41_iOS932: return 0xd9848;
		case iPhone41_iOS933: return 0xd9838;
		case iPhone41_iOS934: return 0xd9838;
		case iPhone51_iOS932: return 0xdea48;
		case iPhone51_iOS933: return 0xdea48;
		case iPhone52_iOS932: return 0xdee6c;
		case iPhone53_iOS932: return 0xdee6c;
		case iPhone53_iOS933: return 0xdea48;
        	case iPad21_iOS920: return 0xd8750;
		case iPad21_iOS930: return 0xd9848;
		case iPad21_iOS931: return 0xd9848;
		case iPad21_iOS932: return 0xd9848;
		case iPad21_iOS933: return 0xd9838;
		case iPad21_iOS934: return 0xd9838;
		case iPad22_iOS930: return 0xd9848;
		case iPad22_iOS931: return 0xd9848;
		case iPad22_iOS932: return 0xd9848;
		case iPad22_iOS933: return 0xd9838;
		case iPad23_iOS932: return 0xd9848;
		case iPad24_iOS932: return 0xd9848;
		case iPad23_iOS933: return 0xd9838;
		case iPad31_iOS934: return 0xd9838;
		case iPad32_iOS931: return 0xd9848;
		case iPad33_iOS933: return 0xd9838;
		case iPod51_iOS932: return 0xd9848;
		default: abort();
	}
}

uint32_t find_clock_ops(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x4033dc;
		case iPhone52_iOS921: return 0x4033dc;
		case iPhone41_iOS921: return 0x3fc3dc;
		case iPhone41_iOS930: return 0x403428;
		case iPhone41_iOS931: return 0x403428;
		case iPhone41_iOS932: return 0x403428;
		case iPhone41_iOS933: return 0x403428;
		case iPhone41_iOS934: return 0x403428;
		case iPhone51_iOS932: return 0x40b654;
		case iPhone51_iOS933: return 0x40b428;
		case iPhone52_iOS932: return 0x40b428;
		case iPhone53_iOS932: return 0x40b428;
		case iPhone53_iOS933: return 0x40b428;
        	case iPad21_iOS920: return 0x3fc3dc;
		case iPad21_iOS930: return 0x403428;
		case iPad21_iOS931: return 0x403428;
		case iPad21_iOS932: return 0x403428;
		case iPad21_iOS933: return 0x403428;
		case iPad21_iOS934: return 0x403428;
		case iPad22_iOS930: return 0x403428;
		case iPad22_iOS931: return 0x403428;
		case iPad22_iOS932: return 0x403428;
		case iPad22_iOS933: return 0x403428;
		case iPad23_iOS932: return 0x403428;
		case iPad24_iOS932: return 0x403428;
		case iPad23_iOS933: return 0x403428;
		case iPad31_iOS934: return 0x403428;
		case iPad32_iOS931: return 0x403428;
		case iPad33_iOS933: return 0x403428;
		case iPod51_iOS932: return 0x403428;
		default: abort();
	}
}

uint32_t find_copyin(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0xca87c;
		case iPhone52_iOS921: return 0xca87c;
		case iPhone41_iOS921: return 0xc6754;
		case iPhone41_iOS930: return 0xc76b4;
		case iPhone41_iOS931: return 0xc76b4;
		case iPhone41_iOS932: return 0xc76b4;
		case iPhone41_iOS933: return 0xc76b4;
		case iPhone41_iOS934: return 0xc76b4;
		case iPhone51_iOS932: return 0xcb7dc;
		case iPhone51_iOS933: return 0xcb7dc;
		case iPhone52_iOS932: return 0xcb7dc;
		case iPhone53_iOS932: return 0xcb7dc;
		case iPhone53_iOS933: return 0xcb7dc;
        	case iPad21_iOS920: return 0xc6754;
		case iPad21_iOS930: return 0xc76b4;
		case iPad21_iOS931: return 0xc76b4;
		case iPad21_iOS932: return 0xc76b4;
		case iPad21_iOS933: return 0xc76b4;
		case iPad21_iOS934: return 0xc76b4;
		case iPad22_iOS930: return 0xc76b4;
		case iPad22_iOS931: return 0xc76b4;
		case iPad22_iOS932: return 0xc76b4;
		case iPad22_iOS933: return 0xc76b4;
		case iPad23_iOS932: return 0xc76b4;
		case iPad24_iOS932: return 0xc76b4;
		case iPad23_iOS933: return 0xc76b4;
		case iPad31_iOS934: return 0xc76b4;
		case iPad32_iOS931: return 0xc76b4;
		case iPad33_iOS933: return 0xc76b4;
		case iPod51_iOS932: return 0xc76b4;
		default: abort();
	}
}

uint32_t find_bx_lr(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0xdd9de;
		case iPhone52_iOS921: return 0xdd9de;
		case iPhone41_iOS921: return 0xd8752;
		case iPhone41_iOS930: return 0xd984a;
		case iPhone41_iOS931: return 0xd984a;
		case iPhone41_iOS932: return 0xd984a;
		case iPhone41_iOS933: return 0xd983a;
		case iPhone41_iOS934: return 0xd983a;
		case iPhone51_iOS932: return 0xdea4a;
		case iPhone51_iOS933: return 0xdea4a;
		case iPhone52_iOS932: return 0xdea4a;
		case iPhone53_iOS932: return 0xdea4a;
		case iPhone53_iOS933: return 0xdea4a;
        	case iPad21_iOS920: return 0xd8752;
		case iPad21_iOS930: return 0xd984a;
		case iPad21_iOS931: return 0xd984a;
		case iPad21_iOS932: return 0xd984a;
		case iPad21_iOS933: return 0xd983a;
		case iPad21_iOS934: return 0xd983a;
		case iPad22_iOS930: return 0xd984a;
		case iPad22_iOS931: return 0xd984a;
		case iPad22_iOS932: return 0xd984a;
		case iPad22_iOS933: return 0xd983a;
		case iPad23_iOS932: return 0xd984a;
		case iPad24_iOS932: return 0xd984a;
		case iPad23_iOS933: return 0xd983a;
		case iPad31_iOS934: return 0xd983a;
		case iPad32_iOS931: return 0xd984a;
		case iPad33_iOS933: return 0xd983a;
		case iPod51_iOS932: return 0xd984a;
		default: abort();
	}
}

uint32_t find_write_gadget(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0xca5a8;
		case iPhone52_iOS921: return 0xca5a8;
		case iPhone41_iOS921: return 0xc6488;
		case iPhone41_iOS930: return 0xc73e8;
		case iPhone41_iOS931: return 0xc73e8;
		case iPhone41_iOS932: return 0xc73e8;
		case iPhone41_iOS933: return 0xc73e8;
		case iPhone41_iOS934: return 0xc73e8;
		case iPhone51_iOS932: return 0xcb508;
		case iPhone51_iOS933: return 0xcb508;
		case iPhone52_iOS932: return 0xcb508;
		case iPhone53_iOS932: return 0xcb508;
		case iPhone53_iOS933: return 0xcb508;
        	case iPad21_iOS920: return 0xc6488;
		case iPad21_iOS930: return 0xc73e8;
		case iPad21_iOS931: return 0xc73e8;
		case iPad21_iOS932: return 0xc73e8;
		case iPad21_iOS933: return 0xc73e8;
		case iPad21_iOS934: return 0xc73e8;
		case iPad22_iOS930: return 0xc73e8;
		case iPad22_iOS931: return 0xc73e8;
		case iPad22_iOS932: return 0xc73e8;
		case iPad22_iOS933: return 0xc73e8;
		case iPad23_iOS932: return 0xc73e8;
		case iPad24_iOS932: return 0xc73e8;
		case iPad23_iOS933: return 0xc73e8;
		case iPad31_iOS934: return 0xc73e8;
		case iPad32_iOS931: return 0xc73e8;
		case iPad33_iOS933: return 0xc73e8;
		case iPod51_iOS932: return 0xc73e8;
		default: abort();
	}
}

uint32_t find_vm_kernel_addrperm(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x455964;
		case iPhone52_iOS921: return 0x455964;
		case iPhone41_iOS921: return 0x44e840;
		case iPhone41_iOS930: return 0x455844;
		case iPhone41_iOS931: return 0x455844;
		case iPhone41_iOS932: return 0x455844;
		case iPhone41_iOS933: return 0x455844;
		case iPhone41_iOS934: return 0x455844;
		case iPhone51_iOS933: return 0x45d978;
		case iPhone52_iOS932: return 0x45d978;
		case iPhone53_iOS932: return 0x45d978;
		case iPhone53_iOS933: return 0x45d978;
        	case iPad21_iOS920: return 0x44e840;
		case iPad21_iOS930: return 0x455844;
		case iPad21_iOS931: return 0x455844;
		case iPad21_iOS932: return 0x455844;
		case iPad21_iOS933: return 0x455844;
		case iPad21_iOS934: return 0x455844;
		case iPad22_iOS930: return 0x455844;
		case iPad22_iOS931: return 0x455844;
		case iPad22_iOS932: return 0x455844;
		case iPad22_iOS933: return 0x455844;
		case iPad23_iOS932: return 0x455844;
		case iPad24_iOS932: return 0x455844;
		case iPad23_iOS933: return 0x455844;
		case iPad31_iOS934: return 0x455844;
		case iPad32_iOS931: return 0x455844;
		case iPad33_iOS933: return 0x455844;
		case iPod51_iOS932: return 0x455844;
		default: abort();
	}
}

uint32_t find_kernel_pmap(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x3f6444;
		case iPhone52_iOS921: return 0x3f6444;
		case iPhone41_iOS921: return 0x3ef444;
		case iPhone41_iOS930: return 0x3f6454;
		case iPhone41_iOS931: return 0x3f6454;
		case iPhone41_iOS932: return 0x3f6454;
		case iPhone41_iOS933: return 0x3f6454;
		case iPhone41_iOS934: return 0x3f6454;
		case iPhone51_iOS932: return 0x3fe454;
		case iPhone51_iOS933: return 0x3fe454;
		case iPhone52_iOS932: return 0x3fe454;
		case iPhone53_iOS932: return 0x3fe454;
		case iPhone53_iOS933: return 0x3fe454;
        	case iPad21_iOS920: return 0x3ef444;
		case iPad21_iOS930: return 0x3f6454;
		case iPad21_iOS931: return 0x3f6454;
		case iPad21_iOS932: return 0x3f6454;
		case iPad21_iOS933: return 0x3f6454;
		case iPad21_iOS934: return 0x3f6454;
		case iPad22_iOS930: return 0x3f6454;
		case iPad22_iOS931: return 0x3f6454;
		case iPad22_iOS932: return 0x3f6454;
		case iPad22_iOS933: return 0x3f6454;
		case iPad23_iOS932: return 0x3f6454;
		case iPad24_iOS932: return 0x3f6454;
		case iPad23_iOS933: return 0x3f6454;
		case iPad31_iOS934: return 0x3f6454;
		case iPad32_iOS931: return 0x3f6454;
		case iPad33_iOS933: return 0x3f6454;
		case iPod51_iOS932: return 0x3f6454;
		default: abort();
	}
}

uint32_t find_flush_dcache(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0xbe5d0;
		case iPhone52_iOS921: return 0xbe610;
		case iPhone41_iOS921: return 0xbb760;
		case iPhone41_iOS930: return 0xbc250;
		case iPhone41_iOS931: return 0xbc250;
		case iPhone41_iOS932: return 0xbc260;
		case iPhone41_iOS933: return 0xbc1d4;
		case iPhone41_iOS934: return 0xbc1d4;
		case iPhone51_iOS932: return 0xbf274;
		case iPhone51_iOS933: return 0xbf404;
		case iPhone52_iOS932: return 0xbf274;
		case iPhone53_iOS932: return 0xbf274;
		case iPhone53_iOS933: return 0xbf404;
        	case iPad21_iOS920: return 0xbb710;
		case iPad21_iOS930: return 0xbc250;
		case iPad21_iOS931: return 0xbc250;
		case iPad21_iOS932: return 0xbc260;
		case iPad21_iOS933: return 0xbc1d4;
		case iPad21_iOS934: return 0xbc1d4;
		case iPad22_iOS930: return 0xbc250;
		case iPad22_iOS931: return 0xbc250;
		case iPad22_iOS932: return 0xbc260;
		case iPad22_iOS933: return 0xbc1d4;
		case iPad23_iOS932: return 0xbc260;
		case iPad24_iOS932: return 0xbc260;
		case iPad23_iOS933: return 0xbc1d8;
		case iPad31_iOS934: return 0xbc1d4;
		case iPad32_iOS931: return 0xbc250;
		case iPad33_iOS933: return 0xbc1d4;
		case iPod51_iOS932: return 0xbc260;
		default: abort();
	}
}

uint32_t find_invalidate_tlb(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0xca600;
		case iPhone52_iOS921: return 0xca600;
		case iPhone41_iOS921: return 0xc64e0;
		case iPhone41_iOS930: return 0xc7440;
		case iPhone41_iOS931: return 0xc7440;
		case iPhone41_iOS932: return 0xc7440;
		case iPhone41_iOS933: return 0xc7440;
		case iPhone41_iOS934: return 0xc7440;
		case iPhone51_iOS932: return 0xcb560;
		case iPhone51_iOS933: return 0xcb560;
		case iPhone52_iOS932: return 0xcb560;
		case iPhone53_iOS932: return 0xcb560;
		case iPhone53_iOS933: return 0xcb560;
        	case iPad21_iOS920: return 0xc64e0;
		case iPad21_iOS930: return 0xc7440;
		case iPad21_iOS931: return 0xc7440;
		case iPad21_iOS932: return 0xc7440;
		case iPad21_iOS933: return 0xc7440;
		case iPad21_iOS934: return 0xc7440;
		case iPad22_iOS930: return 0xc7440;
		case iPad22_iOS931: return 0xc7440;
		case iPad22_iOS932: return 0xc7440;
		case iPad22_iOS933: return 0xc7440;
		case iPad23_iOS932: return 0xc7440;
		case iPad24_iOS932: return 0xc7440;
		case iPad23_iOS933: return 0xc7450;
		case iPad31_iOS934: return 0xc7440;
		case iPad32_iOS931: return 0xc7440;
		case iPad33_iOS933: return 0xc7440;
		case iPod51_iOS932: return 0xc7440;
		default: abort();
	}
}

uint32_t find_task_for_pid(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x2fbb8c;
		case iPhone52_iOS921: return 0x2fbc9c;
		case iPhone41_iOS921: return 0x2f56c4;
		case iPhone41_iOS930: return 0x2fcc8c;
		case iPhone41_iOS931: return 0x2fcc8c;
		case iPhone41_iOS932: return 0x2fcd80;
		case iPhone41_iOS933: return 0x2fcec0;
		case iPhone41_iOS934: return 0x2fcec0;
		case iPhone51_iOS932: return 0x302df0;
		case iPhone51_iOS933: return 0x302fd4;
		case iPhone52_iOS932: return 0x302df0;
		case iPhone53_iOS932: return 0x302df0;
		case iPhone53_iOS933: return 0x302fd4;
        	case iPad21_iOS920: return 0x2f55b4;
		case iPad21_iOS930: return 0x2fcc8c;
		case iPad21_iOS931: return 0x2fcc8c;
		case iPad21_iOS932: return 0x2fcd80;
		case iPad21_iOS933: return 0x2fcec0;
		case iPad21_iOS934: return 0x2fcec0;
		case iPad22_iOS930: return 0x2fcc8c;
		case iPad22_iOS931: return 0x2fcc8c;
		case iPad22_iOS932: return 0x2fcd80;
		case iPad22_iOS933: return 0x2fcec0;
		case iPad23_iOS932: return 0x2fcd80;
		case iPad24_iOS932: return 0x2fcd80;
		case iPad23_iOS933: return 0x2fcec0;
		case iPad31_iOS934: return 0x2fcec0;
		case iPad32_iOS931: return 0x2fcc8c;
		case iPad33_iOS933: return 0x2fcec0;
		case iPod51_iOS932: return 0x2fcd80;
		default: abort();
	}
}

uint32_t find_setreuid(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x2a9e24;
		case iPhone52_iOS921: return 0x2a9f34;
		case iPhone41_iOS921: return 0x2a3bc4;
		case iPhone41_iOS930: return 0x2a977c;
		case iPhone41_iOS931: return 0x2a977c;
		case iPhone41_iOS932: return 0x2a985c;
		case iPhone41_iOS933: return 0x2a9988;
		case iPhone41_iOS934: return 0x2a9988;
		case iPhone51_iOS933: return 0x2af7b8;
		case iPhone52_iOS932: return 0x2af5f8;
		case iPhone53_iOS932: return 0x2af5f8;
		case iPhone53_iOS933: return 0x2af7b8;
        	case iPad21_iOS920: return 0x2a3ab4;
		case iPad21_iOS930: return 0x2a977c;
		case iPad21_iOS931: return 0x2a977c;
		case iPad21_iOS932: return 0x2a985c;
		case iPad21_iOS933: return 0x2a9988;
		case iPad21_iOS934: return 0x2a9988;
		case iPad22_iOS930: return 0x2a977c;
		case iPad22_iOS931: return 0x2a977c;
		case iPad22_iOS932: return 0x2a985c;
		case iPad22_iOS933: return 0x2a9988;
		case iPad23_iOS932: return 0x2a985c;
		case iPad24_iOS932: return 0x2a985c;
		case iPad23_iOS933: return 0x2a9988;
		case iPad31_iOS934: return 0x2a9988;
		case iPad32_iOS931: return 0x2a977c;
		case iPad33_iOS933: return 0x2a9988;
		case iPod51_iOS932: return 0x2a985c;
		default: abort();
	}
}

uint32_t find_pid_check(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x16;
		case iPhone52_iOS921: return 0x16;
		case iPhone41_iOS921: return 0x14;
		case iPhone41_iOS930: return 0x14;
		case iPhone41_iOS931: return 0x14;
		case iPhone41_iOS932: return 0x14;
		case iPhone41_iOS933: return 0x14;
		case iPhone41_iOS934: return 0x14;
		case iPhone51_iOS933: return 0x16;
		case iPhone52_iOS932: return 0x16;
		case iPhone53_iOS932: return 0x16;
		case iPhone53_iOS933: return 0x16;
        	case iPad21_iOS920: return 0x14;
		case iPad21_iOS930: return 0x14;
		case iPad21_iOS931: return 0x14;
		case iPad21_iOS932: return 0x14;
		case iPad21_iOS933: return 0x14;
		case iPad21_iOS934: return 0x14;
		case iPad22_iOS930: return 0x14;
		case iPad22_iOS931: return 0x14;
		case iPad22_iOS932: return 0x14;
		case iPad22_iOS933: return 0x14;
		case iPad23_iOS932: return 0x14;
		case iPad24_iOS932: return 0x14;
		case iPad23_iOS933: return 0x14;
		case iPad31_iOS934: return 0x14;
		case iPad32_iOS931: return 0x14;
		case iPad33_iOS933: return 0x14;
		case iPod51_iOS932: return 0x14;
		default: abort();
	}
}

uint32_t find_posix_check(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x3e;
		case iPhone52_iOS921: return 0x3e;
		case iPhone41_iOS921: return 0x3e;
		case iPhone41_iOS930: return 0x3e;
		case iPhone41_iOS931: return 0x3e;
		case iPhone41_iOS932: return 0x3e;
		case iPhone41_iOS933: return 0x3e;
		case iPhone41_iOS934: return 0x3e;
		case iPhone51_iOS933: return 0x3e;
		case iPhone52_iOS932: return 0x3e;
		case iPhone53_iOS932: return 0x3e;
		case iPhone53_iOS933: return 0x3e;
        	case iPad21_iOS920: return 0x3e;
		case iPad21_iOS930: return 0x3e;
		case iPad21_iOS931: return 0x3e;
		case iPad21_iOS932: return 0x3e;
		case iPad21_iOS933: return 0x3e;
		case iPad21_iOS934: return 0x3e;
		case iPad22_iOS930: return 0x3e;
		case iPad22_iOS931: return 0x3e;
		case iPad22_iOS932: return 0x3e;
		case iPad22_iOS933: return 0x3e;
		case iPad23_iOS932: return 0x3e;
		case iPad24_iOS932: return 0x3e;
		case iPad23_iOS933: return 0x3e;
		case iPad31_iOS934: return 0x3e;
		case iPad32_iOS931: return 0x3e;
		case iPad33_iOS933: return 0x3e;
		case iPod51_iOS932: return 0x3e;
		default: abort();
	}
}

uint32_t find_mac_proc_check(void) {
	switch (target_environment) {
		case iPhone52_iOS920: return 0x1e6;
		case iPhone52_iOS921: return 0x1e6;
		case iPhone41_iOS921: return 0x1e6;
		case iPhone41_iOS930: return 0x1e6;
		case iPhone41_iOS931: return 0x1e6;
		case iPhone41_iOS932: return 0x1e6;
		case iPhone41_iOS933: return 0x1e6;
		case iPhone41_iOS934: return 0x1e6;
		case iPhone51_iOS933: return 0x1e6;
		case iPhone52_iOS932: return 0x1e6;
		case iPhone53_iOS932: return 0x1e6;
		case iPhone53_iOS933: return 0x1e6;
        	case iPad21_iOS920: return 0x1e6;
		case iPad21_iOS930: return 0x1e6;
		case iPad21_iOS931: return 0x1e6;
		case iPad21_iOS932: return 0x1e6;
		case iPad21_iOS933: return 0x1e6;
		case iPad21_iOS934: return 0x1e6;
		case iPad22_iOS930: return 0x1e6;
		case iPad22_iOS931: return 0x1e6;
		case iPad22_iOS932: return 0x1e6;
		case iPad22_iOS933: return 0x1e6;
		case iPad23_iOS932: return 0x1e6;
		case iPad24_iOS932: return 0x1e6;
		case iPad23_iOS933: return 0x1e6;
		case iPad31_iOS934: return 0x1e6;
		case iPad32_iOS931: return 0x1e6;
		case iPad33_iOS933: return 0x1e6;
		case iPod51_iOS932: return 0x1e6;
		default: abort();
	}
}
