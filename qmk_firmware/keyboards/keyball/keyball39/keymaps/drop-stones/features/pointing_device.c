#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE

#include "quantum.h"

// https://docs.qmk.fm/#/feature_pointing_device?id=pointing-device-auto-mouse
void pointing_device_init_user(void) {
  set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}

#endif
