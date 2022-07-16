#ifndef CONVERTER_GLOBAL_H
#define CONVERTER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CONVERTER_LIBRARY)
#  define CONVERTER_EXPORT Q_DECL_EXPORT
#else
#  define CONVERTER_EXPORT Q_DECL_IMPORT
#endif

#endif // CONVERTER_GLOBAL_H
