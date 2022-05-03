/*
  ==============================================================================

    JackelGUI.h
    Created: 25 Apr 2022 6:26:39pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

namespace JackelGUI {

const int width = 900;
const int height = 500;

namespace MenuPanelGUI {

const int width = JackelGUI::width * 0.1f;
const int height = JackelGUI::height;

};

namespace PresetPanelGUI {

const int width = JackelGUI::width - MenuPanelGUI::width;
const int height = JackelGUI::height * 0.1f;

};

namespace MainPanelGUI {

const int width = PresetPanelGUI::width;
const int height = JackelGUI::height - PresetPanelGUI::height;

};

};
