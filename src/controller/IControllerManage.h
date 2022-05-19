﻿#pragma once

#include "base/IHeaderUtil.h"
#include "base/IPreProcessorUtil.h"
#include "biscuits/IHttpMethod.h"
#include "biscuits/IHttpStatus.h"

#include "common/node/IUrlFunctionNode.h"
#include "common/node/IStatusFunctionNode.h"

#include "common/middleware/IMiddleWare.h"
#include "common/middleware/IInterceptorWare.h"
#include "common/middleware/IProcessorWare.h"

#include "IControllerRouteNode.h"

$PackageWebCoreBegin
class IRequest;
class IControllerManage
{
    Q_DISABLE_COPY(IControllerManage)
    $UseInstance(IControllerManage)
private:
    IControllerManage();
    ~IControllerManage() = default;

public:
    using ValidatorFun = bool (*)(const QString&);

    static void registerStatusFunctions(const QVector<IStatusFunctionNode>& statusNodes);
    static void registerUrlFunctions(const QVector<IUrlFunctionNode>& functionNodes);
    static void registerPathValidator(const QString& name, const QString& regexp);
    static void registerPathValidator(const QString& name, ValidatorFun fun);

    // TODO: 这里需要考虑添加到 global 和 local 的两种情形，之后添加上来，作为 AOP 的一部分。
    static void registerPreProcessor(IProcessorWare* middleWare);
    static void registerPostProcessor(IProcessorWare* middleWare);
    static void registerPreInterceptor(IInterceptorWare* middleWare);
    static void registerPostInterceptor(IInterceptorWare* middleWare);

    static void travalPrintUrlTree();
    static QString queryPathRegValidator(const QString& path);
    static ValidatorFun queryPathFunValidator(const QString& path);

    static IUrlFunctionNode* getUrlFunction(IRequest& request);
    static IStatusFunctionNode* getStatusFunction(IHttpStatus status);

    static bool preIntercept(IRequest& request, IResponse& response);
    static bool postIntercept(IRequest& request, IResponse& response);
    static bool preProcess(IRequest& request, IResponse& response);
    static bool postProcess(IRequest& request, IResponse& response);

private:
    static QVector<IUrlFunctionNode*> queryFunctionNodes(IControllerRouteNode* parentNode, const QStringList& fragments, IHttpMethod method);
    static QMap<QString, QByteArray> getPathVariable(void* node, const QStringList& fragments);

    // 这里实现 url 时 需要防止  /<name>/<name>/  这种重复类型的 url
    static bool checkUrlDuplicateName(const IUrlFunctionNode* node);
    void preRegisterPathValidator();

private:
    std::shared_ptr<IControllerRouteNode> m_urlMapppings;
    QMap<IHttpStatus, IStatusFunctionNode> m_statusMappings;
    QMap<QString, QString> m_pathRegValidators;
    QMap<QString, ValidatorFun> m_pathFunValidators;

    QVector<IProcessorWare*> m_preProcessors;
    QVector<IProcessorWare*> m_postProcessors;

    QVector<IInterceptorWare*> m_preInterceptors;
    QVector<IInterceptorWare*> m_postInterceptors;
};

$PackageWebCoreEnd
