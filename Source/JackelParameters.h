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
    JP_Mode,
    JP_TotalNumParams
};

static const String TonalCenterLables[12] = {
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

static const String JPID[JP_TotalNumParams] =
{
    "TonalCenter",
    "Mode"
};

static const String JPLabel[JP_TotalNumParams] =
{
    "Tonal Center",
    "Mode"
};

static const int JPDefaultValue[JP_TotalNumParams] =
{
    0,
    0
};
