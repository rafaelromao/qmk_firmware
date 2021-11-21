# rafaelromao's userspace
## A 34 keys split keyboard layout, optimized for programmers.

Here is where most of my code resides. My keyboards reference and extend this code, with keyboard specific definitions.

## Keyboards

- [kprepublic/bm40hsrgb](../../keyboards/kprepublic/bm40hsrgb/keymaps/rafaelromao/readme.md)
- [xiudi/xd75](../../keyboards/xiudi/xd75/keymaps/rafaelromao/readme.md)

## Keymap

http://www.keyboard-layout-editor.com/#/gists/1a36101d96c804188d2d104ab5296739

![img](https://i.imgur.com/g6uuPhR.png)

## Highlights

Layout:
- This is a 34 keys split layout, optimized for programmers.
- This layout works well with the OS configured for the US International keyboard.
- The base layer can be either qwerty or colemak dhm.
- Use of keys in the two inner columns is reduced, minimizing lateral movement.

Symbols:
- Symbols are spread across the lower and raise layers, making them easier to reach with a single hand.
- All symbols are conveniently placed for software programming and VIM commands.

Modifiers:
- Considering qwerty, home block mods (S Shift, D Ctrl, F Alt, V Gui), mirrored in the other side of the keyboard (M Gui, J Alt, K Ctrl, L Shift), are available on most layers.
- Dedicated modifiers are available on the left side of the functions layer.
- One-shot modifiers are available on the left side of the navigation and mouse layers.

Thumb Keys:
- The four thumb keys control layer transitions, when held (navigation, lower, raise and mouse).
- The two outer thumb keys act as Special Keys, when tapped. See the *Special Keys* section below.
- The two inner thumb keys act as space, when tapped.
- In the lower or raise layers, the two opposite thumb keys can be held (or tapped, for one shot) to activate its corresponding layer.
- Holding both outer thumb keys will activate the maintenance layer.

More:
- One-shot layers and mods remain active with a double tap. Tap toggle layers will be toggle on with a single tap.
- Leds, when available, will highlight active layers, caps lock and one-shot mods.
- In the base layer, holding Z or ; will activate the functions and media layers, respectively. They can be toggled on tapping the same keys in the lower and mouse layers, respectively.
- But holding or tapping Z in the navigation layer will toggle the media layer instead of the functions layer.
- Tab is present on the left side of the navigation and mouse layers, allowing easy access to gui/alt+tab.
- Combos allow easy access to ENTER, ESC, TAB and single hand operations (Swap hands or activate another layer).
- Tap dance allows using dot or comma as decimal separator, as well as backspace, with the numpad, in the lower layer.
- On the navigation and mouse layers, considering qwerty, you find Esc in the Q and Enter in the P.
- Shift+Backspace sends Delete.

## Special Keys

- Mod: This special thumb key behaves as follows, when tapped (not hold):
    - If no modifier is active or locked in one-shot mode, it activates the Gui or Ctrl modifier in one-shot mode.
    - In the maintenance layer, we can toggle between Gui and Ctrl, which makes it easier to transition between different operating systems, using the same key combinations for shortcuts like Cmd/Ctrl+S, Cmd/Ctrl+C and Cmd/Ctrl+V.
    - If any modifier is active or locked in one-shot mode, all these modifiers will be released.
- Cap: This special thumb key behaves as follows, when tapped (not hold):
    - If CapsLock is active, it deactivates CapsLock.
    - If Shift is active or locked in one-shot mode, it activates CapsLock.
    - If Shift is not active in one-shot mode, it activates Shift for one-shot.

## Combos

In the base layers, considering the QWERTY layout:
- WER or UIO sends TAB. 
- SDF sends ESC.
- JKL sends ENTER.
- XCV activates the raise layer for one shot, or while held.
- M,. activates the lower layer for one shot, or while held.

In the lower layer:
- JKL activates the functions layer.

In the mouse layer:
- JKL activates the navigation layer.

In all layers but the base:
- WER or UIO swap hands for one shot.
- SDF or JKL return to the previous layer.

## Tap Dance

- If the base layer is qwerty, the right pinky key, in the lower (numpad style) layer, sends backspace when tapped or held, while the key above it sends dot on single tap and comma on double tap.
- If the base layer is colemak, the right pinky key, in the lower (numpad style) layer, sends dot on single tap and comma on double tap, while the key above it simply sends backspace when tapped or held.

## Accentuation

- This layout was designed mostly for coding and typing in English and Portuguese.
- Using the lower layer, we can type `, ', ", ~ and ^ as independent symbols, while in the left side of the raise layer, we can find these keycodes as accents. I had to program some macros in qmk to make it work this way though.
- For example, considering qwerty, holding my left thumb + tapping s + releasing the thumb + tapping c, gives me 'c, while holding my right thumb + tapping f + tapping c, gives me ç. The same goes for the other accents.

## VIM

- Symbols that are commonly used in VIM are placed in the right side of the raise layer, easily accessible using only the right hand. 
- Navigation with hjkl is ignored in favor of the navigation with the fingers in the home position, in the navigation layer. This trade-off turns the navigation easier and ubiquitous and makes even more sense when using Colemak.

## Resources

- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)
