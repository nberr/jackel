/*
  ==============================================================================

    Negative.h
    Created: 3 Oct 2019 10:11:43am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

inline int getNegative(int note, float center)
{
    /*
     *  Old version that did not take octave into account when translating
     *
     *  float polar = note - center;
     *  int newNote = (center - polar < 0) ? ((int)(center - polar + 12)) % 12 :
     *  ((int)(center - polar)) % 12;
     */
    
    /*
     *  calculate the new note
     *  60 is a constant value representing the absolute pivot point (in
     *  this case the pivot is middle C. we use the constant 3.5 to
     *  represent the number of half steps needed to rotate the root to the
     *  fifth
     */
    return (2 * (60 + center + 3.5)) - note;;
}
