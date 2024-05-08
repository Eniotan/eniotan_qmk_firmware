/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef TAPPING_TERM
#define TAPPING_TERM 170

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 120000

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 12

#define RGB_MATRIX_STARTUP_SPD 60
