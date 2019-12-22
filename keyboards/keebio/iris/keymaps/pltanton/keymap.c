#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _DVORAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

#define KC_____ KC_TRNS
#define KC_QWRT QWERTY
#define KC_DVRK DVORAK
#define KC_TLYT TGLYT
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RSET RESET
#define KC_RGHT KC_RIGHT

#define KC_BLHU BL_HU
#define KC_BLSA BL_SA
#define KC_BLVA BL_VA
#define KC_BLMD BL_MODE
#define KC_RTVO RT_VO

enum custom_keycodes {
  DVORAK,
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  TGLYT,

  BL_HU,
  BL_SA,
  BL_VA,
  BL_MODE,
  RT_VO,
};

enum custom_keycodes rotary_mode = RT_VO;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
//┌────┬────┬────┬────┬────┬────┐            ┌────┬────┬────┬────┬────┬────┐
   GRV , 1  , 2  , 3  , 4  , 5  ,              6  , 7  , 8  , 9  , 0  ,BSPC,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   TAB,  Q  , W  , E  , R  , T  ,              Y  , U  , I  , O  , P  ,LBRC,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   ESC , A  , S  , D  , F  , G  ,              H  , J  , K  , L  ,SCLN,QUOT,
//├────┼────┼────┼────┼────┼────┼────┐  ┌────┼────┼────┼────┼────┼────┼────┤
   LSFT, Z  , X  , C  , V  , B  ,DVRK,   TLYT, N  , M  ,COMM,DOT ,SLSH,RALT,
//└────┴────┴────┴──┬─┴──┬─┴──┬─┴──┬─┘  └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                     LCTL,LGUI,SPC ,       ENT ,LOWR,RASE
                 // └────┴────┴────┘      └────┴────┴────┘
  ),

  [_DVORAK] = LAYOUT_kc(
//┌────┬────┬────┬────┬────┬────┐            ┌────┬────┬────┬────┬────┬────┐
   GRV , 1  , 2  , 3  , 4  , 5  ,              6  , 7  , 8  , 9  , 0  ,BSPC,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   TAB ,QUOT,COMM,DOT , P  , Y  ,              F  , G  , C  , R  , L  ,SLSH,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   ESC , A  , O  , E  , U  , I  ,              D  , H  , T  , N  , S  ,MINS,
//├────┼────┼────┼────┼────┼────┼────┐  ┌────┼────┼────┼────┼────┼────┼────┤
   LSFT,SCLN, Q  , J  , K  , X  ,QWRT,   TLYT, B  , M  , W  , V  , Z  ,RALT,
//└────┴────┴────┴──┬─┴──┬─┴──┬─┴──┬─┘  └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                     LCTL,LGUI,SPC ,       ENT ,LOWR,RASE
                 // └────┴────┴────┘      └────┴────┴────┘
  ),

  [_LOWER] = LAYOUT_kc(
//┌────┬────┬────┬────┬────┬────┐            ┌────┬────┬────┬────┬────┬────┐
   GRV ,EXLM, AT ,HASH,DLR ,PERC,             CIRC,AMPR,ASTR,LPRN,RPRN,DEL ,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   ____,____,____, UP ,____,LCBR,             RCBR,PLUS,____,____,____,BSLS,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   ____,____,LEFT,DOWN,RGHT,LPRN,             RPRN,EQL, ____,____,____,HOME,
//├────┼────┼────┼────┼────┼────┼────┐  ┌────┼────┼────┼────┼────┼────┼────┤
   ____,____,____,____,____,LBRC,____,   ____,RBRC,MINS,____,____,____,____,
//└────┴────┴────┴──┬─┴──┬─┴──┬─┴──┬─┘  └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                     ____,____,DEL ,       DEL ,____,____
                 // └────┴────┴────┘      └────┴────┴────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_UNDS,                            KC_EQL,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_MINS, KC_LPRN,          _______, KC_PLUS, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT_kc(
//┌────┬────┬────┬────┬────┬────┐            ┌────┬────┬────┬────┬────┬────┐
   ____,____,____,____,____,____,             ____,____,____,____,____,____,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   RSET,____,____,____,____,____,             ____,____,____,____,____,____,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   ____,____,____,____,____,____,             ____,____,____,____,____,____,
//├────┼────┼────┼────┼────┼────┼────┐  ┌────┼────┼────┼────┼────┼────┼────┤
   RTVO,BLVA,BLHU,BLSA,BLMD,____,____,   ____,____,____,____,____,____,____,
//└────┴────┴────┴──┬─┴──┬─┴──┬─┴──┬─┘  └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                     ____,____,____,       ____,____,____
                 // └────┴────┴────┘      └────┴────┴────┘
  )
};

bool is_dvorak = true;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
        is_dvorak = true;
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
        is_dvorak = false;
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case TGLYT:
      if (record->event.pressed) {
        if (is_dvorak) {
          set_single_persistent_default_layer(_QWERTY);
          is_dvorak = false;
        } else {
          set_single_persistent_default_layer(_DVORAK);
          is_dvorak = true;
        }
        tap_code16(KC_CAPS);
      }
      break;
  	case BL_HU:
  	case BL_SA:
  	case BL_VA:
    case RT_VO:
    case BL_MODE:
        if (record->event.pressed) {
			rotary_mode = keycode;
        }
		return false;
		break;

  }
  return true;
}

#define MODS_GUI (get_mods() & MOD_BIT(KC_LGUI) || get_mods() & MOD_BIT(KC_RGUI))

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (MODS_GUI) {
            if (clockwise) {
                tap_code(KC_TAB);
            } else {
                tap_code16(S(KC_TAB));
            }
        } else {
			switch (rotary_mode) {
				case BL_HU:
					if (clockwise) {
						rgblight_increase_hue();
					} else {
						rgblight_decrease_hue();
					}
					break;
				case BL_SA:
					if (clockwise) {
						rgblight_increase_sat();
					} else {
						rgblight_decrease_sat();
					}
					break;
				case BL_VA:
					if (clockwise) {
						rgblight_increase_val();
					} else {
						rgblight_decrease_val();
					}
					break;
				case BL_MODE:
					if (clockwise) {
						rgblight_step();
					} else {
						rgblight_step_reverse();
					}
					break;
				case RT_VO:
					if (clockwise) {
						tap_code(KC_VOLU);
					} else {
						tap_code(KC_VOLD);
					}
					break;
				default:
					break;
			}
        }
    }
}
