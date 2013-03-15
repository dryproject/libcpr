/* This is free and unencumbered software released into the public domain. */

#ifndef CPR_FEATURE_H
#define CPR_FEATURE_H

/**
 * @file
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h> /* for bool */

/**
 * Determines whether libcpr supports a given feature.
 */
bool cpr_feature_exists(const char* feature_name);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPR_FEATURE_H */
