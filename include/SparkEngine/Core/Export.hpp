#pragma once

#include <SparkEngine/Config.hpp>

#if defined(CORE_EXPORTS)

#define CORE_API SPARK_API_EXPORT

#else

#define CORE_API SPARK_API_IMPORT

#endif
