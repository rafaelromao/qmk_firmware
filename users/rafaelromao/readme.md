# rafaelromao's keyboard layout

A 34 keys split keyboard layout, optimized for programmers.

## Keyboards

My keymaps, for the keyboards listed here, reference and extend the code in this userspace.

- [kprepublic/bm40hsrgb](../../keyboards/kprepublic/bm40hsrgb/keymaps/rafaelromao/readme.md)
- [xiudi/xd75](../../keyboards/xiudi/xd75/keymaps/rafaelromao/readme.md)

## Keymap

This diagram presents my Keymap definitions. Check the Details section below for more information.

![img](https://i.imgur.com/UNIIcJU.png)

## Main Features

Here is a list of the main features implemented in this layout:

- [Layers](docs/layout.md):
  Base, Lower, Raise, Functions, Media, Navigation, Mouse and Maintenance.
- [Persistent Base Layers](docs/layout.md#persistent-base-layers):
  Qwerty or Colemak-dhm as the base layer.
- [Tap Hold](docs/modifiers.md):
  Home Block Mods and layer toggle.
- [Combos](features/combos.c):
  Enter, Esc, Tab, common shortcuts and layer toggle.
- [Tap Dance](features/tapdance.c):
  Decimal separators, mouse buttons, custom shortcuts and layer toggle.
- [IntelliJ Shortcuts](docs/functions.md#intellij-shortcuts):
  6 most useful IntelliJ shortcuts in the thumbs.
- [Macros](docs/symbols.md):
  String delimiters and custom shortcuts.
- [OS Toggle](docs/maintenance.md):
  Different behaviors for Mac OS, Windows and Linux.
- [Default Mod Key](docs/modifiers.md#default-mod-key):
  One-shot Cmd or Ctrl, in the thumb.
- [Capitalize Key](docs/modifiers.md#capitalize-key):
  One-shot Shift and Caps Lock, in the thumb.
- [Caps Lock Timer](docs/modifiers.md#caps-lock):
  Caps Lock automatically disable after timeout.
- [Mouse Layer Toggle](docs/navigation.md#mouse-layer-toggle):
  Replace the Mouse layer by the Navigation layer.

## Details

This section details how this layout works:

- [Layout](docs/layout.md)
- [Modifiers](docs/modifiers.md)
- [Symbols and Numbers](docs/symbols.md)
- [Functions and Media](docs/functions.md)
- [Navigation and Mouse](docs/navigation.md)
- [Maintenance](docs/maintenance.md)

## References

These were my main references when designing this layout:

- [Miryoku](https://github.com/manna-harbour/miryoku)
- [Seniply](https://stevep99.github.io/seniply)
- [Precondition](https://github.com/precondition/dactyl-manuform-keymap)
- [Callum Oakley](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum)
- [Drashna](https://github.com/qmk/qmk_firmware/tree/master/users/drashna)
- [Pascal Getreuer](https://github.com/getreuer/qmk-keymap)
- [DreymaR](https://dreymar.colemak.org)
- [Thomas Baart](https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/)
- [Ben Vallack](https://youtube.com/c/BenVallack)

## Resources

Some other useful resouces:

- [KLE](http://www.keyboard-layout-editor.com/#/gists/1a36101d96c804188d2d104ab5296739)
- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
