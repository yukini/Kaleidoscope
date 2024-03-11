/* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018-2022  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built on " __DATE__ " at " __TIME__
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-Escape-OneShot.h"
#include "Kaleidoscope-FirmwareVersion.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"
#include "Kaleidoscope-DynamicMacros.h"
#include "Kaleidoscope-LayerNames.h"

#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At          LSHIFT(Key_2)
#define Key_Hash        LSHIFT(Key_3)
#define Key_Dollar      LSHIFT(Key_4)
#define Key_Percent     LSHIFT(Key_5)
#define Key_Caret       LSHIFT(Key_6)
#define Key_And         LSHIFT(Key_7)
#define Key_Star        LSHIFT(Key_8)
#define Key_Plus        LSHIFT(Key_Equals)

//      JIS-keyboard
#define JIS_Key_Exclamation  LSHIFT(Key_1)
#define JIS_Key_DoubleQuote  LSHIFT(Key_2)
#define JIS_Key_Hash         LSHIFT(Key_3)
#define JIS_Key_Dollar       LSHIFT(Key_4)
#define JIS_Key_Percent      LSHIFT(Key_5)
#define JIS_Key_And          LSHIFT(Key_6)
#define JIS_Key_Quote        LSHIFT(Key_7)
#define JIS_Key_RightParen   LSHIFT(Key_8)
#define JIS_Key_LeftParen    LSHIFT(Key_9)
#define JIS_Key_At           Key_LeftBracket    // @
#define JIS_Key_Caret        Key_Equals         // ^
#define JIS_Key_Semicolon    Key_Semicolon      // ;
#define JIS_Key_Colon        Key_Quote          // :
#define JIS_Key_Eisu         Key_Lang2          // Key_Lang2
#define JIS_Key_Kana         Key_Lang1          // Key_Lang1
#define JIS_Key_LeftBracket  Key_RightBracket   // [
#define JIS_Key_RightBracket Key_NonUsPound     // ]
#define JIS_BackSlash        Key_International1 //
#define JIS_Key_YenMark      Key_International3 // ¥


enum {
  QWERTY,
  FUN,
  FUN2,
  UPPER,
  ARROW
};

// clang-format off
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  /* BASE
   *       0       1       2       3       4       5       6       7       8       9       10      11
   *   +---------------------------------------+               +---------------------------------------+
   * 0 |   Q   |   W   |   E   |   R   |   T   |               |   Y   |   U   |   I   |   O   |   P   |
   * 1 |   A   |   S   |   D   |   F   |   G   +---------------+   H   |   J   |   K   |   L   |   :   |
   * 2 |   Z   |   X   |   C   |   V   |   B   |  TAB  |   -   |   N   |   M   |   ,   |   .   |   /   |
   * 3 |  SFT  |  TAB  |  ALT  |  CMD  |   BS  | E/SFT | J/CTL |  SPC  |  FUN  |   _   |   ;   |  ENT  |
   *   +-----------------------------------------------------------------------------------------------+
   */
  (

       Key_Q            ,Key_W      ,Key_E        ,Key_R         ,Key_T
      ,Key_A            ,Key_S      ,Key_D        ,Key_F         ,Key_G
      ,Key_Z            ,Key_X      ,Key_C        ,Key_V         ,Key_B               ,Key_Tab
      ,Key_Esc          ,Key_Tab    ,Key_LeftAlt  ,Key_LeftGui   ,Key_Backspace       ,Key_LeftControl

                        ,Key_Y      ,Key_U        ,Key_I         ,Key_O               ,Key_P
                        ,Key_H      ,Key_J        ,Key_K         ,Key_L               ,JIS_Key_Colon
      ,JIS_BackSlash    ,Key_N      ,Key_M        ,Key_Comma     ,Key_Period          ,Key_Slash
      ,Key_RightShift   ,Key_Space  ,MO(FUN)      ,Key_Minus     ,JIS_Key_Semicolon   ,Key_Enter
  ),
  [FUN] = KEYMAP_STACKED
  (
       Key_1 ,Key_2 ,Key_3 ,Key_4 ,Key_5
      ,___    ,___         ,___         ,___         ,___
      ,___    ,___         ,___         ,___         ,___        ,Key_Tab
      ,Key_Esc          ,Key_Esc    ,Key_LeftAlt  ,Key_LeftGui   ,Key_Backspace       ,Key_LeftControl
  
                        ,Key_6      ,Key_7    ,Key_8       ,Key_9               ,Key_0
                        ,___        ,___      ,___         ,JIS_Key_At          ,JIS_Key_LeftBracket
      ,JIS_BackSlash    ,___        ,___      ,___         ,___                 ,JIS_Key_RightBracket
      ,Key_RightShift   ,Key_Space  ,___      ,Key_Minus   ,JIS_Key_Semicolon   ,Key_Enter
  ),
  [FUN2] = KEYMAP_STACKED
  (

       Key_F1  ,Key_F2  ,Key_F3      ,Key_F4      ,Key_F5
      ,Key_F6  ,Key_F7  ,Key_F8      ,Key_F9      ,Key_F10
      ,Key_F11 ,Key_F12 ,___         ,___         ,___           ,Key_Tab
      ,Key_Esc ,Key_Esc ,Key_LeftAlt ,Key_LeftGui ,Key_Backspace ,Key_LeftControl
  
                        ,___      ,___    ,___       ,___               ,___
                        ,___        ,___      ,___         ,JIS_Key_At          ,JIS_Key_LeftBracket
      ,JIS_BackSlash    ,___        ,___      ,___         ,___                 ,JIS_Key_RightBracket
      ,Key_RightShift   ,Key_Space  ,___      ,Key_Minus   ,JIS_Key_Semicolon   ,Key_Enter
  ),
  [UPPER] = KEYMAP_STACKED
  (
       Key_Insert            ,Key_Home                 ,Key_UpArrow                         ,Key_End        ,Key_PageUp
      ,Key_Delete            ,Key_LeftArrow            ,Key_DownArrow                       ,Key_RightArrow ,Key_PageDown
      ,M(MACRO_VERSION_INFO) ,Consumer_VolumeIncrement ,Consumer_DisplayBrightnessIncrement ,XXX            ,___ ,___
      ,MoveToLayer(QWERTY)   ,Consumer_VolumeDecrement ,Consumer_DisplayBrightnessDecrement ,___            ,___ ,___

                ,Key_UpArrow   ,Key_F7              ,Key_F8          ,Key_F9         ,Key_F10
                ,Key_DownArrow ,Key_F4              ,Key_F5          ,Key_F6         ,Key_F11
      ,___      ,XXX           ,Key_F1              ,Key_F2          ,Key_F3         ,Key_F12
      ,___      ,___           ,MoveToLayer(QWERTY) ,Key_PrintScreen ,Key_ScrollLock ,Consumer_PlaySlashPause
   ),
  [ARROW] = KEYMAP_STACKED
  (
       Key_Esc  ,___            ,___            ,___          ,___
      ,___      ,___            ,___            ,___          ,___
      ,___      ,___            ,___            ,___          ,___            ,___
      ,___      ,___            ,___            ,___          ,___            ,___

                ,Key_PageUp     ,Key_PageDown   ,___          ,___            ,___
                ,Key_LeftArrow  ,Key_DownArrow  ,Key_UpArrow  ,Key_RightArrow ,___
      ,___      ,___            ,___            ,___          ,___            ,___
      ,___      ,___            ,___            ,___          ,___            ,___
   )
)
// clang-format on

KALEIDOSCOPE_INIT_PLUGINS(
  // ----------------------------------------------------------------------
  // Chrysalis plugins

  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings,
  EEPROMKeymap,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,

  // The FirmwareVersion plugin lets Chrysalis query the version of the firmware
  // programmatically.
  FirmwareVersion,

  // The LayerNames plugin allows Chrysalis to display - and edit - custom layer
  // names, to be shown instead of the default indexes.
  LayerNames,

  // ----------------------------------------------------------------------
  // Keystroke-handling plugins

  // The Qukeys plugin enables the "Secondary action" functionality in
  // Chrysalis. Keys with secondary actions will have their primary action
  // performed when tapped, but the secondary action when held.
  Qukeys,

  // SpaceCadet can turn your shifts into parens on tap, while keeping them as
  // Shifts when held. SpaceCadetConfig lets Chrysalis configure some aspects of
  // the plugin.
  SpaceCadet,
  SpaceCadetConfig,

  // Enables the "Sticky" behavior for modifiers, and the "Layer shift when
  // held" functionality for layer keys.
  OneShot,
  OneShotConfig,
  EscapeOneShot,
  EscapeOneShotConfig,

  // The macros plugin adds support for macros
  Macros,

  // Enables dynamic, Chrysalis-editable macros.
  DynamicMacros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,
  MouseKeysConfig  //,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  // MagicCombo,

  // Enables the GeminiPR Stenography protocol. Unused by default, but with the
  // plugin enabled, it becomes configurable - and then usable - via Chrysalis.
  // GeminiPR,
);

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
  if (keyToggledOn(event.state)) {
    switch (macro_id) {
    case MACRO_QWERTY:
      // This macro is currently unused, but is kept around for compatibility
      // reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
      // longer do. We keep it so that if someone still has the old layout with
      // the macro in EEPROM, it will keep working after a firmware update.
      Layer.move(QWERTY);
      break;
    case MACRO_VERSION_INFO:
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
      break;
    default:
      break;
    }
  }
  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
  EEPROMKeymap.setup(9);

  DynamicMacros.reserve_storage(48);

  LayerNames.reserve_storage(63);

  Layer.move(EEPROMSettings.default_layer());

  QUKEYS(
      kaleidoscope::plugin::Qukey(0, KeyAddr(3, 5),  Key_Lang2),
      kaleidoscope::plugin::Qukey(0, KeyAddr(3, 6),  Key_Lang1),
      kaleidoscope::plugin::Qukey(0, KeyAddr(1, 11), MO(ARROW))
      );

  // To avoid any surprises, SpaceCadet is turned off by default. However, it
  // can be permanently enabled via Chrysalis, so we should only disable it if
  // no configuration exists.
  SpaceCadetConfig.disableSpaceCadetIfUnconfigured();
}

void loop() {
  Kaleidoscope.loop();
}
