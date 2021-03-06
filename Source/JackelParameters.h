/*
  ==============================================================================

    JackelParameters.h
    Created: 26 Sep 2019 9:09:02am
    Author:  Nicholas Berriochoa

  ==============================================================================
*/

#pragma once

enum JackelParameters
{
    JP_TonalCenter = 0,
    JP_Octave,
    JP_Mode,
    JP_TotalNumParams
};

#define NUM_TONAL_CENTERS 12
// valid octaves are -2 to 8
#define MAX_NUM_OCTAVES 8

static const String TonalCenterLables[NUM_TONAL_CENTERS] = {
    "Eb",
    "E",
    "F",
    "F#/Gb",
    "G",
    "Ab",
    "A",
    "Bb",
    "B/Cb",
    "C",
    "C#/Db",
    "D"
};

static const String TonalCenterCircle[NUM_TONAL_CENTERS] = {
    "A",
    "E",
    "B/Cb",
    "F#/Gb",
    "C#/Db",
    "Ab",
    "Eb",
    "Bb",
    "F",
    "C",
    "G",
    "D"
};

static const String JPID[JP_TotalNumParams] =
{
    "TonalCenter",
    "Octave",
    "Mode"
};

static const String JPLabel[JP_TotalNumParams] =
{
    "Tonal Center",
    "Octave",
    "Mode"
};

static const int JPDefaultValue[JP_TotalNumParams] =
{
    0, // default tonal center C major
    3, // default octave to middle C
    0
};
