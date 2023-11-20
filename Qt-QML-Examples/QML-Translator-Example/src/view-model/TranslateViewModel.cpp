#include "TranslateViewModel.h"

#include <QLocale>
#include <QCoreApplication>
#include <QDir>
#include <QDebug>

#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>

TranslateViewModel::TranslateViewModel(QObject* parent) :
    QObject(parent)
{
    m_translator = new QTranslator(this);
    qApp->installTranslator(m_translator);
}

void TranslateViewModel::setEn()
{
    m_currLang = "en_EN";
    QLocale locale = QLocale(m_currLang);
    qDebug() <<  locale;
    QLocale::setDefault(locale);
    qDebug() << QLocale::languageToString(locale.language());
    switchTranslator();

    qDebug() << QCoreApplication::tr("Hello");
}

void TranslateViewModel::setRu()
{
    m_currLang = "ru_RU";
    QLocale locale = QLocale(m_currLang);
    qDebug() <<  locale;
    QLocale::setDefault(locale);
    qDebug() << QLocale::languageToString(locale.language());
    switchTranslator();

    qDebug() << QCoreApplication::tr("Hello");
}

void TranslateViewModel::switchTranslator()
{
    qApp->removeTranslator(m_translator);

    if (m_translator->load(QString(":/test_%1.qm").arg(m_currLang))) {
        QCoreApplication::installTranslator(m_translator);

        QQmlEngine* engine = QQmlEngine::contextForObject(this)->engine();
        engine->retranslate();
    } else {
        qDebug() << "Failed to load " << QString(":/test_%1.qm").arg(m_currLang);
    }
}
