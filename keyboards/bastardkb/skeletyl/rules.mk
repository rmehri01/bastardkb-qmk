# Build Options
#   change yes to no to disable
#
AUDIO_SUPPORTED = no        # Audio is not supported
RGB_MATRIX_SUPPORTED = no  # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = no    # RGB underglow is supported, but not enabled by default

COMBO_ENABLE = yes
SPLIT_KEYBOARD = yes

SERIAL_DRIVER = vendor

SRC += keymaps/rmehri01/swapper.c
