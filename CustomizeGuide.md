# How to Customize #

This is purely a "How I Did It" guide for going thru the customization process. I'm outlining **my** process which has worked well for me for almost a year now of doing this. It's a simple process and you can tweak it as you see fit. However, if you're going to start here, you should finish here before forking off your own process.


I use [Mod Organizer](http://www.nexusmods.com/skyrim/mods/1334/?). I haven't used NMM since probably Jan '12. Therefore, the rest of this guide will assume you're using Mod Organizer. If you're not, well... you can figure it out.


## Shit you need ##
  * Just For Fun v4 (hdtHavokModifier.exe program) known as JFF. Can be found with the full mod download on any site.
  * [Mod Organizer](http://www.nexusmods.com/skyrim/mods/1334): the best most integrated tool for uh... Organizing your Mods.
  * [Microsoft's XML Notepad](http://xmlnotepad.codeplex.com/): Not required, but it's the one I use so I'll be referring to it. All you will need is a solid XML editor. This one beats the pants off of any text editor and most other XML editors.
  * [Work Studios](http://www.loverslab.com/files/file/865-work-studios-v2-shadow-striping-fixed/) skyrim mod: It's just a few small rooms with consistent lighting. Again not required, but it really helps streamline customization. If you don't want to use this mod, then pick a small game area with few or no NPC/AI. It's all about being able to load quickly. `whiterunbreezehome` is good. Even so, references to this will be made considering that Work Studios is in use.

## The way I set it up: ##

  1. **Create a new profile in Mod Organizer.** Copy an existing one making sure the old saves are available. This way you can load a game with your existing showracemenu body config. I use "local save games" so that these saves don't get in the way of my main game.
  1. **Add your body mesh and outfits to the load.** If you use a showracemenu mod, add that too.
  1. **Add HDT PE to your load and make sure it is working.** If it doesn't really work yet, why are you here? Go [InstallHDT](InstallHDT.md) first.
  1. **Add Work Studios to the load.** I have it pretty low but you can put it wherever you want. It overwrites nothing vanilla.
  1. **Put JFF wherever you want and open it.** I put it in a dir way away from the extension and just navigate to open the file. I'll bet that you could just as likely put it in the /skse/plugins dir without a problem. (I haven't done this, but I can't imagine it causing issues)
  1. **Click Load.** Find and open your .XML file.


You now have this screen: ![http://i.minus.com/iT9SnqtkyOWK1.png](http://i.minus.com/iT9SnqtkyOWK1.png)

### Couple of notes about JFF ###
  * Look right here <sup>^</sup>^^ at the bottom of that pic. There's an accordion tab there called Constraints. Click it. It's like a whole other half of the program. It's easy to miss.
  * EVERYTHING does something. All the buttons, sliders, and dropdowns have something in them or are used for something. Sometimes, like the Constraints tab, it's not plainly obvious. But it's there. Other times, the plugin will use the parameter if the mesh calls it. Which means a lot of the fields remain empty.
  * **The main purpose of this program:** See the Add button at the top? If you create say a jangle-rific belly dancer outfit and you want to add/make HDT/PE parameters, start here. It's all well & good to make boobies jiggle like an overdeveloped 19 yr old girl, but the focus of this program is to provide a tool for modders to create things like the earrings, the pony tail, cloaks, skirts, etc.

### Anyway, so... Great! It works. ###

**You could quite literally stop reading here and be just fine. What follows are tweaks that I use to streamline the process**


---


### Why do you need XML Notepad, too? ###
Just For Fun (JFF) is great for the interface and having things in one place... But it can be kinda clicky. If you're just changing 1 value A LOT while you make it perfect, using xml notepad can be much quicker.

## Here's my workflow ##
  1. **Start the game in windowed mode, fullscreen res.** Use ENB Settings or [http://www.nexusmods.com/skyrim/mods/40706/?](OneTweak.md) to set it up. Without it, skyrim basically says "fuck you, betch" when you try to alt-tab. I've never gotten it to work even one cycle without this setup. DO IT.
  1. **Load the save game with the char you want.**
  1. **`console > coc` studioblack (or white or blue).** I use black.
  1. **`console > save hdt`**  Not required, but reloading the game just becomes Enter Enter. _Just a reminder: wherever the camera is pointed will be the savegame covershot._
  1. **shift-tab to pop the steam console.** This brings up the windows cursor. Now click on JFF.
  1. **Change some values in JFF.** This is where you might start using XML Notepad. More below.
  1. **Save to the right place.** Overwrite. Having some kinda backup system prior to this point is a good idea.
  1. **Click on the skyrim window**
  1. **`console > coc` studioblack (or white or blue).** This reloads the cell forcing reload of the .XML file. You do not need to restart the game or reload a save game. This tiny black cell loads in about a second on my not-so-cutting-edge rig. This is precisely the reason I made and use the Work Studios mod.
  1. **Using** a combination of `showracemenu, animcam, and fov` changes, I examine the effects and decide what to change next.
  1. **Repeat from step 5** as needed.

### About step 6: ###
Making symmetrical changes, together, all the time, can be tedious. So I'll work on one item in this cycle, then I'll copy the parameters symmetrically about every 20th generation... just to see. When working on the one item and one parameter, I will use XML Notepad instead of JFF. Why? Simple: Type the value, ctrl-s. JFF would require many many clicks to produce the same output.

### Using XML Notepad in the above workflow ###
  1. **Using JFF, change the value of the parameter that you want to work on to something unique.** If the value is 465.758 then make it **99465.75899**
  1. **In XML Notepad: ctrl-f > 99465.75899** This way you don't have to dig around so much.
  1. **Change** the value
  1. **ctrl-s** to save
  1. **Return to Step 8** in the workflow
While you're working on that single value on that single item, getting it just perfect, this method makes it super fast.

Happy boogedy-boogedy-boogedy-ing!