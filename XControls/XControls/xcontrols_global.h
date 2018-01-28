#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(XCONTROLS_LIB)
#  define XCONTROLS_EXPORT Q_DECL_EXPORT
# else
#  define XCONTROLS_EXPORT Q_DECL_IMPORT
# endif
#else
# define XCONTROLS_EXPORT
#endif
