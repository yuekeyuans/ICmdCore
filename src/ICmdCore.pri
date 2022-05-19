INCLUDEPATH += $$PWD

QT += network sql xml

HEADERS += \
    $$PWD/base/ICodecUtil.h \
    $$PWD/base/IConstantUtil.h \
    $$PWD/base/IConvertUtil.h \
    $$PWD/base/IFileUtil.h \
    $$PWD/base/IHeaderUtil.h \
    $$PWD/base/IJsonUtil.h \
    $$PWD/base/IJsonUtil_tojson.h \
    $$PWD/base/IMetaUtil.h \
    $$PWD/base/IOrmUtil.h \
    $$PWD/base/IPackageUtil.h \
    $$PWD/base/IPreProcessorUtil.h \
    $$PWD/base/ISocketUtil.h \
    $$PWD/base/ITicTacUtil.h \
    $$PWD/base/IToeUtil.h \
    $$PWD/base/ITraitHelper.h \
    $$PWD/base/IXmlUtil.h \ \
    $$PWD/orm/IOrmManage.h \
    $$PWD/orm/ISqlQuery.h \
    $$PWD/orm/clause/IOrmClause.h \
    $$PWD/orm/clause/IOrmCondition.h \
    $$PWD/orm/clause/IOrmQueryClause.h \
    $$PWD/orm/database/IOrmDataSource.h \
    $$PWD/orm/database/IOrmDatabaseInterface.h \
    $$PWD/orm/database/IOrmDatabaseWare.h \
    $$PWD/orm/dialect/IOrmDialectInterface.h \
    $$PWD/orm/dialect/IOrmDialectWare.h \
    $$PWD/orm/dialect/IOrmMySqlDialect.h \
    $$PWD/orm/dialect/IOrmSqliteDialect.h \
    $$PWD/orm/dialect/IPostGreSqlDialect.h \
    $$PWD/orm/model/IOrmEntityModeWare.h \
    $$PWD/orm/model/IOrmTableModelInterface.h \
    $$PWD/orm/model/IOrmViewModelInterface.h \
    $$PWD/orm/pp/IOrmPreProcessor.h \
    $$PWD/orm/pp/IOrmTablePreProcessor.h \
    $$PWD/orm/pp/IOrmViewPreProcessor.h \
    $$PWD/orm/private/IOrmConditionImpl.h \
    $$PWD/orm/private/IOrmDatabaseWareImpl.h \
    $$PWD/orm/tableview/IOrmEntityInfoWare.h \
    $$PWD/orm/tableview/IOrmEntityWare.h \
    $$PWD/orm/tableview/IOrmTableInfo.h \
    $$PWD/orm/tableview/IOrmTableInterface.h \
    $$PWD/orm/tableview/IOrmTableWare.h \
    $$PWD/orm/tableview/IOrmViewInfo.h \
    $$PWD/orm/tableview/IOrmViewInterface.h \
    $$PWD/orm/tableview/IOrmViewWare.h

SOURCES += \
    $$PWD/base/ICodecUtil.cpp \
    $$PWD/base/IConvertUtil.cpp \
    $$PWD/base/IFileUtil.cpp \
    $$PWD/base/IHeaderUtil.cpp \
    $$PWD/base/IJsonUtil.cpp \
    $$PWD/base/IJsonUtil_tojson.cpp \
    $$PWD/base/IJsonUtil_tojson_impl.cpp \
    $$PWD/base/IMetaUtil.cpp \
    $$PWD/base/IOrmUtil.cpp \
    $$PWD/base/IPreProcessorUtil.cpp \
    $$PWD/base/ISocketUtil.cpp \
    $$PWD/base/ITicTacUtil.cpp \
    $$PWD/base/IToeUtil.cpp \
    $$PWD/base/ITraitHelper.cpp \
    $$PWD/base/IXmlUtil.cpp \
    $$PWD/orm/IOrmManage.cpp \
    $$PWD/orm/ISqlQuery.cpp \
    $$PWD/orm/clause/IOrmClause.cpp \
    $$PWD/orm/clause/IOrmCondition.cpp \
    $$PWD/orm/clause/IOrmQueryClause.cpp \
    $$PWD/orm/database/IOrmDataSource.cpp \
    $$PWD/orm/database/IOrmDatabaseInterface.cpp \
    $$PWD/orm/database/IOrmDatabaseWare.cpp \
    $$PWD/orm/dialect/IOrmDialectInterface.cpp \
    $$PWD/orm/dialect/IOrmDialectWare.cpp \
    $$PWD/orm/dialect/IOrmMySqlDialect.cpp \
    $$PWD/orm/dialect/IOrmSqliteDialect.cpp \
    $$PWD/orm/dialect/IPostGreSqlDialect.cpp \
    $$PWD/orm/model/IOrmEntityModeWare.cpp \
    $$PWD/orm/model/IOrmTableModelInterface.cpp \
    $$PWD/orm/model/IOrmViewModelInterface.cpp \
    $$PWD/orm/private/IOrmConditionImpl.cpp \
    $$PWD/orm/private/IOrmDatabaseWareImpl.cpp \
    $$PWD/orm/tableview/IOrmEntityInfoWare.cpp \
    $$PWD/orm/tableview/IOrmEntityWare.cpp \
    $$PWD/orm/tableview/IOrmTableInfo.cpp \
    $$PWD/orm/tableview/IOrmTableInterface.cpp \
    $$PWD/orm/tableview/IOrmTableWare.cpp \
    $$PWD/orm/tableview/IOrmViewInfo.cpp \
    $$PWD/orm/tableview/IOrmViewInterface.cpp \
    $$PWD/orm/tableview/IOrmViewWare.cpp
