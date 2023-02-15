#pragma once

#include <QtCore/qglobal.h>

#if defined(SHARED_LIBRARY)
#  define MYDLL_EXPORT Q_DECL_EXPORT
#else
#  define MYDLL_EXPORT Q_DECL_IMPORT
#endif

