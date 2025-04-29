#include "Application.h"

Application::Application(QObject *parent): QObject(parent) {
    loadStartData();
    QObject::connect(&timer_, &QTimer::timeout, this, &Application::printData);
    currentTimeout = data_["Timeout"].toInt();
    timer_.start(currentTimeout);
}

void Application::newData(const QVariantMap& newData) {
    data_=newData;
    timer_.stop();
    currentTimeout = data_["Timeout"].toInt();
    timer_.start(currentTimeout);
}


void Application::printData() {
    std::cout << data_["TimeoutPhrase"].toString().toStdString() << "\n";
}

void Application::loadStartData() {
    QDir dir(QDir::homePath() + "/" + pathDir_);
    if (!dir.exists()) dir.mkpath(pathDir_);
    QFile file(QDir::homePath() + "/" + pathDir_ + "/" + filename_ + ".json");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray data = file.readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
        if (jsonDoc.isObject()) {
            QVariantMap config = jsonDoc.object().toVariantMap();
            data_ = config;
        }
    }
    file.close();
}
