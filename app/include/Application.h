#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once
#include <QtDBus>
#include <iostream>

class Application : public QObject {
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

public slots:
    void newData();
    void printData();

private:
    void loadStartData();

    QVariantMap data_;
    QString filename_ = "confManagerApplication1";
    QString pathDir_ = "com.system.configurationManager/Application";
    QTimer timer_;
    int currentTimeout;
};
#endif //APPLICATION_H
