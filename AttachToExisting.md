# Setup: Attaching HDT to an existing mesh #

If you have a mesh (not an alt body) and you wish to make it use HDT, this should help you get started. Original guide by Vioxsis. The images are huge and therefore not embedded.


  * [pic](http://www.mediafire.com/view/?i6icymujdobd6qi) Open your body/armour nif (with T/BBP weighting) in nifskope.

  * [pic](http://www.mediafire.com/view/?k7ccjd5ducqdk5z) Right click the block list and go to Block and click insert.

  * [pic](http://www.mediafire.com/view/?55ai2ngysf5doyh) Then go to NiS... and click NiStringExtraData.

  * [pic](http://www.mediafire.com/view/?b6y666s6igr16l0) In block details right click the value for name and click edit string index.

  * [pic](http://www.mediafire.com/view/?uluyha99wl2x81p) Type HDT Havok Path and click OK (Make sure to use caps where shown)

  * [pic](http://www.mediafire.com/view/?n7bcrb9gda19r7m) Right click the value for string data click edit string index, and type the path to your .xml (in my case Data\meshes\actors\character\character assets female\hdtCBBE.xml) and click OK

  * [pic](http://www.mediafire.com/view/?6w4zwhgf6i089wc) Click on the NiNode in the block list and in block details change the num extra data list value to 1

  * Double click the green refresh arrows just below and add the number the NiStringExtraData is using in the block list, it is _**0**_ (zero) in this case.

  * Click save as.

Note: If your mesh is an armor/outfit, you'll need to do the same for the `_1` body/armour. It doesn't matter what body the is is for as long as the body it is weighted for TBBP.