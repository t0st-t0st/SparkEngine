#pragma once

#include <SparkEngine/Config.hpp>

#if defined(EDITOR_EXPORTS)

#define EDITOR_API SPARK_API_EXPORT

#else

#define EDITOR_API SPARK_API_IMPORT

#endif
