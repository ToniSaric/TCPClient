#include "tcpclient.h"
#include <QtGui>
#include <QWidget>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QTableWidget>
#include <QHeaderView>

ConnectTab::ConnectTab(QWidget *parent) : QWidget(parent)
{
    QLabel *hostnameLable = new QLabel(tr("Hostname:"));
    hostnameLable->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    QLineEdit *hostnameEdit = new QLineEdit();
    hostnameEdit->setClearButtonEnabled(true);
    hostnameEdit->setFrame(true);
    hostnameEdit->setCursorPosition(0);
    hostnameEdit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

    QLabel *portLable = new QLabel(tr("Port:"));
    QLineEdit *portEdit = new QLineEdit();
    portEdit->setClearButtonEnabled(true);
    portEdit->setFrame(true);
    portEdit->setCursorPosition(0);

    QPushButton *connectButton = new QPushButton(tr("Connect"));
    QPushButton *disconnectButton = new QPushButton(tr("Disconnect"));

    QGroupBox *paramBox = new QGroupBox;
    QGroupBox *buttonBox = new QGroupBox;

    QHBoxLayout *paramLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    paramLayout->addWidget(hostnameLable, Qt::AlignmentFlag::AlignLeft);
    paramLayout->addWidget(hostnameEdit, Qt::AlignmentFlag::AlignLeft);
    paramLayout->addWidget(portLable, Qt::AlignmentFlag::AlignLeft);
    paramLayout->addWidget(portEdit, Qt::AlignmentFlag::AlignLeft);
    paramBox->setLayout(paramLayout);

    buttonLayout->addWidget(connectButton);
    buttonLayout->addWidget(disconnectButton);
    buttonBox->setLayout(buttonLayout);

    mainLayout->addWidget(paramBox);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);
}

PublishTab::PublishTab(QWidget *parent) : QWidget(parent)
{
    QLabel *topicLabel = new QLabel(tr("Topic:"));
    QLineEdit *topicEdit = new QLineEdit();
    topicEdit->setClearButtonEnabled(true);
    topicEdit->setBaseSize(190,25);
    topicEdit->setFrame(true);
    topicEdit->setCursorPosition(0);

    QLabel *messageLable = new QLabel(tr("Message:"));
    QLineEdit *messageEdit = new QLineEdit();
    messageEdit->setClearButtonEnabled(true);
    messageEdit->setBaseSize(190,25);
    messageEdit->setFrame(true);
    messageEdit->setCursorPosition(0);

    QPushButton *publishButton = new QPushButton(tr("Publish"));

    QGroupBox *paramBox = new QGroupBox;
    QGroupBox *buttonBox = new QGroupBox;

    QHBoxLayout *paramLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    paramLayout->addWidget(topicLabel, Qt::AlignmentFlag::AlignLeft);
    paramLayout->addWidget(topicEdit, Qt::AlignmentFlag::AlignLeft);
    paramLayout->addWidget(messageLable, Qt::AlignmentFlag::AlignLeft);
    paramLayout->addWidget(messageEdit, Qt::AlignmentFlag::AlignLeft);
    paramBox->setLayout(paramLayout);

    buttonLayout->addWidget(publishButton);
    buttonBox->setLayout(buttonLayout);

    mainLayout->addWidget(paramBox);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);
}

SubscribeTab::SubscribeTab(QWidget *parent): QWidget(parent)
{
    QLabel *topicLabel = new QLabel(tr("Topic:"));
    QLineEdit *topicEdit = new QLineEdit();
    topicEdit->setClearButtonEnabled(true);
    topicEdit->setBaseSize(190,25);
    topicEdit->setFrame(true);
    topicEdit->setCursorPosition(0);

    QPushButton *subscribeButton = new QPushButton(tr("Subscribe"));
    QPushButton *unsubscribeButton = new QPushButton(tr("Unsubscribe"));

    QTableWidget *subscribeTable = new QTableWidget(4,2);
    subscribeTable->setShowGrid(true);
    subscribeTable->horizontalHeader()->hide();
    subscribeTable->verticalHeader()->hide();

    QGroupBox *paramBox = new QGroupBox;
    QGroupBox *buttonBox = new QGroupBox;
    QGroupBox *tableBox = new QGroupBox(tr("Subscribed topics:"));

    QHBoxLayout *paramLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QVBoxLayout *tableLayout = new QVBoxLayout;

    paramLayout->addWidget(topicLabel, Qt::AlignmentFlag::AlignLeft);
    paramLayout->addWidget(topicEdit, Qt::AlignmentFlag::AlignLeft);
    paramBox->setLayout(paramLayout);

    buttonLayout->addWidget(subscribeButton);
    buttonLayout->addWidget(unsubscribeButton);
    buttonBox->setLayout(buttonLayout);

    tableLayout->addWidget(subscribeTable);
    tableBox->setLayout(tableLayout);

    mainLayout->addWidget(paramBox);
    mainLayout->addWidget(tableBox);
    mainLayout->addWidget(buttonBox);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);
    //QSize availableSize = qApp->desktop()->availableGeometry().size();
    this->setFixedSize(500,500);
}

TCPClient::TCPClient(QWidget *parent)
{
    (void) parent;
    m_menu = new QTabWidget;
    m_menu->addTab(new ConnectTab(parent), tr("Connect/Disconnet"));
    m_menu->addTab(new PublishTab(parent), tr("Publish"));
    m_menu->addTab(new SubscribeTab(parent), tr("Subscribe/unsubscribe"));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(m_menu);
    setLayout(mainLayout);
    setWindowTitle(tr("TCPClient"));
}

void TCPClient::connect()
{
}

void TCPClient::disconnect()
{
}

void TCPClient::publish()
{

}

void TCPClient::subscribe()
{

}

void TCPClient::unsubscribe()
{

}

