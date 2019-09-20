/*
  ==============================================================================

    Theory.h
    Created: 19 Sep 2019 10:03:34pm
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

static String Centers[12] = {
    "C",
    "Db",
    "D",
    "Eb",
    "E",
    "F",
    "Gb",
    "G",
    "Ab",
    "A",
    "Bb",
    "B"
};

inline int get_negative(float center, int note)
{
    float polar = note - center;
    int newNote;
    
    if (center - polar < 0)
    {
        newNote = ((int)(center - polar + 12)) % 12;
    }
    else
    {
        newNote = ((int)(center - polar)) % 12;
    }
    
    return newNote;
}
