uint32_t find_OSSymbol_getMetaClass(void) {
    switch (target_environment) {
	case iPhone53_iOS932: return 0x321818;
    }
}

uint32_t find_calend_gettime(void) {
    switch (target_environment) {
        case iPhone53_iOS932: return 0x1ee6c;
    }
}

uint32_t find_bufattr_cpx(void) {
    switch (target_environment) {
	case iPhone53_iOS932: return 0xdea48;		
    }
}
