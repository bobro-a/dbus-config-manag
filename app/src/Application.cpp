#include "Application.h"
#include <iostream>

Application::Application(QObject *parent): QObject(parent) {
    loadStartData();
    QObject::connect(&timer_, &QTimer::timeout, this, &Application::printData);
    currentTimeout = data_["Timeout"].toInt();
    timer_.start(currentTimeout);
}

void Application::newData(const QVariantMap &newData) {
    data_ = newData;
    timer_.stop();
    currentTimeout = data_["Timeout"].toInt();
    timer_.start(currentTimeout);
}


void Application::printData() {
    std::cout << data_["TimeoutPhrase"].toString().toStdString() << "\n";
}

void Application::loadStartData() {
    QDir dir(QDir::homePath() + "/" + SERVER_NAME);
    if (!dir.exists()) dir.mkpath(SERVER_NAME);
    QFile file(QDir::homePath() + "/" + SERVER_NAME + "/" + APP_NAME + ".json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;
    QByteArray data = file.readAll();
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    if (!jsonDoc.isObject())
        return;
    data_ = jsonDoc.object().toVariantMap();

    file.close();
}
