# A 34 keys split keyboard on a planck platform, optimized for programmers.

![img](https://i.imgur.com/odzZLMc.jpg)

### Compile

`qmk compile -kb bm40hsrgb -km rafaelromao`

### Flash

`qmk flash -kb bm40hsrgb -km rafaelromao`

## Layout

http://www.keyboard-layout-editor.com/#/gists/1a36101d96c804188d2d104ab5296739

![img](https://i.imgur.com/a6KH4yh.png)

## Highlights

- This layout works well with the OS configured for the US International layout.
- The two center columns, the center space bar, and the 6 outer keys in the bottom row are disabled.
- The base layer can be either qwerty or colemak dhm.
- Use of keys in the two inner columns is reduced, minimizing lateral movement.
- Symbols are spread among lower and raise layers, making it easier to use them with a single hand.
- All symbols are conveniently placed for software programming and VIM commands.

Considering the QWERTY layout:
- Home block mods (S Ctrl, D Shift, F Alt, V Gui), also mirrored in the other side of the keyboard (M Gui, J Alt, K Shift, L Ctrl), are available on the base layers, and in the right side in the lower layer.
- Dedicated modifiers are available on the left side of the functions and raise layers.
- Sticky (one shot) modifiers are available on the navigation and mouse layers.
- The two keys on each thumb cluster control layer transitions (navigation, lower, raise and mouse).
- The two inner thumb keys acts as space when tapped.
- Activating both lower and raise layers activates the functions layer.
- Activating both navigation and mouse layers activates the maintenance layer.
- On the navigation and mouse layers, you find Esc in the Q key and Enter in the P key.
- Tab is also present on both sides of the navigation and mouse layers, allowing easy access to gui/alt+tab.
- Combos allow easy access to ENTER (JKL), ESC (SDF), TAB (WER or UIO) and single hand operations (Swap hands or activate another layer).
- Tap dance allows using dot or comma as decimal separator, as well as backspace, with the numpad, in the lower layer.

## Combos

- JKL (qwerty) / NEI (colemak) sends ENTER
- SDF (qwerty) / RST (colemak) sends ESC
- UIO (qwerty) / LUY (colemak) or WER (qwerty) / WFP (colemak) sends TAB
- XCV (qwerty) / XCD (colemak) activates the raise layer for one shot
- M,. (qwerty) / H,. (colemak) activates the lower layer for one shot
- 123 activates the functions layer
- AltShiftCtrl activates the navigation layer
- ' " &, 456, CtrlShiftAlt, -=!, F4F5F6 or LeftDownUp returns to the previous layer
- _{} or $() or 789 or ^~` swap hands for one shot

## Tap Dance

- If the base layer is qwerty, the right pinky key, in the lower layer, sends backspace when tapped or held, while the key above it sends dot on single tap and comma on double tap.
- If the base layer is colemak, the right pinky key, in the lower layer, sends dot on single tap and comma on double tap, while the key above it simply sends backspace when tapped or held.

## Accentuation

- This layout was designed mostly for coding and typing in English and Portuguese.
- Using the raise layer, we can use ", ', `, ~ and ^ as independent symbols, while in the left side of my lower (numpad style) layer, we can find these keycodes as accents. I had to program some macros in qmk to make it work this way though.
- For example, considering qwerty, holding my left thumb + tapping l + releasing the thumb + tapping c, gives me 'c, while holding my right thumb + tapping v + releasing the thumb + tapping c, gives me ç. The same goes for the other accents.

## Resources

- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
