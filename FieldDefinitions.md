#### HDT Physics Extension ####
# Definitions #

This doc attempts to explain the use of a few of the different fields in the .xml file. This is not 100% coverage, but it should be enough to get you through most customization. The fields are easily accessible and grouped logically by using Just For Fun v4 (available with any extenstion download).

Thanks to _Yoo_ and _b00marrows_ for their posts on [Lover’s Lab](http://loverslab.com) from which this page was derived.
Their work has been edited only for clarity and formatting.

## Orientation ##
This Cluster is the axis definitions.

![http://i.minus.com/i3Dd2g4CwbXXU.png](http://i.minus.com/i3Dd2g4CwbXXU.png)

  * Angular fields define movement that twists around the axis.
  * Linear fields define movement that travels along the axis.
  * Positive/negative definitions are made relative to the point being defined, not relative to the zero-point of the full mesh.


---


## Rigid Bodies Tab ##

### Generic Properties ###

|Name|The name of which bone this specific set of details will effect|
|:---|:--------------------------------------------------------------|
|Motion Type|_Keyframes:_ The object will follow standard animation positions (I.E. Physics is Disabled). All the others are different types of physics primitives, the mesh object will be 'simplified' to this object and will have the physical properties and equations of the object applied to it in physics calculations in-game|
|Friction|The 'drag' force on the object, otherwise known as the friction constant http://en.wikipedia.org/wiki/Friction. There is no ‘drag’, i.e. friction against air.|
|Restitution|How elastic the collision effects are, 1 being completely elastic, http://en.wikipedia...._of_restitution|


### Advanced Properties ###

|Dampening|How much momentum is lost. The effect is similar to the tensioner on the wheel of a stationary bike. Related to Linear and Angular Constraints. http://forums.corona...linear-damping/|
|:--------|:-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|Gravity Factor|Weight/downwards force multiplier. No info on the accuracy of this desc.                                                                                                              |
|Time Factor|Speed of which all effects "run" higher for quicker bounce with shorter effect, lower for slower bounce with longer effect. Extreme parameters (1.0 is default) can cause the effect to become unstable.|

### Mass Properties ###

|Mass|weight/downwards force of object|
|:---|:-------------------------------|
|Center of Mass|depicts the placement of the center of the object|
|Inertia Tensor|Controls Inertia, Increase numbers to 'tighten' control and decrease number to 'loosen' control. It is directly related to Center Of Mass and Mass.Think of this as an invisible frame that has springs connected to the rigid body. The values change the stiffness of those springs.|

### Collisions ###

|Shape|The mesh object will gain the physical properties of this item in all physics calculations|
|:----|:-----------------------------------------------------------------------------------------|
|GroupID|This is what defines what the object is considered as when colliding with other objects. allowing for the next one to work.|
|No Collide With|This is the "collision control" section. More about it in “Collision Filters and You” (http://www.loverslab.com/topic/27118-collision-filters-and-you/)|



---

## Constraints Tab ##

### Normal ###

|Type|See Normal > Type (next) section.|
|:---|:--------------------------------|
|Body A/B|No info. Appears to be a choice of the defined rigid bodies. |
|Angular|Twist around the axis. On the Z axis, this would be movement similar to a spinning top.|
|Linear|Travel along the axis. On the Z axis, this would be up and down.|
|Motors|The icon to the far right contains the numerical settings. The default setting is hkpSpringDamperConstraintMotor. No info about the other choices.|
|Motor > Spring Constant|The energy behind any movement. Greater mass requires more energy.|
|Motor > Spring Damping|The time of energy falloff.      |
|Angular Basis A/B|No info.                         |
|Min/Max Limits|Defines the extents of Linear/Angular movement|
|Friction|Friction fields do not work properly in Just For Fun. No info about the relationship to the Rigid Bodies friction field.|
|Joint > Pivot|Using these parameters you can move the body to an arbitrary position.|


### Normal > Type ###
#### Ball and Socket ####
_You lock a rigid body to a parent and the child will move in every way._

The ball and socket constraint is the simplest type of constraint provided by the Havok Content Tools. At runtime, this constrains the child space position in the child rigid body to the parent space position in the parent rigid body / world.

---

#### Hinge ####

_Not too much to explain. But, you can limit how much it moves_

The hinge constraint allows you to constrain two rigid bodies together relative to a position and axis in each body's space, or to constrain an axis in one body's space to an axis in world space. The constrained objects are then free to rotate about this axis. The allowed rotation between the attached objects may also be limited. This limit is defined with respect to an axis perpendicular to the hinge axis (the zero-axis) for each body. These sets of axes are defined by the child and parent constraint spaces.

HINGE
http://www.youtube.com/watch?v=kbEbbKqWo_c

LIMITED HINGE
http://www.youtube.com/watch?v=RtueZRPiNQY

---

#### Ragdoll (the secret behind fake Cloth and Hair) ####
Rag doll constraints are useful for simulate complex joints, such as those found in some human and animal joints (shoulders, hips). These joints may require some freedom of rotation in more than one axis, as well as some ability to twist.

Like the other constraints we have seen so far, this one constrains the child space position in the child rigid body to the parent space position in the parent rigid body / world. However the rotational constraints have a somewhat complex parametrization which requires some additional explanation.

The parameters are:
  * Cone angle: The amount of freedom
  * Plane Max - Min: Think about it like a hinge inside the ragdoll. But the respective max values are limited to the cone angle.
  * Twists values: How much it twists from -180° to 180°

http://www.youtube.com/watch?v=Vu3Ld-Z_68o

---

#### Stiff spring (the secret behind cloth pulling mechanics) ####
_If a parent rigid body moves. The child will follow._

The stiff spring constraint constrains the child space position in the child rigid body to lie a set distance from the parent space position in the parent rigid body (as if they were connected by an inflexible rod). As in the ball and socket constraint, there is no constraint on the child or parent space rotation.

http://www.youtube.com/watch?v=xrVueoxxnFA

http://www.youtube.com/watch?v=w_ZT44CipQ0

---

#### Prismatic Constraint (like in "The Dark Side of the Moon") (also usefull for bulge effects) ####
The prismatic constraint constrains the child rigid body to move along a specified axis relative to the parent body by specified distances in each direction (or if not specified, by an unlimited distance).

Mostly used for sliding but you can add an extra layer of control to a ragdoll chain assigning this constraint to the end of it.

http://www.youtube.com/watch?v=W7-maQuz5rA

---

#### Wheel Constraint ####
Its a wheel... how much could I say?

The wheel constraint constrains the child rigid body to rotate about a specified "spinning" axis relative to the parent body, and optionally to translate along a specified "suspension" axis for specified distances in each direction. The "steering" axis is by default aligned with the suspension axis, but may be offset relative to the suspension axis by a specified rotation angle about the spinning axis.