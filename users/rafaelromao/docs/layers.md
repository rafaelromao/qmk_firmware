# rafaelromao's keyboard layout

## Base

## Lower and Raise

### Symbols
- Symbols are spread across the lower and raise layers, making them easier to reach with a single hand.
- All symbols are conveniently placed for software programming and VIM commands.

### VIM
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
### Accentuation
- Using the lower layer, we can type `, ', ", ~ and ^ as independent symbols, while in the left side of the raise layer, we can find these keycodes as accents. I had to program some macros in qmk to make it work this way though.
- For example, considering qwerty, holding my left thumb + tapping s + releasing the thumb + tapping c, gives me 'c, while holding my right thumb + tapping f + tapping c, gives me ç. The same goes for the other accents.

## Navigation and Mouse
- Navigation layer gives access to one-shot mods in the left side and VIM style navigation in the right side.
- Mouse layer is similar to the navigation layer, but replaces the arrows and page navigation by mouse and wheel navigation.

### Enter, Esc, Tab, Delete
- Considering qwerty, on the navigation and mouse layers, you find Esc in the Q and Enter in the P.
- Tab is present on the left side of the navigation and mouse layers, in the E, allowing easy access to Cmd/Alt+Tab.
- [Combos](docs/tapdance_combos.md) allow easy access to ENTER, ESC, TAB.
- Shift+Backspace sends Delete, when shift is not one-shot, but Delete is also available under ; in the navigation and mouse layers.

## Functions and Media

## Maintenance

##
[Home](../readme.md)
