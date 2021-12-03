# rafaelromao's userspace
## A 34 keys split keyboard layout, optimized for programmers.

Here is where most of my code resides. My keyboards reference and extend this code, with keyboard specific definitions.

## Keyboards

- [kprepublic/bm40hsrgb](../../keyboards/kprepublic/bm40hsrgb/keymaps/rafaelromao/readme.md)
- [xiudi/xd75](../../keyboards/xiudi/xd75/keymaps/rafaelromao/readme.md)

## Keymap

http://www.keyboard-layout-editor.com/#/gists/1a36101d96c804188d2d104ab5296739

![img](https://i.imgur.com/NRsQ1dx.png)

### Layout
- This is a 34 keys split layout, 3x5+2, optimized for programmers.
- This layout works well with the OS configured for the US International keyboard.
- This layout was designed mostly for coding and typing in English and Portuguese (but will probably work well for other latin languages).
- This layout considers the right hand as the stronger hand.
- The base layer can be either qwerty or colemak dhm.
- Use of keys in the two inner columns is reduced, minimizing lateral movement.

### Thumb Keys
- The four thumb keys control layer transitions, when held (navigation, lower, raise and mouse).
- The two outer thumb keys act as Special Keys, when tapped. See below.
- The two inner thumb keys act as space, when tapped.
- Holding both outer thumb keys will activate the maintenance layer.

### Mod-Taps and Layer-Taps
- Home block mods are available on both sides of the base layers.
  - Qwerty: S Shift, D Ctrl, F Alt, V Gui, M Gui, J Alt, K Ctrl, L Shift
  - Colemak: R Shift, S Ctrl, T Alt, D Gui, H Gui, N Alt, R Ctrl, I Shift
- Home block mods are not available on lower and raise layers, since they delay the symbol activation and are not that much usefull anyway.
- Dedicated modifiers are available on the left side of the functions layer.
- One-shot modifiers are available on the left side of the navigation and mouse layers.
- Gui/Ctrl and Shift are also available as Special Keys, in the thumbs, see below.
- In the base layer, holding Z or ; will activate the functions and media layers, respectively.
- In the lower or raise layers, the two opposite thumb key can be held (or tapped, for one shot) to activate its corresponding layer.
- One-shot layers and mods remain active with a double tap. Tap toggle layers will be toggle on with a single tap.
- The mouse layer can be disabled, using the maintenance layer. In this case, the navigation layer will be activated in its place instead.

### Enter, Esc, Tab, Delete
- Considering qwerty, on the navigation and mouse layers, you find Esc in the Q and Enter in the P.
- Tab is present on the left side of the navigation and mouse layers, in the E, allowing easy access to Gui/Alt+Tab.
- Combos allow easy access to ENTER (JKL), ESC (SDF), TAB (UIO).
- Shift+Backspace sends Delete, when shift is not one-shot, but Delete is also available under ; in the navigation layer.

### Symbols
- Symbols are spread across the lower and raise layers, making them easier to reach with a single hand.
- All symbols are conveniently placed for software programming and VIM commands.

#### Accentuation
- Using the lower layer, we can type `, ', ", ~ and ^ as independent symbols, while in the left side of the raise layer, we can find these keycodes as accents. I had to program some macros in qmk to make it work this way though.
- For example, considering qwerty, holding my left thumb + tapping s + releasing the thumb + tapping c, gives me 'c, while holding my right thumb + tapping f + tapping c, gives me ç. The same goes for the other accents.

#### VIM
- Symbols that are commonly used in VIM are placed in the right side of the raise layer, easily accessible using only the right hand. 
- Navigation with hjkl is ignored in favor of the navigation with the fingers in the home position, in the navigation layer.
- For that to work better, hjkl and backspace should be disabled in normal and visual modes.
```vim
nnoremap h <nop>
nnoremap j <nop>
nnoremap k <nop>
nnoremap l <nop>
nnoremap <BACKSPACE> <nop>
vnoremap h <nop>
vnoremap j <nop>
vnoremap k <nop>
vnoremap l <nop>
vnoremap <BACKSPACE> <nop>
```
- This trade-off turns the navigation easier and ubiquitous and makes even more sense when using Colemak.

### Special Keys

- Mod: This special thumb key behaves as follows, when tapped (not hold):
    - If no modifier is active or locked in one-shot mode, it activates the Gui or Ctrl modifier in one-shot mode.
    - In the maintenance layer, we can toggle between Gui and Ctrl, which makes it easier to transition between different operating systems, using the same key combinations for shortcuts like Cmd/Ctrl+S, Cmd/Ctrl+C and Cmd/Ctrl+V.
    - If any modifier is active or locked in one-shot mode, all these modifiers will be released.
- Cap: This special thumb key behaves as follows, when tapped (not hold):
    - If CapsLock is active, it deactivates CapsLock.
    - If Shift is active or locked in one-shot mode, it activates CapsLock.
    - If Shift is not active in one-shot mode, it activates Shift for one-shot.

### Combos

In the base layers, considering the QWERTY layout:
- UIO sends TAB. 
- SDF sends ESC.
- JKL sends ENTER.
- XCV activates the raise layer.
- M,. activates the lower layer.

In the lower layer:
- M,. activates the functions layer.

In the mouse layer:
- M,. activates the navigation layer.

In all layers but the base and maintenance:
- JKL return to the previous layer.

In the lower and raise layers:
- WER swap hands for one shot.
- UIO swap hands for one shot.
- SDF return to the previous layer.

### Tap Dance

- The key below the right pinky key, in the lower (numpad style) layer, sends dot on single tap and comma on double tap.

## Resources

- [QMK Docs](https://docs.qmk.fm)
- [Keyboard Tester](https://config.qmk.fm/#/test)

## References

- [Miryoku](https://github.com/manna-harbour/miryoku)
- [Seniply](https://stevep99.github.io/seniply)
- [Precondition](https://precondition.github.io/home-row-mods)
- [Callum](https://github.com/callum-oakley/qmk_firmware/tree/master/users/callum)
- [Drashna](https://github.com/qmk/qmk_firmware/tree/master/users/drashna)
- [Getreuer](https://github.com/getreuer/qmk-keymap)
- [DreymaR](https://dreymar.colemak.org)
- [Ben Vallack](https://youtube.com/c/BenVallack)
