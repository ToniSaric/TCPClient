#include <QtGui>

#include "button.h"

Button::Button(const QString &text, QWidget *parent)
    : QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);
}

QSize Button::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}

Button *Button::createButton(const QString &text, const char *member)
{
    (void) member;
    Button *button = new Button(text);
    //connect(button, SIGNAL(clicked()), this, member);
    return button;
}
