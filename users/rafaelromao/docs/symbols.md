# rafaelromao's keyboard layout

### Symbols and Numbers
Symbols and Numbers are available in the two classic layers, Lower and Raise, activated holding the space and backspace thumb keys, respectively.
![img](https://i.imgur.com/kP6jRXE.png)
- Symbols are available in the left side of the lower layer and in the right side of the raise layers, making them easier to reach with a single hand.
- Accents are available in the left side of the raise layer, so they require two hands to access them.
- Number are available in the right side of the lower layer, also requiring two hands to access them, but that can be mitigated using a two keys combo with the right hand, in the bottom row, to toggle the lower layer on permanently.
- A combo with the three fingers in the home row can be used to toggle the layer off.
- Enter and Esc are available in the Lower and Raise layer, as well as in the Navigation and Mouse layers, in the same positions.

### Lower Symbols
- String delimiters, conditional operators, parenthesis and square brackets, among others, are found in the left side of the Lower layer.
- Source code: [macros.c](../features/macros.c)

### Raise Symbols
- Symbols that are commonly used in VIM are placed in the right side of the Raise layer, making them easily accessible using only the right hand.
- Curly braces and angle brackets are also found in the right side of this layer.
- Some common programmer n-grams, like ->, =>, \<!--, -->, <>, />, !=, :=, +=, -=, ${, can all be typed rolling through keys in the right hand.

### Numpad
- In the right side of the Lower layer, there is a numpad, replicating the traditional numpad of 100% keyboards.
- The Raise layer can be activated on top of the Lower layer, holding the left home thumb key, which make it easier to access math operators when working with the numpad.
- A tap dance is used to give access to both comma and dot in the pinky key, which makes it easier to use different locales with different decimal separators.
- Source code: [tapdance.c](../features/tapdance.c)

### Accentuation
- Accents are available in the left side of the raise layer, while non-accent versions of these symbols are available in the left side of the Lower layer and in the right side of the Raise layer.
- For example, considering qwerty, holding my left thumb + tapping s + releasing the thumb + tapping c, gives me 'c, while holding my right thumb + tapping f + tapping c, gives me ç. The same goes for the other accents.


##
[Home](../readme.md) | 
[Layout](layout.md) |
[Modifiers](modifiers.md) |
Symbols and Numbers |
[Functions and Media](functions.md) | 
[Navigation and Mouse](navigation.md) |
[Maintenance](maintenance.md) |
