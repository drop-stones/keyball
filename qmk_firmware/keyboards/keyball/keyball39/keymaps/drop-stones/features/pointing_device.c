#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE

#include "quantum.h"
#include "keymap.h"

// https://docs.qmk.fm/#/feature_pointing_device?id=pointing-device-auto-mouse
void pointing_device_init_user(void) {
  set_auto_mouse_layer(_MOUSE); // set the layer to be used for auto mouse
  set_auto_mouse_timeout(250);
  set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}

#endif
