/*
Copyright 2020 gtips

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define TAPPING_TERM 175
#define TAPPING_TERM_PER_KEY

#define LEADER_TIMEOUT 500
#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

//~ #define ONESHOT_TAP_TOGGLE 2
//~ #define ONESHOT_TIMEOUT 3000

#define NO_ALT_REPEAT_KEY

#define MOUSEKEY_MOVE_DELTA 16
#define MK_KINETIC_SPEED

#undef RGBLIGHT_VAL_STEP
#define RGBLIGHT_VAL_STEP 10
#define RGBLIGHT_LIMIT_VAL 255
#undef RGBLIGHT_DISABLE_KEYCODES
#define RGBLIGHT_DEFAULT_VAL 20
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_BREATHING
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_RETAIN_VAL
//~ #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
//~ #undef RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_BREATHE_MAX 255
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
//~ #undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_TWINKLE


#undef NO_DEBUG
#undef NO_PRINT
#undef NO_ACTION_ONESHOT
