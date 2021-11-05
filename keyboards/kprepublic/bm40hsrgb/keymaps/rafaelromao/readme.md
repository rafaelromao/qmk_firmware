# kprepublic/bm40hsrgb/rafaelromao
## A 34 keys split keyboard layout, optimized for programmers.

The keyboard in the picture below is a BM40, using this layout.
![img](https://i.imgur.com/odzZLMc.jpg)

### Compile

`qmk compile -kb bm40hsrgb -km rafaelromao`

### Flash

`qmk flash -kb bm40hsrgb -km rafaelromao`

## Layout

http://www.keyboard-layout-editor.com/#/gists/1a36101d96c804188d2d104ab5296739

![img](https://i.imgur.com/mgvPHqB.png)

## Highlights

- This layout works well with the OS configured for the US International layout.
- The two center columns, the center space bar, and the 6 outer keys in the bottom row are disabled.
- The base layer can be either qwerty or colemak dhm.
- Use of keys in the two inner columns is reduced, minimizing lateral movement.
- Symbols are spread among lower and raise layers, making it easier to use them with a single hand.
- All symbols are conveniently placed for software programming and VIM commands.

Considering the QWERTY layout:
- Home block mods (S Shift, D Ctrl, F Alt, V Gui), also mirrored in the other side of the keyboard (M Gui, J Alt, K Ctrl, L Shift), are available on most layers.
- Dedicated modifiers are available on the left side of the functions layer.
- Sticky (one shot) modifiers are available on the left side of the navigation and mouse layers.
- The two keys on each thumb cluster control layer transitions when held (navigation, lower, raise and mouse).
- The two inner thumb keys acts as space when tapped.
- The two outer thumb keys acts as Special Keys when tapped. See the *Special Keys* section below.
- Activating both lower and raise layers activates the functions layer.
- Activating both navigation and mouse layers activates the maintenance layer.
- On the navigation and mouse layers, you find Esc in the Q key and Enter in the P key.
- Tab is present on the left side of the navigation and mouse layers, allowing easy access to gui/alt+tab.
- Combos allow easy access to ENTER (JKL), ESC (SDF), TAB (WER or UIO) and single hand operations (Swap hands or activate another layer).
- Tap dance allows using dot or comma as decimal separator, as well as backspace, with the numpad, in the lower layer.

## Special Keys

- Mod: This special thumb key behaves as follows, when tapped (not hold):
    - If no modifier is active or locked in one-shot mode, it activates the Gui or Ctrl modifier in one-shot mode.
    - In the layers layer, we can toggle between Gui and Ctrl, which makes it easier to transition between different operating systems, using the same key combinations for shortcuts like Cmd/Ctrl+S, Cmd/Ctrl+C and Cmd/Ctrl+V.
    - If any modifier is active or locked in one-shot mode, all these modifiers will be released.
- Cap: This special thumb key behaves as follows, when tapped (not hold):
    - If CapsLock is active, it deactivates CapsLock.
    - If Shift is active in one-shot mode or locked in one-shot mode, it activates CapsLock.
    - If Shift is not active in one-shot mode, it activates Shift for one-shot.

## Combos

- JKL (qwerty) / NEI (colemak) sends ENTER.
- SDF (qwerty) / RST (colemak) sends ESC.
- UIO (qwerty) / LUY (colemak) or WER (qwerty) / WFP (colemak) sends TAB.
- XCV (qwerty) / XCD (colemak) activates the raise layer for one shot.
- M,. (qwerty) / H,. (colemak) activates the lower layer for one shot.
- 123 activates the functions layer.
- Btn1Btn2 activates the navigation layer.
- ' " &, 456, ShiftCtrlAlt, -=!, F4F5F6 or LeftDownUp returns to the previous layer.
- _{} or 789 or WE" (qwerty) or WF" (colemak) or $() swap hands for one shot.

## Tap Dance

- If the base layer is qwerty, the right pinky key, in the lower (numpad style) layer, sends backspace when tapped or held, while the key above it sends dot on single tap and comma on double tap.
- If the base layer is colemak, the right pinky key, in the lower (numpad style) layer, sends dot on single tap and comma on double tap, while the key above it simply sends backspace when tapped or held.

## Accentuation

- This layout was designed mostly for coding and typing in English and Portuguese.
- Using the lower layer, we can type `, ', ", ~ and ^ as independent symbols, while in the left side of the raise layer, we can find these keycodes as accents. I had to program some macros in qmk to make it work this way though.
- For example, considering qwerty, holding my left thumb + tapping s + releasing the thumb + tapping c, gives me 'c, while holding my right thumb + tapping f + tapping c, gives me ç. The same goes for the other accents.

## Resources

- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
