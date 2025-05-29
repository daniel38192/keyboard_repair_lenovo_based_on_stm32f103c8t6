#ifndef HID_KEYCODES_H
#define HID_KEYCODES_H

// USB HID Keyboard Modifier Bits
#define HID_MODIFIER_LEFT_CTRL   0x01
#define HID_MODIFIER_LEFT_SHIFT  0x02
#define HID_MODIFIER_LEFT_ALT    0x04
#define HID_MODIFIER_LEFT_GUI    0x08
#define HID_MODIFIER_RIGHT_CTRL  0x10
#define HID_MODIFIER_RIGHT_SHIFT 0x20
#define HID_MODIFIER_RIGHT_ALT   0x40  // AltGr for Spanish characters (e.g., ç, ¡)
#define HID_MODIFIER_RIGHT_GUI   0x80

// USB HID Keyboard Key Codes
#define HID_KEY_NONE             0x00
#define HID_KEY_ERROR_ROLLOVER   0x01
#define HID_KEY_POST_FAIL        0x02
#define HID_KEY_ERROR_UNDEFINED  0x03
#define HID_KEY_A                0x04  // 'a', AltGr + 'a' = á
#define HID_KEY_B                0x05  // 'b'
#define HID_KEY_C                0x06  // 'c', AltGr + 'c' = ç
#define HID_KEY_D                0x07  // 'd'
#define HID_KEY_E                0x08  // 'e', AltGr + 'e' = €
#define HID_KEY_F                0x09  // 'f'
#define HID_KEY_G                0x0A  // 'g'
#define HID_KEY_H                0x0B  // 'h'
#define HID_KEY_I                0x0C  // 'i', AltGr + 'i' = í
#define HID_KEY_J                0x0D  // 'j'
#define HID_KEY_K                0x0E  // 'k'
#define HID_KEY_L                0x0F  // 'l'
#define HID_KEY_M                0x10  // 'm'
#define HID_KEY_N                0x11  // 'n'
#define HID_KEY_O                0x12  // 'o', AltGr + 'o' = ó
#define HID_KEY_P                0x13  // 'p'
#define HID_KEY_Q                0x14  // 'q'
#define HID_KEY_R                0x15  // 'r'
#define HID_KEY_S                0x16  // 's'
#define HID_KEY_T                0x17  // 't'
#define HID_KEY_U                0x18  // 'u', AltGr + 'u' = ú
#define HID_KEY_V                0x19  // 'v'
#define HID_KEY_W                0x1A  // 'w'
#define HID_KEY_X                0x1B  // 'x'
#define HID_KEY_Y                0x1C  // 'y'
#define HID_KEY_Z                0x1D  // 'z'
#define HID_KEY_1                0x1E  // '1', AltGr + '1' = ¡
#define HID_KEY_2                0x1F  // '2', Shift + '2' = "
#define HID_KEY_3                0x20  // '3', Shift + '3' = ·
#define HID_KEY_4                0x21  // '4', Shift + '4' = $
#define HID_KEY_5                0x22  // '5', Shift + '5' = %
#define HID_KEY_6                0x23  // '6', Shift + '6' = &
#define HID_KEY_7                0x24  // '7', Shift + '7' = /
#define HID_KEY_8                0x25  // '8', Shift + '8' = (
#define HID_KEY_9                0x26  // '9', Shift + '9' = )
#define HID_KEY_0                0x27  // '0', Shift + '0' = =
#define HID_KEY_ENTER            0x28
#define HID_KEY_ESCAPE           0x29
#define HID_KEY_BACKSPACE        0x2A
#define HID_KEY_TAB              0x2B
#define HID_KEY_SPACE            0x2C
#define HID_KEY_MINUS            0x2D  // '-', Shift + '-' = '_'
#define HID_KEY_EQUAL            0x2E  // '=', Shift + '=' = '+'
#define HID_KEY_LEFT_BRACKET     0x2F  // Dead key for ´/¨
#define HID_KEY_RIGHT_BRACKET    0x30  // ']', Shift + ']' = '}'
#define HID_KEY_BACKSLASH        0x31  // '\', Shift + '\' = '|'
#define HID_KEY_NON_US_HASH      0x32  // '#', Shift + '#' = '~' or 'º'/'ª'
#define HID_KEY_SEMICOLON        0x33  // 'ñ', Shift + ';' = 'Ñ'
#define HID_KEY_QUOTE            0x34  // ''', Shift + ''' = '?'
#define HID_KEY_GRAVE            0x35  // '`', Shift + '`' = '^'
#define HID_KEY_COMMA            0x36  // ',', Shift + ',' = ';'
#define HID_KEY_PERIOD           0x37  // '.', Shift + '.' = ':'
#define HID_KEY_SLASH            0x38  // '/', AltGr + '/' = '¿'
#define HID_KEY_CAPS_LOCK        0x39
#define HID_KEY_F1               0x3A
#define HID_KEY_F2               0x3B
#define HID_KEY_F3               0x3C
#define HID_KEY_F4               0x3D
#define HID_KEY_F5               0x3E
#define HID_KEY_F6               0x3F
#define HID_KEY_F7               0x40
#define HID_KEY_F8               0x41
#define HID_KEY_F9               0x42
#define HID_KEY_F10              0x43
#define HID_KEY_F11              0x44
#define HID_KEY_F12              0x45
#define HID_KEY_PRINT_SCREEN     0x46
#define HID_KEY_SCROLL_LOCK      0x47
#define HID_KEY_PAUSE            0x48
#define HID_KEY_INSERT           0x49
#define HID_KEY_HOME             0x4A
#define HID_KEY_PAGE_UP          0x4B
#define HID_KEY_DELETE           0x4C
#define HID_KEY_END              0x4D
#define HID_KEY_PAGE_DOWN        0x4E
#define HID_KEY_RIGHT_ARROW      0x4F
#define HID_KEY_LEFT_ARROW       0x50
#define HID_KEY_DOWN_ARROW       0x51
#define HID_KEY_UP_ARROW         0x52
#define HID_KEY_NUM_LOCK         0x53
#define HID_KEY_KP_SLASH         0x54
#define HID_KEY_KP_ASTERISK      0x55
#define HID_KEY_KP_MINUS         0x56
#define HID_KEY_KP_PLUS          0x57
#define HID_KEY_KP_ENTER         0x58
#define HID_KEY_KP_1             0x59
#define HID_KEY_KP_2             0x5A
#define HID_KEY_KP_3             0x5B
#define HID_KEY_KP_4             0x5C
#define HID_KEY_KP_5             0x5D
#define HID_KEY_KP_6             0x5E
#define HID_KEY_KP_7             0x5F
#define HID_KEY_KP_8             0x60
#define HID_KEY_KP_9             0x61
#define HID_KEY_KP_0             0x62
#define HID_KEY_KP_PERIOD        0x63
#define HID_KEY_NON_US_HASH2      0x64
#define HID_KEY_KP_EQUAL         0x65
#define HID_KEY_F13              0x66
#define HID_KEY_F14              0x67
#define HID_KEY_F15              0x68
#define HID_KEY_F16              0x69
#define HID_KEY_F17              0x6A
#define HID_KEY_F18              0x6B
#define HID_KEY_F19              0x6C
#define HID_KEY_F20              0x6D
#define HID_KEY_F21              0x6E
#define HID_KEY_F22              0x6F
#define HID_KEY_F23              0x70
#define HID_KEY_F24              0x71
#define HID_KEY_EXECUTE          0x72
#define HID_KEY_HELP             0x73
#define HID_KEY_MENU             0x74
#define HID_KEY_SELECT           0x75
#define HID_KEY_STOP             0x76
#define HID_KEY_AGAIN            0x77
#define HID_KEY_UNDO             0x78
#define HID_KEY_CUT              0x79
#define HID_KEY_COPY             0x7A
#define HID_KEY_PASTE            0x7B
#define HID_KEY_FIND             0x7C
#define HID_KEY_MUTE             0x7D
#define HID_KEY_VOLUME_UP        0x7E
#define HID_KEY_VOLUME_DOWN      0x7F
#define HID_KEY_LOCKING_CAPS     0x80
#define HID_KEY_LOCKING_NUM      0x81
#define HID_KEY_LOCKING_SCROLL   0x82
#define HID_KEY_KP_COMMA_DOT     0x83

#endif // HID_KEYCODES_H