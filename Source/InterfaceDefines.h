/*
  ==============================================================================

    InterfaceDefines.h
    Created: 17 Sep 2019 10:53:04am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

/*
 ==============================================================================

  Main Panel and Members
  - Top Panel
  - Center Panel
  - Bottom Panel
  - Popout Panel

 ==============================================================================
*/

#define WIDTH 4
#define HEIGHT 3

#define SCALE 180

#define MAIN_PANEL_WIDTH (WIDTH * SCALE)
#define MAIN_PANEL_HEIGHT (HEIGHT * SCALE)

/*
 ==============================================================================

  Top Panel and Members
  - logo
  - preset panel

 ==============================================================================
*/

#define TOP_PANEL_WIDTH MAIN_PANEL_WIDTH
#define TOP_PANEL_HEIGHT (MAIN_PANEL_HEIGHT * 0.2)

#define LOGO_PANEL_WIDTH MAIN_PANEL_WIDTH
#define LOGO_PANEL_HEIGHT (TOP_PANEL_HEIGHT * 0.5)

#define JACKEL_WIDTH ((LOGO_PANEL_WIDTH - (MAIN_PANEL_WIDTH * 0.4)) * 0.5)
#define JACKEL_HEIGHT LOGO_PANEL_HEIGHT

#define LOGO_WIDTH JACKEL_WIDTH
#define LOGO_HEIGHT LOGO_PANEL_HEIGHT

#define PRESET_PANEL_WIDTH MAIN_PANEL_WIDTH
#define PRESET_PANEL_HEIGHT (TOP_PANEL_HEIGHT * 0.5)

#define PRESET_DISPLAY_WIDTH (MAIN_PANEL_WIDTH * 0.4)
#define PRESET_DISPLAY_HEIGHT (PRESET_PANEL_HEIGHT * 0.6)

#define PRESET_NEXT_WIDTH 50
#define PRESET_NEXT_HEIGHT (PRESET_PANEL_HEIGHT * 0.6)

#define PRESET_PREV_WIDTH PRESET_NEXT_WIDTH
#define PRESET_PREV_HEIGHT PRESET_NEXT_HEIGHT

#define PRESET_NEW_WIDTH 50
#define PRESET_NEW_HEIGHT (PRESET_PANEL_HEIGHT * 0.6)

#define PRESET_SAVE_WIDTH PRESET_NEW_WIDTH
#define PRESET_SAVE_HEIGHT PRESET_NEW_HEIGHT

#define PRESET_TOTAL_WIDTH (PRESET_NEW_WIDTH + PRESET_PREV_WIDTH + PRESET_DISPLAY_WIDTH + PRESET_NEXT_WIDTH + PRESET_SAVE_WIDTH)

/*
 ==============================================================================

  Center Panel and Members
  - Device Selector
  - tonal center
  - input chord
  - output chord
  - Octave Selector

 ==============================================================================
*/

#define CENTER_PANEL_WIDTH MAIN_PANEL_WIDTH
#define CENTER_PANEL_HEIGHT (MAIN_PANEL_HEIGHT * 0.6)


#define DEVICE_SELECT_WIDTH MAIN_PANEL_WIDTH
#define DEVICE_SELECT_HEIGHT (TOP_PANEL_HEIGHT * 0.40)

#define TONAL_CENTER_WIDTH (MAIN_PANEL_WIDTH * 0.4)
#define TONAL_CENTER_HEIGHT (MAIN_PANEL_HEIGHT * 0.4)

#define INPUT_CHORD_WIDTH (TONAL_CENTER_WIDTH * 0.5)
#define INPUT_CHORD_HEIGHT INPUT_CHORD_WIDTH

#define OUTPUT_CHORD_WIDTH INPUT_CHORD_WIDTH
#define OUTPUT_CHORD_HEIGHT INPUT_CHORD_WIDTH

#define OCTAVE_PANEL_WIDTH MAIN_PANEL_WIDTH
#define OCTAVE_PANEL_HEIGHT LOGO_PANEL_HEIGHT

#define OCTAVE_SELECT_WIDTH PRESET_TOTAL_WIDTH
#define OCTAVE_SELECT_HEIGHT (TOP_PANEL_HEIGHT * 0.40)

#define OCTAVE_BUTTON_WIDTH (OCTAVE_SELECT_WIDTH / 12)
#define OCTAVE_BUTTON_HEIGHT (OCTAVE_SELECT_HEIGHT * 0.5)

/*
 ==============================================================================

  Bottom Panel and Members
  - Keyboard Display

 ==============================================================================
*/

#define BOTTOM_PANEL_WIDTH MAIN_PANEL_WIDTH
#define BOTTOM_PANEL_HEIGHT TOP_PANEL_HEIGHT

#define KEYBOARD_WIDTH (BOTTOM_PANEL_WIDTH - 71)
#define KEYBOARD_HEIGHT (BOTTOM_PANEL_HEIGHT - 30)

/*
 ==============================================================================

  Popout Panel and Members
  - Translation

 ==============================================================================
*/

#define POPOUT_BUTTON_WIDTH 25
#define POPOUT_BUTTON_HEIGHT MAIN_PANEL_HEIGHT

#define POPOUT_PANEL_WIDTH (MAIN_PANEL_WIDTH * 0.5)
#define POPOUT_PANEL_HEIGHT (MAIN_PANEL_HEIGHT * 0.6)

#define TRANSLATION_WIDTH TONAL_CENTER_WIDTH
#define TRANSLATION_HEIGHT TONAL_CENTER_HEIGHT







// space between boxes or the side of the application
#define LARGE_BUFFER 20
#define MEDIUM_BUFFER 10
#define SMALL_BUFFER 5


// Midi device combobox selector + label
#define MIDI_DEV_CB_WIDTH 530
#define MIDI_DEV_CB_HEIGHT 40



/*
 ==============================================================================

  Center Panel and Members
  - tonal center
  - translation

 ==============================================================================
*/




#define TC_BUTTON_WIDTH 80
#define TC_BUTTON_HEIGHT 45


#define TRANSLATION_LABEL_WIDTH 40
#define TRANSLATION_LABEL_HEIGHT 40

/*
 ==============================================================================

  Bottom Panel and Members
  - keyboard display
  - octave selector

 ==============================================================================
*/



#define OCTAVE_WIDTH 5
#define OCTAVE_HEIGHT 40




// use this to draw boxes around groups of buttons
inline void drawRectWithLabel(Graphics& g, Rectangle<float> r, String name)
{
    g.drawRoundedRectangle(r.withTrimmedTop(5), 2, 2);
    // g.drawSingleLineText(name, r.getTopRight().getX(), 2);
}
