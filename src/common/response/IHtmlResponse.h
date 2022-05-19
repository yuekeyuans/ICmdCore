﻿#pragma once
#include <QtCore>
#include "IResponseInterface.h"
#include "IResponsePreProcessor.h"

$PackageWebCoreBegin

class IHtmlResponse : public IResponseInterface<IHtmlResponse>
{
    Q_GADGET
    $AsResponse(IHtmlResponse)
public:
    using IResponseInterface::operator[];

public:
    IHtmlResponse();
    IHtmlResponse(const char* data);
    IHtmlResponse(const QString& data);
    IHtmlResponse(IRedirectResponse&& redirectResponse);

    virtual void setInstanceArg(QString &&data) final;
    virtual bool canConvertFromString() final;
    virtual bool matchConvertString(const QString &str) final;

    virtual QSharedPointer<IResponseWare> createInstance() final;

private:
    static const QString m_matcherPrefix;
};


IHtmlResponse operator"" _html(const char* str, size_t size);

$PackageWebCoreEnd


