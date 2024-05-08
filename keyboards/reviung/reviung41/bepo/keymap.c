/* Copyright 2020 gtips
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "keymap_bepo.h"
#include "sendstring_bepo.h"

enum layer_names {
    _BLUE,
    _GREEN,
    _RED,
    _VIOLET,
    _GAME,
};

#ifdef TAP_DANCE_ENABLE

enum tap_dance_codes {
  _TD_M_W,
  _TD_C_CED,
  _TD_CAPSL,
  _TD_DELBK,    // KC_BSPC KC_DEL 
};

#define TD_M_W TD(_TD_M_W)
#define TD_C_CED TD(_TD_C_CED)
#define TD_CAPSL TD(_TD_CAPSL)
#define TD_DELBK TD(_TD_DELBK)

#endif

#define GREEN  TO(_GREEN)
#define RED  TO(_RED)
#define BLUE  TO(_BLUE)
#define GAME TO(_GAME)
#define VIOLET TO(_VIOLET)
#define KC_COPY LCTL(BP_C)
#define KC_PSTE LCTL(BP_V)
#define KC_CUT LCTL(BP_X)
#define KC_UNDO LCTL(BP_Z)
#define KC_ALL LCTL(BP_A)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BLUE] = LAYOUT(
    KC_TAB,    BP_B,         BP_EACU,      BP_P,         BP_O,         BP_EGRV,                     BP_DCIR,      BP_V,         BP_D,          BP_L,         BP_J,          BP_Z,
    TD_DELBK,  CTL_T(BP_A),  RALT_T(BP_U), LGUI_T(BP_I), LSFT_T(BP_E), TD_CAPSL,                    TD_C_CED,     RSFT_T(BP_T), RGUI_T(BP_S),  RALT_T(BP_R), RCTL_T(BP_N),  TD_M_W,
    BP_K,      BP_ECIR,      LALT_T(BP_AGRV),BP_Y,         BP_X,         LALT_T(BP_DOT),              BP_QUOT,      BP_Q,         BP_G,          BP_H,         BP_F,          QK_LEAD,
                                                            RED,       VIOLET,     KC_SPC,   RALT_T(KC_ENT),       GREEN
  ),
  
   [_RED] = LAYOUT(
    _______,      KC_EXECUTE,   KC_MYCM,      KC_WAKE,      KC_LPRN,     KC_RPRN,                    KC_NUM,       KC_P7,        KC_P8,        KC_P9,        KC_PAST,      KC_PSLS,
    _______,      _______,      _______,      LGUI_T(KC_LBRC),LSFT_T(KC_RBRC), _______,              BP_C,         KC_P4,        KC_P5,        KC_P6,        KC_PPLS,      KC_PMNS,
    _______,      _______,      _______,      KC_LCBR,      KC_RCBR,     LALT_T(KC_PDOT),            KC_P0,        KC_P1,        KC_P2,        KC_P3,        BP_F,         QK_LEAD,
                                                            BLUE,        _______,      _______,      _______,      _______
  ),
   [_GREEN] = LAYOUT(
    _______,      KC_MPRV,      KC_MSTP,      KC_MPLY,      KC_MNXT,      KC_MENU,                    KC_CAPS,     KC_HOME,       KC_PGDN,       KC_PGUP,     KC_END,       KC_SLEP,
    _______,      _______,      _______,      _______,      _______,      KC_MUTE,                    RGB_TOG,     KC_LEFT,       KC_DOWN,       KC_UP,       KC_RGHT,      KC_ESCAPE,
    KC_SLCT,      KC_BTN1,      KC_MS_WH_DOWN,KC_MS_WH_UP,  KC_BTN2,      KC_PCMM,                    RGB_VAD,     KC_MS_L,       KC_MS_D,       KC_MS_U,     KC_MS_R,      QK_LEAD,
                                                            _______,      _______,     KC_BTN1,       KC_BTN2,     BLUE
  ),
  
  
  [_VIOLET] = LAYOUT(
    BP_DLR,       BP_DQUO,      BP_LDAQ,      BP_RDAQ,      BP_LPRN,      BP_RPRN,                    BP_AT,       BP_PLUS,       BP_MINS,      BP_SLSH,      BP_ASTR,      BP_EQL,
    _______,      _______,      _______,      _______,      _______,      KC_PSTE,                    KC_PSCR,     _______,       _______,      _______,      _______,      BP_PERC,
    GAME,         KC_ALL,       KC_UNDO,      KC_COPY,      KC_CUT,       _______,                    _______,     _______,       _______,      _______,      _______,      QK_LEAD,
                                                            _______,      BLUE,        _______,       _______,     _______
  ),
  
  [_GAME] = LAYOUT(
    KC_ESCAPE,    BP_B,         BP_W,         BP_P,         BP_O,         BP_AT,                      BP_DCIR,     BP_V,         BP_D,           BP_L,          BP_J,          BP_Z,
    KC_TAB,       BP_A,         BP_U,         BP_I,         BP_E,         BP_COMM,                    BP_C,        BP_T,         BP_S,           BP_R,          BP_N,          BP_M,
    BP_K,         BP_MINS,      BP_W,         BP_Y,         BP_X,         BP_DOT,                     BP_QUOT,     BP_Q,         BP_G,           BP_H,          BP_F,          _______,
                                                            KC_LCTL,      KC_LALT,      KC_SPC,       KC_ENT,      BLUE
  ),
};

#ifdef TAP_DANCE_ENABLE

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

void on_dance_TD_DELBK(tap_dance_state_t *state, void *user_data);
void dance_TD_DELBK_finished(tap_dance_state_t *state, void *user_data);
void dance_TD_DELBK_reset(tap_dance_state_t *state, void *user_data);

void on_dance_TD_DELBK(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_TD_DELBK_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: register_code16(KC_DEL); break;
        case DOUBLE_TAP: register_code16(KC_BSPC); register_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_TD_DELBK_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case SINGLE_HOLD: unregister_code16(KC_DEL); break;
        case DOUBLE_TAP: unregister_code16(KC_BSPC); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[0].step = 0;
}

void on_dance_TD_CAPSL(tap_dance_state_t *state, void *user_data);
void dance_TD_CAPSL_finished(tap_dance_state_t *state, void *user_data);
void dance_TD_CAPSL_reset(tap_dance_state_t *state, void *user_data);

void on_dance_TD_CAPSL(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
        tap_code16(BP_COMM);
    }
    if(state->count > 3) {
        tap_code16(BP_COMM);
    }
}

void dance_TD_CAPSL_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(BP_COMM); break;
        case SINGLE_HOLD: register_code16(KC_CAPS); break;
        case DOUBLE_TAP: register_code16(BP_COMM); register_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_COMM); register_code16(BP_COMM);
    }
}

void dance_TD_CAPSL_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(BP_COMM); break;
        case SINGLE_HOLD: unregister_code16(KC_CAPS); break;
        case DOUBLE_TAP: unregister_code16(BP_COMM); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_COMM); break;
    }
    dance_state[0].step = 0;
}

void on_dance_TD_M_W(tap_dance_state_t *state, void *user_data);
void dance_TD_M_W_finished(tap_dance_state_t *state, void *user_data);
void dance_TD_M_W_reset(tap_dance_state_t *state, void *user_data);

void on_dance_TD_M_W(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_M);
        tap_code16(BP_M);
        tap_code16(BP_M);
    }
    if(state->count > 3) {
        tap_code16(BP_M);
    }
}

void dance_TD_M_W_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(BP_M); break;
        case SINGLE_HOLD: register_code16(BP_W); break;
        case DOUBLE_TAP: register_code16(BP_M); register_code16(BP_M); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_M); register_code16(BP_M);
    }
}

void dance_TD_M_W_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(BP_M); break;
        case SINGLE_HOLD: unregister_code16(BP_W); break;
        case DOUBLE_TAP: unregister_code16(BP_M); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_M); break;
    }
    dance_state[0].step = 0;
}

void on_dance_TD_C_CED(tap_dance_state_t *state, void *user_data);
void dance_TD_C_CED_finished(tap_dance_state_t *state, void *user_data);
void dance_TD_C_CED_reset(tap_dance_state_t *state, void *user_data);

void on_dance_TD_C_CED(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(BP_C);
        tap_code16(BP_C);
        tap_code16(BP_C);
    }
    if(state->count > 3) {
        tap_code16(BP_C);
    }
}

void dance_TD_C_CED_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(BP_C); break;
        case SINGLE_HOLD: register_code16(BP_CCED); break;
        case DOUBLE_TAP: register_code16(BP_C); register_code16(BP_C); break;
        case DOUBLE_SINGLE_TAP: tap_code16(BP_C); register_code16(BP_C);
    }
}

void dance_TD_C_CED_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(BP_C); break;
        case SINGLE_HOLD: unregister_code16(BP_CCED); break;
        case DOUBLE_TAP: unregister_code16(BP_C); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(BP_C); break;
    }
    dance_state[2].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [_TD_M_W] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_TD_M_W, dance_TD_M_W_finished, dance_TD_M_W_reset),
        [_TD_C_CED] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_TD_C_CED, dance_TD_C_CED_finished, dance_TD_C_CED_reset),
        [_TD_CAPSL] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_TD_CAPSL, dance_TD_CAPSL_finished, dance_TD_CAPSL_reset),
        [_TD_DELBK] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_TD_DELBK, dance_TD_DELBK_finished, dance_TD_DELBK_reset),
};

#endif

#ifdef LEADER_ENABLE

void ldrkey_send_paranthesis_wrap_ini(void) {
    SEND_STRING("()" SS_TAP(X_LEFT));
}

void ldrkey_send_brackets_wrap_ini(void) {
    SEND_STRING("[]" SS_TAP(X_LEFT));
}

void ldrkey_send_curly_brackets_wrap_ini(void) {
    SEND_STRING("{}" SS_TAP(X_LEFT));
}

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(BP_AGRV)) {
        tap_code(BP_K);
    } else if (leader_sequence_one_key(KC_LEFT)) {
        SEND_STRING(SS_LSFT(SS_TAP(X_HOME))); // selection du début de la ligne
    } else if (leader_sequence_one_key(KC_RIGHT)) {
        SEND_STRING(SS_LSFT(SS_TAP(X_END))); // selection de la fin de la ligne
    //~ } else if (leader_sequence_one_key(KC_BSPC)) {
        //~ tap_code(KC_INS);
    } else if (leader_sequence_one_key(KC_P1)) {
        tap_code(KC_F1);
    } else if (leader_sequence_one_key(KC_P2)) {
        tap_code(KC_F2);
    } else if (leader_sequence_one_key(KC_P3)) {
        tap_code(KC_F3);
    } else if (leader_sequence_one_key(KC_P4)) {
        tap_code(KC_F4);
    } else if (leader_sequence_one_key(KC_P5)) {
        tap_code(KC_F5);
    } else if (leader_sequence_one_key(KC_P6)) {
        tap_code(KC_F6);
    } else if (leader_sequence_one_key(KC_P7)) {
        tap_code(KC_F7);
    } else if (leader_sequence_one_key(KC_P8)) {
        tap_code(KC_F8);
    } else if (leader_sequence_one_key(KC_P9)) {
        tap_code(KC_F9);
    } else if (leader_sequence_one_key(KC_P0)) {
        tap_code(KC_F10);
    } else if (leader_sequence_one_key(KC_PAST)) {
        tap_code(KC_F11);
    } else if (leader_sequence_two_keys(KC_RIGHT, KC_LEFT)) {
        SEND_STRING(SS_TAP(X_END) SS_LSFT(SS_TAP(X_HOME))); // selection de la ligne
    } else if (leader_sequence_two_keys(BP_I, BP_I)) { 
        SEND_STRING(SS_LCTL("a") SS_LCTL("c")); // ctrl+a, ctrl+c
    } else if (leader_sequence_two_keys(BP_O, BP_O)) {
        ldrkey_send_paranthesis_wrap_ini();
    } else if (leader_sequence_two_keys(BP_E, BP_E)) {
        ldrkey_send_brackets_wrap_ini();
    } else if (leader_sequence_two_keys(BP_X, BP_X)) {
        ldrkey_send_curly_brackets_wrap_ini();
    } else if (leader_sequence_three_keys(BP_V, BP_V, BP_V)) {
        SEND_STRING("www.");
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        SEND_STRING("https://start.duckduckgo.com\n");
    }
}
#endif

#ifdef RGBLIGHT_ENABLE
 
// RGB LED Indicators

const rgblight_segment_t PROGMEM my_blue_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_AZURE}    // Light 11 LED, starting with LED 0
);

const rgblight_segment_t PROGMEM my_green_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_GREEN}  
);

const rgblight_segment_t PROGMEM my_red_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_RED}    
);
 
const rgblight_segment_t PROGMEM my_violet_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_MAGENTA}    
);
 
const rgblight_segment_t PROGMEM my_game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 11, HSV_YELLOW}    
);


 // Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
     my_blue_layer,          // 0
     my_red_layer,         // 1
     my_green_layer,          // 2
     my_violet_layer,     // 3
     my_game_layer        // 4
 );

 // Enable the LED layers
void keyboard_post_init_user(void) {
     rgblight_layers = my_rgb_layers;
 }

layer_state_t default_layer_state_set_user(layer_state_t state) {
     rgblight_set_layer_state(0, layer_state_cmp(state, _BLUE));
     return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
     rgblight_set_layer_state(1, layer_state_cmp(state, _RED));
     rgblight_set_layer_state(2, layer_state_cmp(state, _GREEN));
     rgblight_set_layer_state(3, layer_state_cmp(state, _VIOLET));
     rgblight_set_layer_state(4, layer_state_cmp(state, _GAME));
     return state;
 }
 #endif

#ifdef COMBO_ENABLE
enum combos {
  _F1,
  _F2,
  _F3,
  _F4,
  _F5,
  _F6,
  _F7,
  _F8,
  _F9,
  _F10,
  _F11,
  _F12
};

const uint16_t PROGMEM F1_combo[] = {BP_F, KC_P1, COMBO_END};
const uint16_t PROGMEM F2_combo[] = {BP_F, KC_P2, COMBO_END};
const uint16_t PROGMEM F3_combo[] = {BP_F, KC_P3, COMBO_END};
const uint16_t PROGMEM F4_combo[] = {BP_F, KC_P4, COMBO_END};
const uint16_t PROGMEM F5_combo[] = {BP_F, KC_P5, COMBO_END};
const uint16_t PROGMEM F6_combo[] = {BP_F, BP_S, COMBO_END};
const uint16_t PROGMEM F7_combo[] = {BP_F, KC_P7, COMBO_END};
const uint16_t PROGMEM F8_combo[] = {BP_F, KC_P8, COMBO_END};
const uint16_t PROGMEM F9_combo[] = {BP_F, KC_P9, COMBO_END};
const uint16_t PROGMEM F10_combo[] = {BP_F, KC_P0, COMBO_END};
const uint16_t PROGMEM F11_combo[] = {BP_F, KC_PAST, COMBO_END};
const uint16_t PROGMEM F12_combo[] = {BP_F, KC_PSLS, COMBO_END};


combo_t key_combos[] = {
  [_F1] = COMBO(F1_combo, KC_F1),
  [_F2] = COMBO(F2_combo, KC_F2),
  [_F3] = COMBO(F3_combo, KC_F3),
  [_F4] = COMBO(F4_combo, KC_F4),
  [_F5] = COMBO(F5_combo, BP_E),
  [_F6] = COMBO(F6_combo, KC_F6),
  [_F7] = COMBO(F7_combo, KC_F7),
  [_F8] = COMBO(F8_combo, KC_F8),
  [_F9] = COMBO(F9_combo, KC_F9),
  [_F10] = COMBO(F10_combo, KC_F10),
  [_F11] = COMBO(F11_combo, KC_F11),
  [_F12] = COMBO(F12_combo, KC_F12)
};
#endif


