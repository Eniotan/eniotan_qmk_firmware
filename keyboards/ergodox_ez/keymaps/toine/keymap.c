#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
//~ #include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_brazilian_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german.h"
#include "keymap_japanese.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
//~ #include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"
#include "keymap_croatian.h"
#include "keymap_turkish_q.h"
#include "keymap_slovak.h"


#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  BP_LSPO,
  BP_RSPC,
  FR_LSPO,
  FR_RSPC,
};

enum tap_dance_codes {
  DANCE_0,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    BP_DLR,         BP_DQUO,        BP_LDAQ,        BP_RDAQ,        BP_LPRN,        BP_RPRN,        KC_ESCAPE,                                      BP_PERC,      BP_AT,          BP_PLUS,        BP_MINS,        BP_SLSH,        BP_ASTR,        BP_EQL,
    KC_TAB,         BP_B,           BP_EACU,        BP_P,           BP_O,           BP_EGRV,        KC_PSCR,                                        KC_CAPS_LOCK,      BP_DCIR,        BP_V,           BP_D,           BP_L,           BP_J,           TD(DANCE_4),
    KC_CAPS_LOCK,        LCTL_T(BP_A),   RALT_T(BP_U),   LGUI_T(BP_I),   LSFT_T(BP_E),   BP_COMM,                                                                      BP_C,           RSFT_T(BP_T),   RGUI_T(BP_S),   RALT_T(BP_R),   RCTL_T(BP_N),   TD(DANCE_5),
    KC_LSFT,        BP_ECIR,        BP_AGRV,        BP_Y,           BP_X,           BP_DOT,         TG(2),                                          TG(3),        BP_QUOT,        BP_Q,           TD(DANCE_3),    BP_H,           BP_F,          KC_RSFT,
    KC_HOME,        KC_END,         KC_PAUSE,       BP_K,           MOD_LALT,                                                                                                   RALT_T(KC_LEFT),KC_DOWN,        KC_RIGHT,       KC_NO,          KC_SYRQ,        
                                                                                                    TO(1),          TD(DANCE_0),    KC_DELETE,  KC_INSERT,
                                                                                                                    MT(MOD_LALT, KC_MEDIA_NEXT_TRACK),MT(MOD_RALT, KC_PGUP),
                                                                                    MT(MOD_LSFT, KC_SPACE),MT(MOD_LCTL, KC_BACKSPACE),MT(MOD_LGUI, KC_MEDIA_PREV_TRACK),MT(MOD_RGUI, KC_PGDN),MT(MOD_RCTL, KC_TAB),MT(MOD_RSFT, KC_ENTER)
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    BP_Q,           BP_A,           BP_U,           BP_I,           BP_E,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    BP_W,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_V,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, BP_G,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, BP_J,           KC_TRANSPARENT, KC_LALT,                                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LGUI(KC_RIGHT)), KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    TO(2),          KC_TRANSPARENT, KC_TRANSPARENT,KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_LSFT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_NUM_LOCK,     KC_KP_SLASH,    KC_KP_ASTERISK, KC_KP_MINUS,    KC_EQUAL,
    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_BACKSPACE,                                      KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL_T(KC_F11), LALT_T(KC_F12),LGUI_T(KC_F13), LSFT_T(KC_F14), KC_F15,                                                                         KC_TRANSPARENT, RSFT_T(KC_KP_4),RGUI_T(KC_KP_5),RALT_T(KC_KP_6),RCTL_T(KC_KP_PLUS),KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F16,         KC_F17,         KC_F18,         KC_F19,         KC_F20,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_ENTER,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F21,         KC_F22,         KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_KP_0,        KC_KP_COMMA,    TD(DANCE_2),    KC_LALT,
                                                                                                    TO(3),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LCTL
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_HOME,        KC_MY_COMPUTER, KC_MAIL,        KC_MS_BTN3,     KC_PAUSE,       KC_PWR,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_HOME,        KC_TRANSPARENT, KC_MS_BTN3,     KC_TRANSPARENT, KC_TRANSPARENT, KC_INSERT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_WH_UP,    KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_END,         KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_RIGHT, KC_TRANSPARENT,                                                                 KC_MEDIA_STOP,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT,      KC_TRANSPARENT, KC_MS_BTN1,     KC_UP,          KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1
  ),
};


extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {196,255,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {82,255,255}, {82,255,255}, {82,255,255}, {82,255,255}, {0,255,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {196,255,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255}, {88,153,255} },

    [1] = { {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {196,255,255}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {0,255,255}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {196,255,255}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204}, {45,218,204} },

    [2] = { {0,0,0}, {195,152,255}, {195,152,255}, {195,152,255}, {195,152,255}, {0,0,0}, {195,152,255}, {195,152,255}, {195,152,255}, {0,0,0}, {0,0,0}, {195,152,255}, {88,153,255}, {195,152,255}, {195,152,255}, {0,0,0}, {195,152,255}, {195,152,255}, {195,152,255}, {0,0,0}, {0,0,0}, {195,152,255}, {195,152,255}, {195,152,255}, {195,152,255}, {201,247,196}, {0,255,255}, {195,152,255}, {195,152,255}, {195,152,255}, {195,152,255}, {195,152,255}, {195,152,255}, {195,152,255}, {196,255,255}, {88,153,255}, {196,255,255}, {196,255,255}, {196,255,255}, {195,152,255}, {195,152,255}, {195,152,255}, {195,152,255}, {195,152,255}, {212,243,185}, {212,243,185}, {212,243,185}, {212,243,185} },

    [3] = { {0,0,0}, {0,0,0}, {45,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {177,255,164}, {41,255,255}, {177,255,164}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {212,218,204}, {177,255,164}, {0,0,0}, {212,218,204}, {212,218,204}, {212,218,204}, {0,0,0}, {128,246,240}, {0,255,232}, {140,218,204}, {140,218,204}, {140,218,204}, {0,0,0}, {177,255,164}, {41,255,255}, {177,255,164}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}


bool rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return false;
}


void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    switch (layer) {
        case 0:
          set_layer_color(0);
          break;
        case 1:
          set_layer_color(1);
          break;
        case 2:
          set_layer_color(2);
          break;
        case 3:
          set_layer_color(3);
          break;
       default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE)
          rgb_matrix_set_color_all(0, 0, 0);
        break;
    }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BP_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, BP_LPRN);
      return false;
    case BP_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, BP_RPRN);
      return false;
    case FR_LSPO:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, FR_LPRN);
      return false;
    case FR_RSPC:
      perform_space_cadet(record, keycode, KC_LSFT, KC_TRNS, FR_RPRN);
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[3];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_PAUSE); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_PAUSE); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[0].step = 0;
}

void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_KP_ENTER);
        tap_code16(KC_KP_ENTER);
        tap_code16(KC_KP_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_KP_ENTER);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_KP_ENTER); break;
        case SINGLE_HOLD: register_code16(FR_EQL); break;
        case DOUBLE_TAP: register_code16(KC_KP_ENTER); register_code16(KC_KP_ENTER); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_KP_ENTER); register_code16(KC_KP_ENTER);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_KP_ENTER); break;
        case SINGLE_HOLD: unregister_code16(FR_EQL); break;
        case DOUBLE_TAP: unregister_code16(KC_KP_ENTER); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_KP_ENTER); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_G);
        tap_code16(BP_G);
        tap_code16(BP_G);
    }
    if(state->count > 3) {
        tap_code16(BP_G);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(BP_G); break;
        case SINGLE_HOLD: register_code16(KC_UP); break;
        case DOUBLE_TAP: register_code16(KC_UP); register_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UP); register_code16(KC_UP);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(BP_G); break;
        case SINGLE_HOLD: unregister_code16(KC_UP); break;
        case DOUBLE_TAP: unregister_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UP); break;
    }
    dance_state[3].step = 0;
}

void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_Z);
        tap_code16(BP_Z);
        tap_code16(BP_Z);
    }
    if(state->count > 3) {
        tap_code16(BP_Z);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(BP_Z); break;
        case SINGLE_HOLD: register_code16(BP_W); break;
        case DOUBLE_TAP: register_code16(BP_Z); register_code16(BP_Z); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_Z); register_code16(BP_Z);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(BP_Z); break;
        case SINGLE_HOLD: unregister_code16(BP_W); break;
        case DOUBLE_TAP: unregister_code16(BP_Z); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_Z); break;
    }
    dance_state[3].step = 0;
}


void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_M);
        tap_code16(BP_M);
        tap_code16(BP_M);
    }
    if(state->count > 3) {
        tap_code16(BP_M);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(BP_M); break;
        case SINGLE_HOLD: register_code16(BP_CCED); break;
        case DOUBLE_TAP: register_code16(BP_M); register_code16(BP_M); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_M); register_code16(BP_M);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(BP_M); break;
        case SINGLE_HOLD: unregister_code16(BP_CCED); break;
        case DOUBLE_TAP: unregister_code16(BP_M); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_M); break;
    }
    dance_state[3].step = 0;
}



tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
};

