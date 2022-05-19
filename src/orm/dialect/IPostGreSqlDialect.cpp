#include "IPostGreSqlDialect.h"

QString IWebCore::IPostGreSqlDialect::dialectType()
{
    return "PostGreSql";
}

QString IWebCore::IPostGreSqlDialect::getSqlType(const int typeId)
{
    static const QMap<int, QString> map = {
        {QMetaType::Char, "INTEGER"},
        {QMetaType::UChar, "INTEGER"},
        {QMetaType::Short, "INTEGER"},
        {QMetaType::UShort, "INTEGER"},
        {QMetaType::Int, "INTEGER"},
        {QMetaType::UInt, "INTEGER"},
        {QMetaType::Long, "INTEGER"},
        {QMetaType::ULong, "INTEGER"},
        {QMetaType::LongLong, "INTEGER"},
        {QMetaType::ULongLong, "INTEGER"},
        {QMetaType::Double, "DOUBLE"},
        {QMetaType::Float, "FLOAT"},

        {QVariant::String, "VARCHAR(100)"}, // TODO: 这个需要修改

        {QVariant::Bool, "BOOL"},

        {QVariant::Date, "DATE"},
        {QVariant::Time, "TIME(3)"},
        {QVariant::DateTime, "DATETIME(3)"}
    };
    if(!map.contains(typeId)){
        QString info = QString("Type is not supported. Type:").append(QVariant::typeToName(typeId));
        qFatal(info.toUtf8());
    }
    return map[typeId];
}

QString IWebCore::IPostGreSqlDialect::getLimitString(int count)
{
    return QString("LIMIT ").append(QString::number(count));
}

QString IWebCore::IPostGreSqlDialect::getLimitString(quint64 start, quint64 count)
{
    return QString("LIMIT ").append(QString::number(start)).append(" ,").append(QString::number(count));
}
