# rafaelromao's keyboard layout
## A 34 keys split keyboard layout, optimized for programmers.

Here is where most of my code resides. My keyboards reference and extend this code, with keyboard specific definitions.

## Keyboards

- [kprepublic/bm40hsrgb](../../keyboards/kprepublic/bm40hsrgb/keymaps/rafaelromao/readme.md)
- [xiudi/xd75](../../keyboards/xiudi/xd75/keymaps/rafaelromao/readme.md)

## Keymap

![img](https://i.imgur.com/lNnNXi5.png)

## Table of Contents

Home | 
[Layout](docs/layout.md) |
[Modifiers](docs/modifiers.md) |
[Symbols and Numbers](docs/symbols.md) |
[Functions and Media](docs/functions.md) | 
[Navigation and Mouse](docs/navigation.md) |
[Maintenance](docs/maintenance.md) |

## Summary
- [This](docs/layout.md) is a 34 keys split layout, 3x5+2, optimized for programmers.
- [Home block mods](docs/modifiers.md) for shortcuts that combine them.
- [One-shot mods](docs/modifiers.md) in thumb keys.
	- [Cmd/Ctrl](features/default_mod_key.c) on the left side (you can choose which one will be used).
	- [Shift/Caps Lock](features/capitalize_key.c) on the right side (if Shift is already active, toggle Caps Lock).
- [Symbols](docs/symbols.md) in the left side of the lower and right side of the raise.
    - All symbols reachable with a single hand.
    - Most used VIM symbols on the right side of the raise layer.
- [Numpad](docs/symbols.md) in the right side of the lower and accents in the left side of the raise.
	- A combo activates the numpad using only the right hand.
	- Math symbols can be accessed activating the raise layer when the lower is already active.
- [Navigation and Mouse](docs/navigation.md) layers activated holding thumb keys.
    - VIM style navigation, but in the home position (shifted one key to the right).
    - Mouse layer can be disabled (navigation layer will replace it).
- [Combos](features/combos.c) allow easy access to Esc, Enter, Tab and layer switching.
- [Tap Dance](features/tapdance.c) is used for decimal separator keys and mouse buttons.

## Feature List
- [Layers](docs/layout.md)
  - Base, Lower, Raise, Functions, Media, Navigation, Mouse and Maintenance.
- [Persistent Base Layers](docs/layout.md)
  - Qwerty or Colemak-dhm as the base layer.
- [Tap Hold](docs/modifiers.md)
  - Home Block Mods and Layer Toggle.
- [Combos](features/combos.c)
  - Enter, Esc, Tab and Layer Toggle.
- [Tap Dance](features/tapdance.c)
  - Decimal Separators and Mouse Buttons.
- [Macros](docs/symbols.md)
  - String Delimiters and Shortcuts.
- [OS Toggle](docs/maintenance.md)
  - Mac OS, Windows or Linux.
- [Default Mod Key](docs/modifiers.md)
  - One-shot Cmd or Ctrl, in the thumb.
- [Capitalize Key](docs/modifiers.md)
  - One-shot Shift and Caps Lock, in the thumb.
- [Caps Lock Timer](docs/modifiers.md)
  - Caps Lock automatically disable after timeout.
- [Mouse Layer Toggle](docs/navigation.md)
  - Replace the Mouse layer by the Navigation layer.

## Resources

- [KLE](http://www.keyboard-layout-editor.com/#/gists/1a36101d96c804188d2d104ab5296739)
- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)

## References

- [Miryoku](https://github.com/manna-harbour/miryoku)
- [Seniply](https://stevep99.github.io/seniply)
- [Precondition](https://github.com/precondition/dactyl-manuform-keymap)
- [Callum Oakley](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum)
- [Drashna](https://github.com/qmk/qmk_firmware/tree/master/users/drashna)
- [Pascal Getreuer](https://github.com/getreuer/qmk-keymap)
- [DreymaR](https://dreymar.colemak.org)
- [Thomas Baart](https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/)
- [Ben Vallack](https://youtube.com/c/BenVallack)
