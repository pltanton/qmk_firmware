// vim: ts=2:sw=2
#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _DVORAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

#define KC_____ KC_TRNS
#define KC_RGBT RGB_TOG
#define KC_BLTG BL_TOGG
#define KC_QWRT QWERTY
#define KC_DVRK DVORAK
#define KC_TLYT TGLYT
#define KC_LOWR LOWER
#define KC_RASE RAISE
#define KC_RSET RESET
#define KC_RGHT KC_RIGHT

#define KC_DALT DALT
#define KC_DGUI DGUI
#define KC_DCTL DCTL
#define KC_DSFT DSFT

#define KC_RGHU BL_HU
#define KC_RGSA BL_SA
#define KC_RGVA RG_VA
#define KC_BLVA BL_VA
#define KC_RGMD BL_MODE
#define KC_RTVO RT_VO

#define KC_XALT OSM(MOD_RALT)


enum custom_keycodes {
  DVORAK,
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  TGLYT,

  DALT,
  DGUI,
  DCTL,

  BL_HU,
  BL_SA,
  BL_VA,
  RG_VA,
  BL_MODE,
  RT_VO,
};

enum custom_keycodes rotary_mode = RT_VO;

uint16_t getDModifier(enum custom_keycodes keycode) {
  switch (keycode) {
    case DALT: return KC_XALT;
    case DGUI: return KC_LGUI;
    case DCTL: return KC_LCTL;
    default: return 0;
  }
  return 0;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
//┌────┬────┬────┬────┬────┬────┐            ┌────┬────┬────┬────┬────┬────┐
   BSLS, 1  , 2  , 3  , 4  , 5  ,              6  , 7  , 8  , 9  , 0  ,BSPC,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   TAB,  Q  , W  , E  , R  , T  ,              Y  , U  , I  , O  , P  ,LBRC,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   GESC, A  , S  , D  , F  , G  ,              H  , J  , K  , L  ,SCLN,QUOT,
//├────┼────┼────┼────┼────┼────┼────┐  ┌────┼────┼────┼────┼────┼────┼────┤
   LSFT, Z  , X  , C  , V  , B  ,DVRK,   TLYT, N  , M  ,COMM,DOT ,SLSH,XALT,
//└────┴────┴────┴──┬─┴──┬─┴──┬─┴──┬─┘  └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                     DCTL,DGUI,SPC ,       ENT ,LOWR,RASE
                 // └────┴────┴────┘      └────┴────┴────┘
  ),

  [_DVORAK] = LAYOUT_kc(
//┌────┬────┬────┬────┬────┬────┐            ┌────┬────┬────┬────┬────┬────┐
   BSLS, 1  , 2  , 3  , 4  , 5  ,              6  , 7  , 8  , 9  , 0  ,BSPC,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   TAB ,QUOT,COMM,DOT , P  , Y  ,              F  , G  , C  , R  , L  ,SLSH,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   GESC, A  , O  , E  , U  , I  ,              D  , H  , T  , N  , S  ,MINS,
//├────┼────┼────┼────┼────┼────┼────┐  ┌────┼────┼────┼────┼────┼────┼────┤
   LSFT,SCLN, Q  , J  , K  , X  ,QWRT,   TLYT, B  , M  , W  , V  , Z  ,XALT,
//└────┴────┴────┴──┬─┴──┬─┴──┬─┴──┬─┘  └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                     LCTL,RGUI,SPC ,       ENT ,LOWR,RASE
                 // └────┴────┴────┘      └────┴────┴────┘
  ),

  [_LOWER] = LAYOUT_kc(
//┌────┬────┬────┬────┬────┬────┐            ┌────┬────┬────┬────┬────┬────┐
   ____,EXLM, AT ,HASH,DLR ,PERC,             CIRC,AMPR,ASTR,LPRN,RPRN,DEL ,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   ____,____,____, UP ,____,LCBR,             RCBR,PLUS,____,____,____,BSLS,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   GRV ,____,LEFT,DOWN,RGHT,LPRN,             RPRN,EQL, ____,____,____,HOME,
//├────┼────┼────┼────┼────┼────┼────┐  ┌────┼────┼────┼────┼────┼────┼────┤
   ____,____,____,____,____,LBRC,____,   ____,RBRC,MINS,____,____,____,____,
//└────┴────┴────┴──┬─┴──┬─┴──┬─┴──┬─┘  └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                     ____,____,DEL ,       DEL ,____,____
                 // └────┴────┴────┘      └────┴────┴────┘
  ),

  [_RAISE] = LAYOUT_kc(
//┌────┬────┬────┬────┬────┬────┐            ┌────┬────┬────┬────┬────┬────┐
   F12 , F1 , F2 , F3 , F4 , F5 ,              F6 , F7 , F8 , F9 ,F10 ,F11 ,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   MPRV,MPLY,MSTP,MNXT,____,____,             PSCR,____,____,____,____,____,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   ____,____,____,____,____,____,             INS ,____,____,____,____,____,
//├────┼────┼────┼────┼────┼────┼────┐  ┌────┼────┼────┼────┼────┼────┼────┤
   ____,____,____,____,____,____,____,   ____,____,____,____,____,____,____,
//└────┴────┴────┴──┬─┴──┬─┴──┬─┴──┬─┘  └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                     ____,____,____,       ____,____,____
                 // └────┴────┴────┘      └────┴────┴────┘
  ),

  [_ADJUST] = LAYOUT_kc(
//┌────┬────┬────┬────┬────┬────┐            ┌────┬────┬────┬────┬────┬────┐
   RSET,____,____,____,____,____,             ____,____,____,____,____,____,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   BLTG,____,____,____,____,____,             ____,____,____,____,____,____,
//├────┼────┼────┼────┼────┼────┤            ├────┼────┼────┼────┼────┼────┤
   RGBT,BLVA,____,____,____,____,             ____,____,____,____,____,____,
//├────┼────┼────┼────┼────┼────┼────┐  ┌────┼────┼────┼────┼────┼────┼────┤
   RTVO,RGVA,RGHU,RGSA,RGMD,____,____,   ____,____,____,____,____,____,____,
//└────┴────┴────┴──┬─┴──┬─┴──┬─┴──┬─┘  └─┬──┴─┬──┴─┬──┴─┬──┴────┴────┴────┘
                     ____,____,____,       ____,____,____
                 // └────┴────┴────┘      └────┴────┴────┘
  )
};

bool is_dvorak = true;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DALT:
    case DGUI:
    case DCTL:
      if (record->event.pressed) {
        layer_on(_DVORAK);
        register_code(getDModifier(keycode));
      } else {
        layer_off(_DVORAK);
        unregister_code(getDModifier(keycode));
      }
      return false;
      break;
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
    case RG_VA:
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
           case BL_VA:
             if (clockwise) {
               backlight_increase();
             } else {
               backlight_decrease();
             }
             break;
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
           case RG_VA:
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
