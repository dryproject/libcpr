/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_UTF8_H
#define _CPRIME_UTF8_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h> /* for uint8_t */

#define UTF8_ENCODE(c, output) {                       \
  if (likely(c < 0x00080)) {                           \
    *output++ = (uint8_t)(c & 0xFF);                   \
  }                                                    \
  else if (likely(c < 0x00800)) {                      \
    *output++ = 0xC0 + (uint8_t)((c >> 6) & 0x1F);     \
    *output++ = 0x80 + (uint8_t)(c & 0x3F);            \
  }                                                    \
  else if (likely(c < 0x10000)) {                      \
    *output++ = 0xE0 + (uint8_t)((c >> 12) & 0x0F);    \
    *output++ = 0x80 + (uint8_t)((c >> 6)  & 0x3F);    \
    *output++ = 0x80 + (uint8_t)(c & 0x3F);            \
  }                                                    \
  else {                                               \
    *output++ = 0xF0 + (uint8_t)((c >> 18) & 0x07);    \
    *output++ = 0x80 + (uint8_t)((c >> 12) & 0x3F);    \
    *output++ = 0x80 + (uint8_t)((c >> 6) & 0x3F);     \
    *output++ = 0x80 + (uint8_t)(c & 0x3F);            \
  }                                                    \
}

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_UTF8_H */