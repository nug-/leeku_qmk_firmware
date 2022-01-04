#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"

// place overrides here
#undef TAPPING_TERM
#undef TAPPING_TOGGLE
#undef RGBLIGHT_SLEEP
#undef USB_POLLING_INTERVAL_MS

#define TAPPING_TOGGLE 2
#define TAPPING_TERM 175
#define RGBLIGHT_SLEEP
#define USB_POLLING_INTERVAL_MS 1

#endif