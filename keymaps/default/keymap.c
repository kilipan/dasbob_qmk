#include QMK_KEYBOARD_H

enum dasbob_layers {
  _QWERTY,
  _LOWER,
  _RAISE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │DEL├───┐           ┌───┤ESC│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘
      *               └───│LOW│   │RSE├───┘
      *                   └───┘   └───┘
      */


    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,              KC_E,            KC_R,            KC_T,               KC_Y,         KC_U,              KC_I,              KC_O,           KC_P,
        KC_A,    RALT_T(KC_S),      LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,               KC_H,         LSFT_T(KC_J),      LCTL_T(KC_K),      RALT_T(KC_L),   KC_SCLN,
        KC_Z,    KC_X,              KC_C,            KC_V,            KC_B,               KC_N,         KC_M,              KC_COMM,           KC_DOT,         KC_SLSH,
                                    KC_DEL,          KC_SPC,          MO(1),              MO(2),        KC_BSPC,           KC_ESC
    ),

    [_LOWER] = LAYOUT_split_3x5_3(
       KC_1,     KC_2,              KC_3,            KC_4,            KC_5,               KC_6,         KC_7,             KC_8,            KC_9,              KC_0,
       XXXXXXX,  RALT_T(XXXXXXX),   LCTL_T(XXXXXXX), LSFT_T(XXXXXXX), XXXXXXX,           KC_MINS,      LSFT_T(KC_EQL),   LCTL_T(KC_GRV),  RALT_T(KC_QUOT),    KC_BSLS,
       XXXXXXX,  XXXXXXX,           XXXXXXX,         LCTL(KC_C),      LCTL(KC_V),         KC_PSCR,      XXXXXXX,          XXXXXXX,         XXXXXXX,           XXXXXXX,
                                    KC_TRNS,         KC_TRNS,         KC_TAB,             KC_ENT,       KC_TRNS,          KC_TRNS
    ),

    [_RAISE] = LAYOUT_split_3x5_3(
        KC_ESC,   KC_UP,           XXXXXXX,         XXXXXXX,         CK_TOGG,             KC_NUM_LOCK,  KC_KP_7,          KC_KP_8,         KC_KP_9,           KC_KP_MINUS,
        KC_LEFT,  RALT_T(KC_DOWN), LCTL_T(KC_RGHT), LSFT_T(XXXXXXX), KC_LGUI,             XXXXXXX,      LSFT_T(KC_KP_4),  LCTL_T(KC_KP_5), RALT_T(KC_KP_6),   KC_KP_PLUS,
        KC_MPRV,  KC_MSTP,         KC_MPLY,         KC_MNXT,         KC_PSCR,             KC_RALT,      KC_KP_1,          KC_KP_2,         KC_KP_3,           KC_KP_0,
                                   KC_TRNS,         KC_TRNS,         KC_TAB,              KC_ENT,       KC_TRNS,          KC_TRNS
    ),


};
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        static const char PROGMEM runqmk_logo[] = {0,0,0,0,152,152,152,152,152,152,24,24,24,
        152,152,24,24,24,152,152,24,24,152,152,24,24,24,152,152,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,127,127,13,13,29,63,103,64,0,63,127,96,96,96,127,63,0,0,127,127,7,12,56,
        127,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,252,134,198,198,252,120,0,0,254,254,
        60,224,224,60,254,254,0,254,254,16,24,124,230,130,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,24,24,25,25,25,25,27,24,24,25,25,24,25,25,24,25,25,24,25,25,24,24,24,24,25,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0};


        oled_write_raw_P(runqmk_logo, sizeof(runqmk_logo));

        led_t led_usb_state = host_keyboard_led_state();
        oled_set_cursor(6, 3);
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUM") : PSTR(""), false);
        oled_set_cursor(6, 2);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
        oled_set_cursor(6, 0);
        oled_write_P(PSTR("by GroooveBob"), false);
            oled_set_cursor(6, 1);
            oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LOWER:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Lower\n"), false);
            break;
        case _RAISE:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Raise\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_set_cursor(6, 1);
        oled_write_ln_P(PSTR("Undefined"), false);
    }
    } else {
        static const char PROGMEM dasbob_logo[] = {
            0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,
            0,0,0,0,0,0,128,128,128,128,128,128,128,128,128,128,128,128,128,0,0,0,0,0,0,0,
            0,0,128,128,128,128,128,128,128,128,128,128,128,128,128,0,0,0,128,128,128,128,
            128,128,128,128,128,128,128,128,128,128,128,128,0,0,0,0,0,0,0,0,0,128,128,128,
            128,128,128,128,128,128,128,128,128,0,0,0,0,0,0,128,128,128,128,128,128,128,
            128,128,128,128,128,128,128,128,128,0,0,0,0,0,0,255,255,255,255,255,255,255,
            255,255,255,255,31,255,255,255,255,255,255,255,255,255,252,0,224,255,255,255,
            255,255,255,255,255,255,255,255,255,255,255,248,192,0,0,0,120,254,255,255,255,
            255,255,255,255,255,223,223,223,223,223,159,159,191,63,1,255,255,255,255,255,
            255,255,255,255,199,255,255,255,255,255,255,255,255,126,0,224,252,254,255,255,
            255,255,255,255,255,255,31,255,255,255,255,255,255,255,254,252,240,0,255,255,
            255,255,255,255,255,255,255,199,255,255,255,255,255,255,255,255,126,0,0,0,1,
            255,255,255,255,255,255,255,255,255,255,248,255,255,255,255,255,255,255,127,63,
            143,252,255,255,255,255,255,255,255,127,112,127,255,255,255,255,255,255,255,252,
            224,0,252,249,251,251,251,243,247,247,247,247,255,255,255,255,255,255,255,255,
            126,254,255,255,255,255,255,255,255,255,239,227,255,255,255,255,255,255,255,254,
            126,0,31,127,255,255,255,255,255,255,255,255,254,240,255,255,255,255,255,255,
            255,255,255,63,254,255,255,255,255,255,255,255,255,239,227,255,255,255,255,255,
            255,255,254,126,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,
            1,1,0,0,0,3,3,3,3,3,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,
            1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0,0,0,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0
        };
        oled_write_raw_P(dasbob_logo, sizeof(dasbob_logo));
    }
    return false;
}
#endif //OLED_ENABLE
