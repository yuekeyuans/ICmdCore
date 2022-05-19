﻿#include "IHttpMethod.h"

$PackageWebCoreBegin

QString IHttpMethodHelper::toString(IHttpMethod method)
{
    if(method >= IHttpMethod::UNKNOWN){
        method = IHttpMethod::UNKNOWN;
    }
    return methodNames()[static_cast<int>(method)];
}

IHttpMethod IHttpMethodHelper::toMethod(const QString &name)
{
    auto index = methodNames().indexOf(name.toUpper());
    if(index == -1){
        return IHttpMethod::UNKNOWN;
    }
    return static_cast<IHttpMethod>(index);
}

const QStringList &IHttpMethodHelper::methodNames()
{
    static const QStringList m_methodNames = {"GET", "POST", "PUT", "DELETE", "PATCH", "HEAD", "OPTIONS", "UNKNOWN"};
    return m_methodNames;
}

$PackageWebCoreEnd
