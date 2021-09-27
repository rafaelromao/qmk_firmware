# rafaelromao

## A 34 key split keyboard on a planck platform, optimized for programmers.

- All black keys (two center columns, the center space bar, and the 6 outer keys in the last row) are disabled.
- Home row mods make modifiers easier to reach.
- Dedicated modifier keys are available on navigation, mouse, number and function layers.
- The two keys on each thumb cluster control layer transitions, space, tab and backspace.
  - Outer left space activates the navigation layer, when held.
    - On this layer, left pinky key acts as Esc when tapped and shift when held.
  - Inner left space activates the number layer.
  - Inner right space activates the symbol layer.
  - Outer right activates the mouse layer.
    - On this layer, right pinky key acts as Enter when tapped and shift when held.
  - Holding inner left space followed by inner right space allows accessing the symbol layer from the number layer.
  - Holding both outer space keys will activate the maintenance layer.
- Use of the two extreme top keys (Q and P on QWERTY) is reduced.
- All symbols are conveniently placed for programming.
- From the maintenance layer, all primary layers can be toggled on.
  - Function and media layers are secondary and can only be activated from the number layer

### Compile

`qmk compile -kb bm40hsrgb -km rafaelromao`

### Flash

`qmk flash -kb bm40hsrgb -km rafaelromao`

## Layout

http://www.keyboard-layout-editor.com/#/gists/59d65a3aafd060cf391e85eef33f5b21

![img](https://i.imgur.com/Xo5Fadh.png)
