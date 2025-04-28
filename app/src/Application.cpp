#include "Application.h"

Application::Application(QObject *parent): QObject(parent) {
    loadStartData();
    QObject::connect(&timer_, &QTimer::timeout, this, &Application::printData);
    currentTimeout=data_["Timeout"].toInt();
    timer_.start(currentTimeout);
}

void Application::newData() {
    QDBusInterface interface("com.system.configurationManager",
                             "com/system/configurationManager/Application/confManagerApplication1",
                             "com.system.configurationManager.Application.Configuration");
    QDBusReply<QVariantMap> qReply(interface.call("GetConfiguration"));
    if (qReply.isValid())
        data_ = qReply.value();
    if (data_["Timeout"].toInt()!=currentTimeout) {
        timer_.stop();
        currentTimeout=data_["Timeout"].toInt();
        timer_.start(currentTimeout);
    }
}


void Application::printData() {
    qDebug() << data_["TimeoutPhrase"].toString();
}

void Application::loadStartData() {
    QDir dir(QDir::homePath()+"/"+pathDir_);
    if (!dir.exists()) dir.mkpath(pathDir_);
    QFile file(pathDir_ + "/" + filename_ + ".json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (jsonDoc.isObject()) {
            QVariantMap config=jsonDoc.object().toVariantMap();
            data_=config;
        }
    }
    file.close();
}
