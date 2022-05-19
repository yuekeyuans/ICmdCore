﻿#pragma once

#include "base/IHeaderUtil.h"

$PackageWebCoreBegin

class ITaskWare
{
    $AsWare
public:
    ITaskWare() = default;

public:
    virtual QString taskFinishTip();
    virtual void task() = 0;

public:
    void printTips();
};

$PackageWebCoreEnd
