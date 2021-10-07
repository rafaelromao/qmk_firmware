# rafaelromao

## A 34 key split keyboard on a planck platform, optimized for programmers.

![img](https://i.imgur.com/odzZLMc.jpg)

### Compile

`qmk compile -kb bm40hsrgb -km rafaelromao`

### Flash

`qmk flash -kb bm40hsrgb -km rafaelromao`

## Layout

http://www.keyboard-layout-editor.com/#/gists/59d65a3aafd060cf391e85eef33f5b21

![img](https://i.imgur.com/3Tz8M1p.png)

## Highlights

- All black keys (two center columns, the center space bar, and the 6 outer keys in the last row) are disabled.
- Home row mods make modifiers easier to reach.
  - Dedicated modifier keys are available on most layers, always in the home row.
- The two keys on each thumb cluster control layer transitions, space, tab, backspace, enter and esc.
  - Outer left space activates the navigation layer, when held.
    - On this layer, left pinky key acts as Esc when tapped and shift when held.
    - Outer right space acts as Enter when tapped.
  - Inner left space activates the symbol layer.
    - On this layer, inner right space acts as Tab when tapped.
    - Holding the key below the left pinky key activates the media layer.
  - Outer right space activates the mouse layer.
    - On this layer, right pinky key acts as Enter when tapped and shift when held.
    - Outer left space acts as Esc when tapped.
  - Inner right space activates the number layer.
    - On this layer, inner left space acts as backspace when tapped.
    - Holding the left homming key activates the primary function layer (F1-F9).
    - Holding the key below the left homming key activates the secondary function layer (F10-F12).
    - Holding the right pinky key activates the shifted version of the numpad, allowing single-hand navigation.
      - Double tapping this key sends comma instead of dot.
  - Holding both outer space keys will activate the maintenance layer.
- The key below the left homming key activates the accentuation layer.
  - This works in the symbol layer as well.
- The key below the right homming key activates the operations layer.
  - This works in the number layer as well.
- The keys in the two center columns and the keys in the extreme top left and right are used only in the base layer.
- All symbols are conveniently placed for programming.

## Combos

- Combos allow easy access to ENTER, ESC, TAB and single hand operations.
  - JKL or 456 sends ENTER
  - SDF sends ESC
  - UIO or 789 sends TAB
  - 123 activates the symbol layer for one shot
  - %<> or []\ swap hands for one shot
  - Acc1, Acc2, Acc3 activates the navigation layer
  - Insert, Page Up, Page Down rerurns to the base layer
