/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_PRELUDE_H
#define CPR_PRELUDE_H

/**
 * @file
 */

#include <system_error> /* for std::errc */

#include "cpr/error.h"  /* for cpr_error_trigger() */

#define cpr_malloc(s)     std::malloc(s)
#define cpr_free(p)       std::free(p)
#define cpr_calloc(n, s)  std::calloc(n, s)
#define cpr_realloc(p, s) std::realloc(p, s)

#ifndef __has_builtin
  #define __has_builtin(x) 0
#endif

#ifndef __has_feature
  #define __has_feature(x) 0
#endif

#ifndef __has_extension
  #define __has_extension __has_feature
#endif

static inline void
cpr_error_trigger(const char* caller_name,
                  const std::errc& error_code,
                  const char* error_message, ...) {
  cpr_error_trigger(caller_name,
    static_cast<int>(error_code), error_message); // TODO: varargs
}

#endif /* CPR_PRELUDE_H */
