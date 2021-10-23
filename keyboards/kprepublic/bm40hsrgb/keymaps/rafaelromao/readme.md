# A 34 keys split keyboard on a planck platform, optimized for programmers.

![img](https://i.imgur.com/odzZLMc.jpg)

### Compile

`qmk compile -kb bm40hsrgb -km rafaelromao`

### Flash

`qmk flash -kb bm40hsrgb -km rafaelromao`

## Layout

http://www.keyboard-layout-editor.com/#/gists/59d65a3aafd060cf391e85eef33f5b21

![img](https://i.imgur.com/CCkfF5P.png)

## Highlights

- The two center columns, the center space bar, and the 6 outer keys in the bottom row are disabled.
- The base layer can be either qwerty or colemak dhm.
- Use of keys in the two inner columns is reduced, minimizing lateral movement.
- All symbols are conveniently placed for programming.

Considering the QWERTY layout:
- Home row mods (A Shift, S Ctrl, D Alt, F Gui), also mirrored in the other side of the keyboard (J Gui, K Alt, L Ctrl, Backspace Shift), are available on the base layers, and in the right side in the numbers layer.
- Dedicated modifiers are available on the left side of the functions layers.
- Sticky (one shot) modifiers are available on the navigation and mouse layers.
- The two keys on each thumb cluster control layer transitions (navigation, symbols, numbers and mouse) when held and space (all 4 keys) when tapped.
- Activating both numbers and symbols layers activates the functions layer.
- Activating both navigation and mouse layers activates the maintenance layer.
- It is also possible to send tab, backspace, enter and esc using only these four thumb keys, depending on which ones you hold first and tap later.
- On the navigation layer, you find Esc in the Q key.
- On the mouse layer, you find Enter in the P key.
- Tab is also present on both sides of the navigation and mouse layers, allowing easy access to gui/alt+tab.
- Combos allow easy access to ENTER (JKL), ESC (SDF), TAB (WER or UIO) and single hand operations (Swap hands or activate another layer).
- Tap dance allows using dot or comma as decimal separator, as well as backspace, in the numbers layer.

## Combos

- JKL (qwerty) / NEI (colemak) sends ENTER
- SDF (qwerty) / RST (colemak) sends ESC
- UIO (qwerty) / LUY (colemak) or WER (qwerty) / WFP (colemak) sends TAB
- XCV (qwerty) / XCD (colemak) activates the numbers layer for one shot
- M,. (qwerty) / H,. (colemak) or 123 activates the symbols layer for one shot
- 456 activates the functions layer
- Gui, Alt, Ctrl activates the navigation layer
- F4F5F6 or LeftDownUp returns to the previous layer
- {}_ or $?# or 789 or ^~` swap hands for one shot

## Tap Dance

- If the base layer is qwerty, the right pinky key, in the numbers row, sends shift when held or backspace when tapped, or tapped and then held, while the key above it sends dot on single tap and comma on double tap.
- If the base layer is colemak, the right pinky key, in the numbers layer, sends dot on single tap, comma on double tap and shift when held, while the key above it simply sends backspace when tapped or held.
  
## Resources

- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
