/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "cpr/map.h"

#include <map> /* for std::map */

struct cpr_map : public std::map<void*, void*> {
  // TODO
};