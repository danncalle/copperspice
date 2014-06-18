/***********************************************************************
*
* Copyright (c) 2012-2014 Barbara Geller
* Copyright (c) 2012-2014 Ansel Sermersheim
* Copyright (c) 2012-2014 Digia Plc and/or its subsidiary(-ies).
* Copyright (c) 2008-2012 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
*
* This file is part of CopperSpice.
*
* CopperSpice is free software: you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* version 2.1 as published by the Free Software Foundation.
*
* CopperSpice is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public
* License along with CopperSpice.  If not, see
* <http://www.gnu.org/licenses/>.
*
***********************************************************************/

#ifndef QFRAME_P_H
#define QFRAME_P_H

#include "qwidget_p.h"
#include "qframe.h"

QT_BEGIN_NAMESPACE

class QFramePrivate : public QWidgetPrivate
{
   Q_DECLARE_PUBLIC(QFrame)

 public:
   QFramePrivate();

   void        updateFrameWidth();
   void        updateStyledFrameWidths();

   QRect       frect;
   int         frameStyle;
   short       lineWidth;
   short       midLineWidth;
   short       frameWidth;
   short       leftFrameWidth, rightFrameWidth;
   short       topFrameWidth, bottomFrameWidth;

   inline void init();

};

QT_END_NAMESPACE

#endif // QFRAME_P_H
