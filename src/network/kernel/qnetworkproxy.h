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

#ifndef QNETWORKPROXY_H
#define QNETWORKPROXY_H

#include <QtNetwork/qhostaddress.h>
#include <QtCore/qshareddata.h>

#ifndef QT_NO_NETWORKPROXY

QT_BEGIN_NAMESPACE

class QUrl;
class QNetworkConfiguration;
class QNetworkProxyQueryPrivate;
class QNetworkProxyPrivate;

class Q_NETWORK_EXPORT QNetworkProxyQuery
{

 public:
   enum QueryType {
      TcpSocket,
      UdpSocket,
      TcpServer = 100,
      UrlRequest
   };

   QNetworkProxyQuery();
   QNetworkProxyQuery(const QUrl &requestUrl, QueryType queryType = UrlRequest);
   QNetworkProxyQuery(const QString &hostname, int port, const QString &protocolTag = QString(),
                      QueryType queryType = TcpSocket);
   QNetworkProxyQuery(quint16 bindPort, const QString &protocolTag = QString(),
                      QueryType queryType = TcpServer);
   QNetworkProxyQuery(const QNetworkProxyQuery &other);

#ifndef QT_NO_BEARERMANAGEMENT
   QNetworkProxyQuery(const QNetworkConfiguration &networkConfiguration,
                      const QUrl &requestUrl, QueryType queryType = UrlRequest);
   QNetworkProxyQuery(const QNetworkConfiguration &networkConfiguration,
                      const QString &hostname, int port, const QString &protocolTag = QString(),
                      QueryType queryType = TcpSocket);
   QNetworkProxyQuery(const QNetworkConfiguration &networkConfiguration,
                      quint16 bindPort, const QString &protocolTag = QString(),
                      QueryType queryType = TcpServer);
#endif
   ~QNetworkProxyQuery();
   QNetworkProxyQuery &operator=(const QNetworkProxyQuery &other);
   bool operator==(const QNetworkProxyQuery &other) const;
   inline bool operator!=(const QNetworkProxyQuery &other) const {
      return !(*this == other);
   }

   QueryType queryType() const;
   void setQueryType(QueryType type);

   int peerPort() const;
   void setPeerPort(int port);

   QString peerHostName() const;
   void setPeerHostName(const QString &hostname);

   int localPort() const;
   void setLocalPort(int port);

   QString protocolTag() const;
   void setProtocolTag(const QString &protocolTag);

   QUrl url() const;
   void setUrl(const QUrl &url);

#ifndef QT_NO_BEARERMANAGEMENT
   QNetworkConfiguration networkConfiguration() const;
   void setNetworkConfiguration(const QNetworkConfiguration &networkConfiguration);
#endif

 private:
   QSharedDataPointer<QNetworkProxyQueryPrivate> d;
};
Q_DECLARE_TYPEINFO(QNetworkProxyQuery, Q_MOVABLE_TYPE);


class Q_NETWORK_EXPORT QNetworkProxy
{

 public:
   enum ProxyType {
      DefaultProxy,
      Socks5Proxy,
      NoProxy,
      HttpProxy,
      HttpCachingProxy,
      FtpCachingProxy
   };

   enum Capability {
      TunnelingCapability = 0x0001,
      ListeningCapability = 0x0002,
      UdpTunnelingCapability = 0x0004,
      CachingCapability = 0x0008,
      HostNameLookupCapability = 0x0010
   };
   using Capabilities = QFlags<Capability>;

   QNetworkProxy();
   QNetworkProxy(ProxyType type, const QString &hostName = QString(), quint16 port = 0,
                 const QString &user = QString(), const QString &password = QString());
   QNetworkProxy(const QNetworkProxy &other);
   QNetworkProxy &operator=(const QNetworkProxy &other);
   ~QNetworkProxy();
   bool operator==(const QNetworkProxy &other) const;
   inline bool operator!=(const QNetworkProxy &other) const {
      return !(*this == other);
   }

   void setType(QNetworkProxy::ProxyType type);
   QNetworkProxy::ProxyType type() const;

   void setCapabilities(Capabilities capab);
   Capabilities capabilities() const;
   bool isCachingProxy() const;
   bool isTransparentProxy() const;

   void setUser(const QString &userName);
   QString user() const;

   void setPassword(const QString &password);
   QString password() const;

   void setHostName(const QString &hostName);
   QString hostName() const;

   void setPort(quint16 port);
   quint16 port() const;

   static void setApplicationProxy(const QNetworkProxy &proxy);
   static QNetworkProxy applicationProxy();

 private:
   QSharedDataPointer<QNetworkProxyPrivate> d;
};
Q_DECLARE_OPERATORS_FOR_FLAGS(QNetworkProxy::Capabilities)

class Q_NETWORK_EXPORT QNetworkProxyFactory
{
 public:
   QNetworkProxyFactory();
   virtual ~QNetworkProxyFactory();

   virtual QList<QNetworkProxy> queryProxy(const QNetworkProxyQuery &query = QNetworkProxyQuery()) = 0;

   static void setUseSystemConfiguration(bool enable);
   static void setApplicationProxyFactory(QNetworkProxyFactory *factory);
   static QList<QNetworkProxy> proxyForQuery(const QNetworkProxyQuery &query);
   static QList<QNetworkProxy> systemProxyForQuery(const QNetworkProxyQuery &query = QNetworkProxyQuery());
};

QT_END_NAMESPACE

#endif // QT_NO_NETWORKPROXY

#endif // QHOSTINFO_H
