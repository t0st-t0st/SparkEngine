#if !defined(UNIX)

// Windows compilers need specific (and different) keywords for export and import
#define SPARK_API_EXPORT __declspec(dllexport)
#define SPARK_API_IMPORT __declspec(dllimport)

#else // Linux, FreeBSD, Mac OS X

#define SPARK_API_EXPORT __attribute__((__visibility__("default")))
#define SPARK_API_IMPORT __attribute__((__visibility__("default")))

#endif
