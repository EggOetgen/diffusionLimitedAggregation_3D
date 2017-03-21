# diffusionLimitedAggregation_3D

This program implements a diffusion limited aggregation algorithm to generate 'organic' shapes. Random walkers wander around the screen until they hit a 'stuck' particle, at which point they too become stuck

Since the WIP i have added an abstract base class, three derived classes of sticky particle and replaced as many pointers as possible with smart pointers, as well as general performance improvements



--- //CONTROlS//---

--- Mouse --- will control ofEasyCam
---   1   --- will show random walkers 
---   2   --- will show the bounding sphere, where new walkers will appear
---   3   --- toggle rotation
---   4   --- will add a few particles
---   5   --- will pause the walkers
--- space --- toggle contiusuly adding more particles, be CAREFUL NOT TO CRASH
---   c   --- Will clear all random walkers, use this if starts getting slow


More information about DLA algorithm:-
http://paulbourke.net/fractals/dla/

8-]

