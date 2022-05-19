#pragma once

#include "base/IHeaderUtil.h"
#include "orm/pp/IOrmPreProcessor.h"
#include "orm/dialect/IOrmDialectInterface.h"

$PackageWebCoreBegin

class IPostGreSqlDialect : public IOrmDialectInterface<IPostGreSqlDialect>
{
    $AsDialect(IPostGreSqlDialect)
public:
    IPostGreSqlDialect() =default;

    virtual QString dialectType() final;
    virtual QString getSqlType(const int typeId) final;
    virtual QString getLimitString(int count) final;
    virtual QString getLimitString(quint64 start, quint64 count) final;

};

$PackageWebCoreEnd
