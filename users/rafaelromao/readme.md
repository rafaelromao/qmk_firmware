# rafaelromao's keyboard layout
## A 34 keys split keyboard layout, optimized for programmers.

Here is where most of my code resides. My keyboards reference and extend this code, with keyboard specific definitions.

## Keyboards

- [kprepublic/bm40hsrgb](../../keyboards/kprepublic/bm40hsrgb/keymaps/rafaelromao/readme.md)
- [xiudi/xd75](../../keyboards/xiudi/xd75/keymaps/rafaelromao/readme.md)

## Keymap

http://www.keyboard-layout-editor.com/#/gists/1a36101d96c804188d2d104ab5296739

![img](https://i.imgur.com/X6yFyPY.png)

## Summary
- This is a [34 keys split layout](docs/layout.md), 3x5+2, optimized for programmers.
- [Home block mods](docs/taphold.md) for shortcuts that combine them.
- One-shot mods in thumb keys.
	- [Cmd/Ctrl](docs/modifier_keys.md) on the left side (you can choose which one will be used).
	- [Shift/Caps Lock](docs/modifier_keys.md) on the right side (if shift is already active, will toggle [Caps Lock](docs/modifier_keys.md).
- Symbols in the left side of the lower and right side of the raise.
    - All [symbols](docs/layers.md) reachable with a single hand.
    - Most used [VIM symbols](docs/layers.md) on the right side of the raise layer.
- Numpad in the right side of the lower and accents in the left side of the raise.
	- A combo activates the numpad using only the right hand.
	- Math symbols can be accessed activating the raise layer when the lower is already active.
- Navigation and Mouse [layers](docs/layers.md) activated holding thumb keys.
    - VIM style navigation, but in the home position (shifted one key to the right).
    - Mouse layer can be disabled (navigation layer will replace it).
- [Combos](docs/tapdance_combos.md) allow easy access to Esc, Enter, Tab and layer switching.
- [Tap Dance](docs/tapdance_combos.md) is used for decimal separator keys and mouse buttons.

## Feature List
- [Layers](docs/layers.md)
  - Base, Lower, Raise, Functions, Media, Navigation, Mouse and Maintenance.
- [Persistent Layers](docs/layers.md)
  - Qwerty or Colemak-dhm as the base layer.
- [Tap Hold](docs/taphold.md)
  - Home Block Mods and Layer Toggle.
- [Combos](docs/tapdance_combos.md)
  - Enter, Esc, Tab and Layer Toggle.
- [Tap Dance](docs/tapdance_combos.md)
  - Decimal Separators and Mouse Buttons.
- Macros
  - String Delimiters and Shortcuts.
- OS Toggle
  - Mac OS, Windows or Linux.
- [Default Modifier Key](docs/modifier_keys.md)
  - One-shot Cmd or Ctrl, in the thumb.
- [Capitalize Key](docs/modifier_keys.md)
  - One-shot Shift and Caps Lock, in the thumb.
- [Caps Lock Timer](docs/modifier_keys.md)
  - Caps Lock automatically disable after timeout.
- Mouse Layer Toggle
  - Replace the Mouse layer by the Navigation layer.

## Resources

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
