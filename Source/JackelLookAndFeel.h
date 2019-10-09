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
const Colour JackelColour_Highlight = Colour(235,  94,  40); // vivid vermillion

// lines and words and buttons
const Colour JackelColour_Base1     = Colour(37,   36,  34); // raisin black
// top and side panels
const Colour JackelColour_Base2     = Colour(64,   61,  57); // black olive
// center panel, combobox
const Colour JackelColour_Base3     = Colour(204, 197, 185); // pale silver
// tonal center
const Colour JackelColour_Base4     = Colour(255, 252, 242); // floral white

const Font font_1 ("Helvetica Neue", 12.00f, Font::bold);
const Font font_2 ("Helvetica Neue", 22.00f, Font::bold);
const Font font_3 ("Helvetica Neue", 48.00f, Font::bold);

class JackelLookAndFeel
:   public LookAndFeel_V4
{
public:
    JackelLookAndFeel()
    {
        setColour(PopupMenu::backgroundColourId, JackelColour_Base3);
        setColour(PopupMenu::textColourId, JackelColour_Base1);
        setColour(PopupMenu::highlightedBackgroundColourId, JackelColour_Highlight);
    }
    
    virtual ~JackelLookAndFeel()
    {
        
    }
    
private:
    
};


