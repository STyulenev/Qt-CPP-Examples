#pragma once

#include <QTranslator>

class TranslateViewModel : public QObject
{
    Q_OBJECT

public:
    explicit TranslateViewModel(QObject* parent = nullptr);

    Q_INVOKABLE void setEn();
    Q_INVOKABLE void setRu();

private:
    void switchTranslator();

private:
    QTranslator* m_translator;
    QString m_currLang;

};
