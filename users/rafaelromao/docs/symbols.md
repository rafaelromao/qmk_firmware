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
- The mouse layer can be disabled, using the maintenance layer. In this case, the navigation layer will be activated in its place instead.

## Functions and Media
- In the base layer, holding Z or ; will activate the functions and media layers, respectively.
- In the lower or raise layers, the two opposite thumb key can be held (or tapped, for one shot) to activate its corresponding layer.
- Tap toggle layers will be toggle on with a single tap.

## Maintenance

##
[Home](../readme.md) | 
Symbols |
[Modifiers](modifiers.md)
