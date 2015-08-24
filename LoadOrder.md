# Load Order #

### Final load order ###
  * SKSE
  * HDT Physics Extension
  * Body
  * Skeleton

A lot of problems can arise from incorrect load order. If you are having problems with the most basic install, make sure your load order is proper.


The best way to do manage load order is to use Mod Organizer. It works by compartmentalizing each mod to it's own directory. It then creates a virtual directory structure (in ram) right before loading the game. Therefore, if you need to change your loading order, you can do so without taking down and rebuilding a fragile stack of files piled into the skyrim dir.


**[Here's what](http://minus.com/i/byIiv0opE1hCs)** a basic HDT Physics load order should look like.


**[Here's what](http://minus.com/i/QQ741hn4g86c)** an install with Other Crap might look like. (HDT Requirements are unchecked simply for hiliting)


### Things of note in the Other Crap pic ###
  * HDT Tripples (Bounce Kit) is after the extension. This will supercede the default.
  * Groovetama's Rig is after the skeleton. This will supercede the XPMS skeleton
  * FFW is my own BodySlide and is after everything that affects body including skin texture.

## Oh . . . One More Thing... ##
If you're not using [Mod Organizer](http://www.nexusmods.com/skyrim/mods/1334), you're simply asking for headaches. The load order is modified by simple drag n drop.
