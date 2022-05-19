﻿#pragma once

#include "base/IHeaderUtil.h"
#include "biscuits/IHttpHeader.h"
#include "biscuits/IHttpMethod.h"
#include "biscuits/IHttpMime.h"
#include "biscuits/IHttpStatus.h"
#include "biscuits/IHttpVersion.h"
#include "common/net/IMultiPart.h"
#include "common/cookie/ICookieJar.h"
#include "common/cookie/ICookiePart.h"
#include "common/session/ISessionJar.h"
#include "common/header/IHeaderJar.h"

$PackageWebCoreBegin

class IResponse;
class IRequest;

class IReqRespRaw
{
public:
    IReqRespRaw();

public:
    bool valid() const;
    void setInvalid(IHttpStatus status, const QString& message);
    void setInvalidIf(bool condition, IHttpStatus status, const QString& message);

    QJsonValue& getRequestJson(bool* ok=nullptr);
    QDomNode&   getRequestXml(bool* ok=nullptr);

    // TODO: 将来所有的非 private 字段不要有 m_， 而所有的 private 字段 有 m_
public:
    QTcpSocket* m_socket {nullptr};
    IResponse*  m_response {nullptr};
    IRequest*   m_request  {nullptr};

    int peerPort{};
    QHostAddress peerAddress;
    QString peerName;

    bool m_valid{true};
    QMap<QString, QVariant> m_attribute;                // 用户或系统可以自己放置内容的地方。

    // request
    QString m_url;
    IHttpVersion m_httpVersion {IHttpVersion::UNKNOWN};
    IHttpMethod m_method {IHttpMethod::UNKNOWN};
    IHttpMime m_requestMime {IHttpMime::UNKNOWN};

    QByteArray m_requestBody;
    QList<QPair<QString, QString>> m_requestHeaders;

    QMap<QString, QByteArray> m_requestUrlParameters;
    QMap<QString, QByteArray> m_requestParamParameters;     // 特指 url 参数后面的内容
    QMap<QString, QByteArray> m_requestBodyParameters;  // 特指 url encoded
    QVector<IMultiPart> m_requestMultiParts;
    QList<QPair<QString, QString>> m_requestCookieParameters;

    IHeaderJar m_headerJar;
    ICookieJar m_cookieJar;                                       // TODO: 这两个是否需要指针?
    ISessionJar m_sessionJar;

private:
    QJsonValue m_requestJson;                   // json 和 dom 不一定使用，也可能是延后加载
    QDomNode m_requestXml;

    bool isJsonInited   {false};
    bool isXmlInited    {false};

public:
    // response
    IHttpStatus m_responseStatus {IHttpStatus::UNKNOWN};
    QByteArray m_responseContent;
    IHttpMime m_responseMime{IHttpMime::UNKNOWN};
    QList<QPair<QString, QString>> m_responseHeaders;
    QList<ICookiePart> m_responseCookies;
};

$PackageWebCoreEnd
