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
#define MIDI_KB_WIDTH BOTTOM_PANEL_WIDTH - 40
#define MIDI_KB_HEIGHT 100

// Tonal Center Panel
#define TC_BOX_WIDTH (BOTTOM_PANEL_WIDTH - (BOTTOM_PANEL_WIDTH * 0.6)) - 30
#define TC_BOX_HEIGHT 190

#define TC_LABEL_WIDTH 20
#define TC_LABEL_HEIGHT 20

#define TC_DISPLAY_WIDTH 10
#define TC_DISPLAY_HEIGHT 10

#define TC_BUTTON_WIDTH 5
#define TC_BUTTON_HEIGHT 5

// Translated Panel
#define MAPPED_BOX_WIDTH (BOTTOM_PANEL_WIDTH - (BOTTOM_PANEL_WIDTH * 0.4)) - 30
#define MAPPED_BOX_HEIGHT 190

#define OG_LABEL_WIDTH 10
#define OG_LABEL_HEIGHT 10

#define OG_DISPLAY_WIDTH 10
#define OG_DISPLAY_HEIGHT 10

#define NEG_LABEL_WIDTH 10
#define NEG_LABEL_HEIGHT 10

#define NEG_DISPLAY_WIDTH 10
#define NEG_DISPLAY_HEIGHT 10

/*
 ==============================================================================

  Side Panels for logo area

 ==============================================================================
*/

#define SIDE_PANEL_WIDTH (MAIN_PANEL_WIDTH - (MAIN_PANEL_WIDTH * 0.9))
#define SIDE_PANEL_HEIGHT BOTTOM_PANEL_HEIGHT
