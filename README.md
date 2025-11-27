# Y Board Project
## Initial thoughts
I've  thought about a few different idea options regarding what to do with this Y-board (Maybe later I'll do them sometime on other src files), such as:

- [ ] Using the microphone and audio analysis to display IPA of the sound on the display
- [ ] Making a snake out of the LEDs that would change depending on different switch or knob inputs
- [ ] Using the accelerometer to figure out where one experiences the most inertia on the bus
- [ ] Buying a ton of motors, building a frame for them, and connecting them all to the Y-board to make a drone

## Goal
### Decision
I've decided to work with the accelerometer for the bus. Once built, I'll test it and manually plot data on maps to find out:

 - The turniest turn on my usual bus routes (given a set spot on the bus)
 - The spot on the bus that gives me the greatest portion of inertia (averaged out across turns)

I use the bus multiple times a day, so frequent tests are possible within the next couple weeks.

### Features
This can include the following:

- [x] Lights that react to x- and y- spikes (maybe the lights react most to where the accelerometer is pointing/tipping)
- [ ] Display of the current x/y/z data, with maximums for the current session
- [ ] Switch options for testing different iterations of the above features

## Issues
### Lights
- [ ] Use the knob (or hard coding) to calibrate the lights to display north when tipped north
- [ ] Adjust brightness through math of the x and y values. As both get closer to zero, turn brightness down. As one or both get further from zero, turn brightness up.
- [ ] Change color with direction

### Display


