#-------------------------------------------------
#
# Project created by QtCreator 2013-11-25T18:33:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hdtHavokModifier
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    havokhelper.cpp \
    dialogrigidbody.cpp \
    vec3setter.cpp \
    vec4setter.cpp \
    collisionfiltersetter.cpp \
    masspropertysetter.cpp \
    matrix33setter.cpp \
    dialogshapesetter.cpp \
    shapesetterbase.cpp \
    sphereshapesetter.cpp \
    capsuleshapesetter.cpp \
    boxshapesetter.cpp \
    cylindershapesetter.cpp \
    triangleshapesetter.cpp \
    translatedshapesetter.cpp \
    dialogrotation.cpp \
    transformshapesetter.cpp \
    listshapesetter.cpp \
    rotationsetter.cpp \
    dialogconstraint.cpp \
    ballandsocket.cpp \
    constraintbase.cpp \
    linearclearance.cpp \
    cogwheel.cpp \
    deformablefixed.cpp \
    fixed.cpp \
    hinge.cpp \
    hingelimits.cpp \
    limitedhinge.cpp \
    pointtoplane.cpp \
    prismatic.cpp \
    rackandpinion.cpp \
    ragdoll.cpp \
    ragdolllimit.cpp \
    rotational.cpp \
    stiffspring.cpp \
    malleable.cpp \
    wheel.cpp \
    motorselector.cpp \
    motorbase.cpp \
    motorposition.cpp \
    motorspringdamper.cpp \
    motorvelocity.cpp \
    generic.cpp \
    chainballsocket.cpp \
    chainstiffspring.cpp \
    chainpowered.cpp \
    chainbase.cpp \
    shapeselector.cpp

HEADERS  += mainwindow.h \
    havokhelper.h \
    dialogrigidbody.h \
    vec3setter.h \
    vec4setter.h \
    collisionfiltersetter.h \
    masspropertysetter.h \
    matrix33setter.h \
    dialogshapesetter.h \
    shapesetterbase.h \
    sphereshapesetter.h \
    capsuleshapesetter.h \
    boxshapesetter.h \
    cylindershapesetter.h \
    triangleshapesetter.h \
    translatedshapesetter.h \
    dialogrotation.h \
    transformshapesetter.h \
    listshapesetter.h \
    rotationsetter.h \
    dialogconstraint.h \
    ballandsocket.h \
    constraintbase.h \
    linearclearance.h \
    cogwheel.h \
    deformablefixed.h \
    fixed.h \
    hinge.h \
    hingelimits.h \
    limitedhinge.h \
    pointtoplane.h \
    prismatic.h \
    rackandpinion.h \
    ragdoll.h \
    ragdolllimit.h \
    rotational.h \
    stiffspring.h \
    malleable.h \
    wheel.h \
    motorselector.h \
    motorbase.h \
    motorspringdamper.h \
    motorposition.h \
    motorvelocity.h \
    generic.h \
    chainballsocket.h \
    chainstiffspring.h \
    chainpowered.h \
    chainbase.h \
    shapeselector.h

FORMS    += mainwindow.ui \
    dialogrigidbody.ui \
    vec3setter.ui \
    vec4setter.ui \
    collisionfiltersetter.ui \
    masspropertysetter.ui \
    matrix33setter.ui \
    dialogshapesetter.ui \
    sphereshapesetter.ui \
    capsuleshapesetter.ui \
    boxshapesetter.ui \
    cylindershapesetter.ui \
    triangleshapesetter.ui \
    translatedshapesetter.ui \
    dialogrotation.ui \
    transformshapesetter.ui \
    listshapesetter.ui \
    rotationsetter.ui \
    dialogconstraint.ui \
    ballandsocket.ui \
    linearclearance.ui \
    cogwheel.ui \
    deformablefixed.ui \
    fixed.ui \
    hinge.ui \
    hingelimits.ui \
    limitedhinge.ui \
    pointtoplane.ui \
    prismatic.ui \
    rackandpinion.ui \
    ragdoll.ui \
    ragdolllimit.ui \
    rotational.ui \
    stiffspring.ui \
    malleable.ui \
    wheel.ui \
    motorselector.ui \
    motorposition.ui \
    motorspringdamper.ui \
    motorvelocity.ui \
    generic.ui \
    chainballsocket.ui \
    chainstiffspring.ui \
    chainpowered.ui \
    shapeselector.ui

INCLUDEPATH += $$PWD/../hk2013_1_0_r1/Source
DEPENDPATH += $$PWD/../hk2013_1_0_r1/Source

LIBHAVOK = $$PWD/../hk2013_1_0_r1/Lib/win32_vs2012_win7_noSimd/release_dll
win32:CONFIG(debug, debug|release):LIBHAVOK = $$PWD/../hk2013_1_0_r1/Lib/win32_vs2012_win7_noSimd/debug_dll

LIBS += -L$$LIBHAVOK -lhkaAnimation
LIBS += -L$$LIBHAVOK -lhkaInternal
LIBS += -L$$LIBHAVOK -lhkaPhysics2012Bridge
LIBS += -L$$LIBHAVOK -lhkBase
LIBS += -L$$LIBHAVOK -lhkcdCollide
LIBS += -L$$LIBHAVOK -lhkcdInternal
LIBS += -L$$LIBHAVOK -lhkCompat
LIBS += -L$$LIBHAVOK -lhkgBridge
LIBS += -L$$LIBHAVOK -lhkgCommon
LIBS += -L$$LIBHAVOK -lhkgDx9s
LIBS += -L$$LIBHAVOK -lhkgDx11
LIBS += -L$$LIBHAVOK -lhkGeometryUtilities
LIBS += -L$$LIBHAVOK -lhkgOglES
LIBS += -L$$LIBHAVOK -lhkgOglES2
LIBS += -L$$LIBHAVOK -lhkgOgls
LIBS += -L$$LIBHAVOK -lhkgSoundCommon
LIBS += -L$$LIBHAVOK -lhkgSoundXAudio2
LIBS += -L$$LIBHAVOK -lhkInternal
LIBS += -L$$LIBHAVOK -lhkpCollide
LIBS += -L$$LIBHAVOK -lhkpConstraint
LIBS += -L$$LIBHAVOK -lhkpConstraintSolver
LIBS += -L$$LIBHAVOK -lhkpDynamics
LIBS += -L$$LIBHAVOK -lhkpInternal
LIBS += -L$$LIBHAVOK -lhkpUtilities
LIBS += -L$$LIBHAVOK -lhkpVehicle
LIBS += -L$$LIBHAVOK -lhkSceneData
LIBS += -L$$LIBHAVOK -lhkSerialize
LIBS += -L$$LIBHAVOK -lhkVisualize

PRE_TARGETDEPS += $$LIBHAVOK/hkaAnimation.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkaInternal.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkaPhysics2012Bridge.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkBase.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkcdCollide.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkcdInternal.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkCompat.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkgBridge.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkgCommon.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkgDx9s.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkgDx11.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkGeometryUtilities.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkgOglES.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkgOglES2.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkgOgls.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkgSoundCommon.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkgSoundXAudio2.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkInternal.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkpCollide.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkpConstraint.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkpConstraintSolver.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkpDynamics.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkpInternal.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkpUtilities.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkpVehicle.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkSceneData.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkSerialize.lib
PRE_TARGETDEPS += $$LIBHAVOK/hkVisualize.lib

RESOURCES += \
    rc.qrc

OTHER_FILES +=
