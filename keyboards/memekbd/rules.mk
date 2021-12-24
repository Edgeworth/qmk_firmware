# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Enabled options
BOOTMAGIC_ENABLE = no
RGBLIGHT_ENABLE = yes       # For key backlights
RGBLIGHT_DRIVER = WS2812
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
NKRO_ENABLE = yes           # USB Nkey Rollover
SPLIT_KEYBOARD = yes
LTO_ENABLE = yes

# Disabled options
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
RGB_MATRIX_ENABLE = no
TAP_DANCE_ENABLE = no
