#pragma once

#include <QtCore/qglobal.h>

#ifdef Q_OS_WIN
#define MYLIB1SHARED_EXPORT __declspec(dllexport)
#else
#define MYLIB1SHARED_EXPORT Q_DECL_IMPORT
#endif
