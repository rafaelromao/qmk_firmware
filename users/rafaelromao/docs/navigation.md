# rafaelromao's keyboard layout

## Navigation and Mouse
The Navigation and Mouse layer can be activated holding the outer left and right thumb keys, respectively.
![img](https://i.imgur.com/Qaef03m.png)

## Navigation
- It gives access to [one-shot mods](modifiers.md), along with tab and esc, in the left side and VIM style navigation, along with page navigation, insert, delete, home, end and enter, in the right side.
- In VIM, navigation with hjkl should be ignored in favor of the navigation with the fingers in the home position, using the navigation layer.
    - For that to work better, hjkl should be disabled in normal and visual modes:
        ```vim
        nnoremap h <nop>
        nnoremap j <nop>
        nnoremap k <nop>
        nnoremap l <nop>
        vnoremap h <nop>
        vnoremap j <nop>
        vnoremap k <nop>
        vnoremap l <nop>
        ```
    - This trade-off turns the navigation easier and ubiquitous and makes even more sense when using Colemak.
- Once in the Navigation layer, it is possible to keep the layer on permanently, using a combo with the three main fingers in the bottom row.
- Using a combo with the three main fingers in the home row, the Navigation layer is toggled off.

## Mouse
- It is similar to the navigation layer, but replaces the arrows and page navigation by mouse and wheel navigation.
- From the Mouse layer, it is possible to toggle the Navigation layer on with a combo, also using the three main fingers in the bottom row. It allow single hand access to the Navigation layer.

### Mouse Buttons
- The third and fourth mouse buttons can be triggered double tapping the first and second button keys, on the right side of the mouse layer.
- The first and second buttons are mirrored in the left side of the mouse layer, but without this tap dancing, since it prevents drag and drop from working as expected.

### Mouse Layer Toggle
- The mouse layer can be disabled, using the [maintenance](maintenance.md) layer. In this case, the navigation layer will be activated in its place.
- Source code: [mouselayer_toggle.c](../features/mouselayer_toggle.c)

##
[Home](../readme.md) | 
[Layout](layout.md) |
[Modifiers](modifiers.md) |
Symbols and Numbers |
[Functions and Media](functions.md) | 
Navigation and Mouse |
[Maintenance](maintenance.md) |
