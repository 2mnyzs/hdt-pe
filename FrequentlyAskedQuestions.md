# Frequently Asked Questions #

### Here's a list of commonly asked questions and the answers to them. ###
> <table cellpadding='1' border='1' cellspacing='1'>
<blockquote><tbody>
<blockquote><tr>
<blockquote><td>
<blockquote><div>Q: When I take off the outfit, the game crashes!</div>
<div>Q: HDT PE crashes when I use a custom race or standalone follower.</div>
<div>Q: My game crashes as soon as I loot an armour from a human NPC.</div>
<div>Q: My program constantly crashes on load after installing HDT PE. Nothing else was changed in my mod setup and it used to run fine. What went wrong?</div>
</blockquote></td>
<td>
<blockquote>A: Make sure you are using XPMS or XPMS Extended.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: My boobs often look like a particle in Brownian motion!</td>
</blockquote><td>
<blockquote>A: It's time to find another hdtPhysicsExtensionsDefaultBBP.xml and other .xml's(if you use any).</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote><div>Q: I edit the NPC Breasts and NPC Butt bones in JFF/text editor. But no changes occur?</div>
</blockquote></td>
<td>
<blockquote>A: Make sure NPC Pre-Breasts and NPC Pre-Butts are set to virtual object under group id and are keyframe objects</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: Where is the HDT log file?</td>
</blockquote><td>
<blockquote><div>A: <a href='Skyrim.md'>Path</a>\Data\SKSE\Plugins\hdtPhysicsExtensions.log</div>
</blockquote></td>
</blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: HDT PE crashes my game when I have SOS Light installed.</td>
</blockquote><td>
<blockquote><div>A: Make sure that the SOS Light skeleton overwrites the male skeleton provided in XMPS Extended.</div>
</blockquote></td>
</blockquote></tr>
<tr>
<blockquote><td>
<blockquote><div>Q: HDT PE is working, but I don't get breast collision.</div>
</blockquote></td>
<td>
<blockquote>A: The armour mesh you use must be BBP compatible. If the BBP effect works on your body but not on your armour, your armour is not BBP compatible.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: When using breast collision with the Havok Physics Object, the breasts often get 'stuck' in weird positions. How to fix this?</td>
</blockquote><td>
<blockquote>A: Your skeleton, HDT PE version, and HDT xml configurations must agree with each other. Most likely you have happened to pick a combination which doesn't work well. You can find a group of files that work well together here (for example). Alternatively, you can simply unequip the HDT Havok Physics Object, exit the inventory screen (breasts should go back to normal) and re-equip it afterwards.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: After calling 'showracemenu' on the Skyrim console with the Race Menu mod installed, the HDT BBP and/or HDT hair effects stops working.</td>
</blockquote><td>
<blockquote>A: This seems to be a bug. Saving your game, quitting to desktop and restarting it should fix this issue.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: Using HDT PE with 'Realistic Ragdolls and Force' crashes my game.</td>
</blockquote><td>
<blockquote>A: Make sure that the XMPS Skeleton Extended overwrites the skeleton provided by Realistic Ragdolls and Force.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: How do I get a Havok Physics Object in-game after installing a mod that contains it?</td>
</blockquote><td>
<blockquote>A: Either kill a human NPC and loot it, or open the console and type 'help havok'. This should list a couple of entries, where one is labelled as 'armour'. It has an object ID consisting of uppercase letters and numbers. Type 'player.additem <a href='id.md'>id</a> 1' where <a href='id.md'>id</a> is the object ID of the armour.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: I use the XMPS Skeleton Extended, but I still get crashes with HDT PE. Why?</td>
</blockquote><td>
<blockquote>A: There is a FOMOD installer for the XMPS Skeleton Extended Mod. In one of the pages, it asks you if you are going to use an HDT-based mod. Make sure you tick the 'yes' option when installing.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: My character's breasts look 'crushed' when using HDT PE. How to fix this?</td>
</blockquote><td>
<blockquote>A: It depends on your exact setup, but often it helps to rename the file 'skeleton_female.hkx' (located in 'Data/meshes/actors/character/character assets female/') to something else, e.g. 'skeleton_female.hkx.bak'. This will prevent Skyrim from finding the file and HDT PE is in full control, avoiding the crushed look.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: Breast collision works but the hands are clipping through the boobs all the time. What's wrong?</td>
</blockquote><td>
<blockquote><div>A: The animation itself is a fixed movement and suitable for a given boob size only. If you want no clipping, go ahead and reduce the size of the boobs. You've got to make compromises here.</div>
</blockquote></td>
</blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: I'm doing a manual HDT PE installation. In which file location do the <code>*.dll</code> and <code>*.xml</code> files go?</td>
</blockquote><td>
<blockquote>A: Into Skyrim/Data/SKSE/plugins.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: I'd like to use HDT PE with CBBE. Do I really need CHSBHC in order to make it work?</td>
</blockquote><td>
<blockquote>A: No. But you do need a (T)BBP compatible body (and skeleton). CHSBHC is one such body, but there are alternatives. For example, go and get Bodyslide 2 and Outfit Studio, run Bodyslide 2 and select 'Caliente Body Advanced TBBP' as your body, do some modifications if you want and hit 'Build Bodies' (or 'Batch Build' if you want to build armors along with the body). That's all you need to get a TBBP-compatible CBBE mesh. Install the  XMPS Extended skeleton and you should be good to go.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: I'm using Nexus Mod Manager / I am doing a manual installation. What's the proper overwrite order for the required mods for HDT PE?</td>
</blockquote><td>
<blockquote>A: SKSE followed by Body mod (CBBE, UNP...) followed by Realistic Ragdolls and Force followed by XMPS Skeleton Extended  (always overriding all previous files) followed by actual HDT PE mod.</td>
</blockquote></blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: I have SKSE and HDT PE installed.But the breasts do not jiggle</td>
</blockquote><td>
<blockquote><div>- You have to start Skyrim with the SKSE launcher</div>
<div>- You need a TBBP compatible skeleton: <a href='http://www.loverslab...leton-extended/'>http://www.loverslab...leton-extended/</a></div>
<div>- If you use a custom race, check if the breed has its own skeleton and replace it</div>
<div>- You need at least a BBP Body and Armor, better TBBP</div>
</blockquote></td>
</blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: My breasts and / or buttocks flutters . It does not stop</td>
</blockquote><td>
<blockquote><div>- Each xml is written for a specific version of the DLL</div>
<div>- Do not mix the xml with other dll - stick to the specification from the xml Authors</div>
<div>- Edit the XML with 'Just For Fun' - Tool or editor of your choice.</div>
<div>- Use the group id 's and the collision filter.</div>
<div>- Check fit and calculate whether CapsuleShape to your BodySet the friction and Restutition to 0</div>
<div>- Find a stable value by tests. My recommendation - Breast and Butt always 0, it is enough if hands etc. have a coefficient of friction.</div>
</blockquote></td>
</blockquote></tr>
<tr>
<blockquote><td>
<blockquote>Q: My breasts play at Crazy SexLab - animations with a man</td>
</blockquote><td>
<blockquote><div>- The used hdt.xml was not edited</div>
<div>- The hdt.xml requires clean settings for group id 's and collision filter</div>
</blockquote></td>
</blockquote></tr>
<tr>
<blockquote><td>
<blockquote><div>Q: My breasts wiggle is too strong?</div>
</blockquote></td>
<td>
<blockquote><div>- Havok is a Physic software.</div>
<div>- Force = mass <code>*</code> acceleration:  Reduce the mass</div>
</blockquote></td>
</blockquote></tr>
</blockquote></tbody>
</blockquote><blockquote></table>