#ifndef TCPCLIENT_H
#define TCPCLIENT_H
#include <QWidget>
#include <QLineEdit>
#include "button.h"
#include <QTabWidget>

class ConnectTab: public QWidget
{
    Q_OBJECT;
public:
    explicit ConnectTab(QWidget *parent = nullptr);
};

class PublishTab: public QWidget
{
    Q_OBJECT;

public:
    explicit PublishTab(QWidget *parent = nullptr);
};

class SubscribeTab: public QWidget
{
    Q_OBJECT;

public:
    explicit SubscribeTab(QWidget *parent = nullptr);
};


class TCPClient: public QWidget
{
    Q_OBJECT

public:
    explicit TCPClient(QWidget *parent = 0);

private slots:
    void connect();
    void disconnect();
    void publish();
    void subscribe();
    void unsubscribe();

private:
    QTabWidget *m_menu;
};

#endif // TCPCLIENT_H
