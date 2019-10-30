# GameShow
GameShow Buttons, LEDs, sounds  Built for GameShowFanatics (https://gameshowfanatics.com)

Game Show setup w/2 player buttons (first to hit 'wins' round) using PJRC Teensy, Neopixel leds, buttons, sounds, etc.  WORKS!!

This is the electronics for a podium to support a game show akin to Family Feud (etc), where two players try to hit their respective buttons first after hearing a question.  Winner gets to answer the question with their teammates. 

The system has 2 large arcade buttons, three smaller mode buttons for the host, Neopixel leds in large buttons, 5v leds in mode buttons, NeoPixe led strips adorning the podium edges, and audio output for various sounds.  It is intended to get power from either a battery system or wall AC.

The system needs to be packed up for mobile travel to.from venues with easy setup.  The physical podium was not designed when we started back in 2016, but in 2019 we have a nice folding design using 80/20 aluminum, acrylic and wood, with fabric covering.  The mobile requirement, and prototyping, made it essential to have connectors between everything.  The project evolved from breadboad wires, to crimp connectors, to RJ-45 cat 5 cables, to lever connectors, to ???  The 7 basic out components had over 100 connections at some points in the design.

Main Components:
* PJRC Teensy 3.2 microcontroller (https://www.pjrc.com/store/teensy32.html)
* PJRC OctoWS2811 Adapter (https://www.pjrc.com/store/octo28_adaptor.html)
* 3 Ultimarc Ultralux arcade buttons (https://www.ultimarc.com/ultralux.html)
* 2 Adafruit Massive Arcade Buttons (https://www.adafruit.com/product/1187)
* 2 Adafruit Neopixel Rings (https://www.adafruit.com/product/1643)
* WS8211 rgbw strip (https://www.amazon.com/gp/product/B01MTW2L6B)

The large buttons have a center LED plus a neopixel ring inside (per http://www.instructables.com/id/Neopixel-Dome-Button/).  Each of these then has connections for: 5v power, ground, button sense, led drive, ring drive (5, with gnd going to several points)
The smaller buttons were originally Adafruit buttons hacked to have a single neopixel inside. but these started failing after a few months use.  They also did not fit the acrylic top, so we changed over to use Ultimarc Ultralux arcade buttons with 5vdc leds. It required a couple extra lines but fit acrylic MUCH better and skipped need for more neopixels.

My NeoEffects library (https://github.com/MauiJerry/NeoEffects_library) is used to provide the blinky effects.  It also supports multiple effects in a single 'strip'.  We have 5 strips - 2 rings in player buttons, one strip around top edge, one each on left/right front vertical edges.

Audio is from Teensy's 12bit DAC on pin A14. It plays quite well and we only needed a couple simple sounds. This eliminated earlier use of the PJRC Audio board, or an SD card reader board.

Original design was for the electronics to reside in the audio amp, but we changed to use a standard PA amp, and put all the electronics in the  podium top.  This greatly reduced the connections required off the top.  Now there is only 5vdc power in, audio out and a cable to the two vertical strips.
