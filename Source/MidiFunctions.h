/*
  ==============================================================================

    Negative.h
    Created: 3 Oct 2019 10:11:43am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

inline int getNegative(int note, float center, int octave)
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
     *  octave is the value representing the absolute pivot point. we add two
     *  to this value because of the difference between midi standard and theory
     *  standard octave representation.
     *  we use the constant 3.5 to represent the number of half steps needed
     *  to rotate the root to the fifth
     */
    return (2 * (((octave+2) * 12) + center + 3.5)) - note;
}
