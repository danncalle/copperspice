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

#ifndef QHTTPNETWORKHEADER_P_H
#define QHTTPNETWORKHEADER_P_H

#ifndef QT_NO_HTTP

#include <qshareddata.h>
#include <qurl.h>

QT_BEGIN_NAMESPACE

class QHttpNetworkHeader
{
 public:
   virtual ~QHttpNetworkHeader() {};
   virtual QUrl url() const = 0;
   virtual void setUrl(const QUrl &url) = 0;

   virtual int majorVersion() const = 0;
   virtual int minorVersion() const = 0;

   virtual qint64 contentLength() const = 0;
   virtual void setContentLength(qint64 length) = 0;

   virtual QList<QPair<QByteArray, QByteArray> > header() const = 0;
   virtual QByteArray headerField(const QByteArray &name, const QByteArray &defaultValue = QByteArray()) const = 0;
   virtual void setHeaderField(const QByteArray &name, const QByteArray &data) = 0;
};

class QHttpNetworkHeaderPrivate : public QSharedData
{
 public:
   QUrl url;
   QList<QPair<QByteArray, QByteArray> > fields;

   QHttpNetworkHeaderPrivate(const QUrl &newUrl = QUrl());
   QHttpNetworkHeaderPrivate(const QHttpNetworkHeaderPrivate &other);
   qint64 contentLength() const;
   void setContentLength(qint64 length);

   QByteArray headerField(const QByteArray &name, const QByteArray &defaultValue = QByteArray()) const;
   QList<QByteArray> headerFieldValues(const QByteArray &name) const;
   void setHeaderField(const QByteArray &name, const QByteArray &data);
   bool operator==(const QHttpNetworkHeaderPrivate &other) const;

};


QT_END_NAMESPACE


#endif // QT_NO_HTTP


#endif // QHTTPNETWORKHEADER_H






