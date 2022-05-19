﻿#include "IByteArrayResponse.h"

$PackageWebCoreBegin

const QString IByteArrayResponse::m_matcherPrefix = "$bytes:";

IByteArrayResponse::IByteArrayResponse()
{
    raw->mime = IHttpMime::APPLICATION_OCTET_STREAM;
}

IByteArrayResponse::IByteArrayResponse(QByteArray &array)
{
    raw->content = array;
    raw->mime = IHttpMime::APPLICATION_OCTET_STREAM;
}

IByteArrayResponse::IByteArrayResponse(QByteArray &&array)
{
    std::swap(raw->content, array);
    raw->mime = IHttpMime::APPLICATION_OCTET_STREAM;
}

IByteArrayResponse::IByteArrayResponse(IRedirectResponse &&redirectResponse)
{
    redirectTo(std::forward<IRedirectResponse&&>(redirectResponse));
}

void IByteArrayResponse::setInstanceArg(QString &&value)
{
    raw->content = value.midRef(m_matcherPrefix.length()).toUtf8();
}

void IByteArrayResponse::setInstanceArg(void *arg, const QString &)
{
    auto value = *static_cast<QByteArray*>(arg);
    std::swap(value, raw->content);
}

bool IByteArrayResponse::canConvertFromString()
{
    return true;
}

bool IByteArrayResponse::matchConvertString(const QString &value)
{
    return value.startsWith(m_matcherPrefix);
}

QSharedPointer<IResponseWare> IByteArrayResponse::createByteArrayInstance()
{
    return QSharedPointer<IResponseWare>(new IByteArrayResponse);
}

QSharedPointer<IResponseWare> IByteArrayResponse::createInstance()
{
    return QSharedPointer<IResponseWare>(new IByteArrayResponse);
}

IByteArrayResponse operator"" _bytes(const char* str, size_t size){
    return QByteArray::fromRawData(str, static_cast<int>(size));
}

$PackageWebCoreEnd
