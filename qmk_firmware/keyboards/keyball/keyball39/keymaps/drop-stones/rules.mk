# build rules
SRC += \
	features/hold_on_other_key_press.c \
	features/layer_state.c \
	features/oled.c \
	features/permissive_hold.c \
	features/pointing_device.c \
	features/process_record.c \
	features/quick_tap.c \
	features/tapping_term.c \

# Enable features
VIA_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
CAPS_WORD_ENABLE = yes

# Disalbe lighting
RGBLIGHT_ENABLE = no
OLED_ENABLE = no
