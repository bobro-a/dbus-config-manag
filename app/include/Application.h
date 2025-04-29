#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once
#include <QtDBus>
#include <iostream>
#include "Constants.h"

class Application : public QObject {
    Q_OBJECT

public:
    explicit Application(QObject *parent = nullptr);

public slots:
    void newData(const QVariantMap &newData);

    void printData();

private:
    void loadStartData();

    QVariantMap data_;
    // QString filename_ = "confManagerApplication1";
    // QString pathDir_ = "com.system.configurationManager";
    QTimer timer_;
    int currentTimeout;
};
#endif //APPLICATION_H
