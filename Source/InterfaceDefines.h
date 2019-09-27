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

#define LARGE_BUFFER 20
#define MEDIUM_BUFFER 10
#define SMALL_BUFFER 5

/*
 ==============================================================================

  Top Panel and Members

 ==============================================================================
*/
#define TOP_PANEL_WIDTH MAIN_PANEL_WIDTH
#define TOP_PANEL_HEIGHT 100

// Midi device combobox selector + label
#define MIDI_DEV_CB_WIDTH (((TOP_PANEL_WIDTH - (TOP_PANEL_WIDTH * 0.3)) * 0.85) - 50)
#define MIDI_DEV_CB_HEIGHT 50

#define MIDI_DEV_LB_WIDTH ((TOP_PANEL_WIDTH - (TOP_PANEL_WIDTH * 0.3)) * 0.15)
#define MIDI_DEV_LB_HEIGHT 50

// Mode Label, display box, buttons
#define MODE_LABEL_WIDTH 10
#define MODE_LABEL_HEIGHT 10

#define MODE_DISPLAY WIDTH 10
#define MODE_DISPLAY_HEIGHT 10

#define MODE_BUTTON_WIDTH 10
#define MODE_BUTTON_HEIGHT 10

/*
 ==============================================================================

  Bottom Panel and Members

 ==============================================================================
*/
#define BOTTOM_PANEL_WIDTH (MAIN_PANEL_WIDTH - (MAIN_PANEL_WIDTH * 0.2))
#define BOTTOM_PANEL_HEIGHT (MAIN_PANEL_HEIGHT - TOP_PANEL_HEIGHT)

// Keyboard Display
#define MIDI_KB_WIDTH (BOTTOM_PANEL_WIDTH - 40)
#define MIDI_KB_HEIGHT 100

// Tonal Center Panel
#define TC_BOX_WIDTH ((BOTTOM_PANEL_WIDTH - (BOTTOM_PANEL_WIDTH * 0.6)) - 30)
#define TC_BOX_HEIGHT 190

#define TC_LABEL_WIDTH 100
#define TC_LABEL_HEIGHT 50

#define TC_DISPLAY_WIDTH (TC_BOX_HEIGHT - (3 * MEDIUM_BUFFER) - TC_LABEL_HEIGHT)
#define TC_DISPLAY_HEIGHT TC_DISPLAY_WIDTH // make it square

#define TC_BUTTON_DISPLAY_WIDTH ((TC_BOX_WIDTH - (3 * MEDIUM_BUFFER)) - TC_DISPLAY_WIDTH)
#define TC_BUTTON_DISPLAY_HEIGHT ((TC_DISPLAY_HEIGHT / 2) - SMALL_BUFFER)

#define TC_BUTTON_WIDTH (TC_BUTTON_DISPLAY_WIDTH - SMALL_BUFFER)
#define TC_BUTTON_HEIGHT (TC_BUTTON_DISPLAY_HEIGHT - SMALL_BUFFER)

// Translated Panel
#define MAPPED_BOX_WIDTH ((BOTTOM_PANEL_WIDTH - (BOTTOM_PANEL_WIDTH * 0.4)) - 30)
#define MAPPED_BOX_HEIGHT 190

#define OG_DISPLAY_WIDTH ((MAPPED_BOX_WIDTH - (MAPPED_BOX_WIDTH * 0.6)) - (2 * MEDIUM_BUFFER))
#define OG_DISPLAY_HEIGHT OG_DISPLAY_WIDTH // make it square

#define OG_LABEL_WIDTH OG_DISPLAY_WIDTH
#define OG_LABEL_HEIGHT 50

#define NEG_DISPLAY_WIDTH OG_DISPLAY_HEIGHT
#define NEG_DISPLAY_HEIGHT OG_DISPLAY_HEIGHT

#define NEG_LABEL_WIDTH NEG_DISPLAY_WIDTH
#define NEG_LABEL_HEIGHT 50

/*
 ==============================================================================

  Side Panels for logo area

 ==============================================================================
*/

#define SIDE_PANEL_WIDTH (MAIN_PANEL_WIDTH - (MAIN_PANEL_WIDTH * 0.9))
#define SIDE_PANEL_HEIGHT BOTTOM_PANEL_HEIGHT
