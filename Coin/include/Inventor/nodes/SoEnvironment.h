#ifndef COIN_SOENVIRONMENT_H
#define COIN_SOENVIRONMENT_H

/**************************************************************************\
 *
 *  This file is part of the Coin 3D visualization library.
 *  Copyright (C) by Kongsberg Oil & Gas Technologies.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  ("GPL") version 2 as published by the Free Software Foundation.
 *  See the file LICENSE.GPL at the root directory of this source
 *  distribution for additional information about the GNU GPL.
 *
 *  For using Coin with software that can not be combined with the GNU
 *  GPL, and for taking advantage of the additional benefits of our
 *  support services, please contact Kongsberg Oil & Gas Technologies
 *  about acquiring a Coin Professional Edition License.
 *
 *  See http://www.coin3d.org/ for more information.
 *
 *  Kongsberg Oil & Gas Technologies, Bygdoy Alle 5, 0257 Oslo, NORWAY.
 *  http://www.sim.no/  sales@sim.no  coin-support@coin3d.org
 *
\**************************************************************************/

#include <Inventor/nodes/SoSubNode.h>
#include <Inventor/fields/SoSFFloat.h>
#include <Inventor/fields/SoSFColor.h>
#include <Inventor/fields/SoSFVec3f.h>
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/elements/SoEnvironmentElement.h>

class COIN_DLL_API SoEnvironment : public SoNode {
  typedef SoNode inherited;

  SO_NODE_HEADER(SoEnvironment);

public:
  static void initClass(void);
  SoEnvironment(void);

  enum FogType {
    NONE = SoEnvironmentElement::NONE,
    HAZE = SoEnvironmentElement::HAZE,
    FOG = SoEnvironmentElement::FOG,
    SMOKE = SoEnvironmentElement::SMOKE
  };

  virtual void GLRender(SoGLRenderAction * action);
  virtual void callback(SoCallbackAction * action);

  SoSFFloat ambientIntensity;
  SoSFColor ambientColor;
  SoSFVec3f attenuation;
  SoSFEnum fogType;
  SoSFColor fogColor;
  SoSFFloat fogVisibility;

protected:
  virtual ~SoEnvironment();
};

#endif // !COIN_SOENVIRONMENT_H
