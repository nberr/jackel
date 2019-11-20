/*
  ==============================================================================

    InterfaceDefines.h
    Created: 17 Sep 2019 10:53:04am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#define MAIN_PANEL_WIDTH 800
#define MAIN_PANEL_HEIGHT 450

// space between boxes or the side of the application
#define LARGE_BUFFER 20
#define MEDIUM_BUFFER 10
#define SMALL_BUFFER 5

/*
 ==============================================================================

  Top Panel and Members
  - Midi Selector
  - logo

 ==============================================================================
*/
#define TOP_PANEL_WIDTH MAIN_PANEL_WIDTH
#define TOP_PANEL_HEIGHT 90

// Midi device combobox selector + label
#define MIDI_DEV_CB_WIDTH 530
#define MIDI_DEV_CB_HEIGHT 40

#define LOGO_WIDTH 210
#define LOGO_HEIGHT 60

/*
 ==============================================================================

  Center Panel and Members
  - tonal center
  - translation

 ==============================================================================
*/

#define CENTER_PANEL_WIDTH MAIN_PANEL_WIDTH
#define CENTER_PANEL_HEIGHT 210

#define TONAL_CENTER_WIDTH 370
#define TONAL_CENTER_HEIGHT 190

#define TRANSLATION_WIDTH 370
#define TRANSLATION_HEIGHT 190

/*
 ==============================================================================

  Bottom Panel and Members
  - keyboard display
  - octave selector

 ==============================================================================
*/
#define BOTTOM_PANEL_WIDTH MAIN_PANEL_WIDTH
#define BOTTOM_PANEL_HEIGHT 150

// Keyboard Display
#define MIDI_KB_WIDTH (BOTTOM_PANEL_WIDTH - 40)
#define MIDI_KB_HEIGHT 70

#define OCTAVE_WIDTH MIDI_KB_WIDTH
#define OCTAVE_HEIGHT 40



// use this to draw boxes around groups of buttons
inline void drawRectWithLabel(Graphics& g, Rectangle<float> r, String name)
{
    g.drawRoundedRectangle(r.withTrimmedTop(5), 2, 2);
    //g.drawSingleLineText(name, r.getTopRight().toInt(), 2);
}
