/*
  ==============================================================================

    JackelLookAndFeel.h
    Created: 9 Oct 2019 9:58:06am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

// tonal center display
const Colour JackelColour_HighlightBg = Colour(235,  94,  40); // vivid vermillion
// tonal center words
const Colour JackelColour_HighlightText = Colour(235, 94, 40); //

// outline, text, buttons
const Colour JackelColour_Darker = Colour(64,   61,  57); // black olive
// top panel
const Colour JackelColour_Dark = Colour(204, 197, 185); // pale silver
// side bars
const Colour JackelColour_Medium = Colour(255, 252, 242); // floral white
// bottom panel
const Colour JackelColour_Light = Colour(255, 252, 242); // floral white
// tonal center, combobox
const Colour JackelColour_Lighter = Colour(255, 252, 242); // floral white

const Font font_1 ("Helvetica Neue", 12.00f, Font::bold);
const Font font_2 ("Helvetica Neue", 22.00f, Font::bold);
const Font font_3 ("Helvetica Neue", 48.00f, Font::bold);

class JackelLookAndFeel
:   public LookAndFeel_V4
{
public:
    JackelLookAndFeel()
    {
        // set look and feel for popup menu (drop down menu from combobox)
        setColour(PopupMenu::backgroundColourId, JackelColour_Lighter);
        setColour(PopupMenu::textColourId, JackelColour_HighlightText);
        setColour(PopupMenu::highlightedBackgroundColourId, JackelColour_HighlightBg);
    }
    
    virtual ~JackelLookAndFeel()
    {
        
    }
    
private:
    
};


