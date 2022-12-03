workspace "EmvTagParser"
   configurations { "Debug", "Release" }
   platforms { "Win32", "Win64", "Linux" }

include "projectscript.lua"
include "tests.lua"