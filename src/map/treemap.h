/* This is free and unencumbered software released into the public domain. */

#ifndef _CPRIME_TREEMAP_H
#define _CPRIME_TREEMAP_H

#ifdef __cplusplus
extern "C" {
#endif

static int
treemap_init(treemap_t* const restrict map,
             const hash_func_t hash_func,
             const compare_func_t compare_func,
             const free_func_t free_key_func,
             const free_func_t free_value_func,
             va_list args) {
  (void)map, (void)hash_func, (void)compare_func,
  (void)free_key_func, (void)free_value_func, (void)args;
  return -(errno = ENOTSUP); // TODO
}

static int
treemap_reset(treemap_t* const map) {
  (void)map;
  return -(errno = ENOTSUP); // TODO
}

static int
treemap_clear(treemap_t* const map) {
  (void)map;
  return -(errno = ENOTSUP); // TODO
}

static long
treemap_count(treemap_t* const restrict map,
              const void* const restrict key) {
  (void)map, (void)key;
  return (errno = ENOTSUP), 0; // TODO
}

static bool
treemap_lookup(treemap_t* const restrict map,
               const void* const restrict key,
               void** const restrict value) {
  (void)map, (void)key, (void)value;
  return (errno = ENOTSUP), FALSE; // TODO
}

static int
treemap_insert(treemap_t* const restrict map,
               const void* const restrict key,
               const void* const restrict value) {
  (void)map, (void)key, (void)value;
  return -(errno = ENOTSUP); // TODO
}

static int
treemap_remove(treemap_t* const restrict map,
               const void* const restrict key) {
  (void)map, (void)key;
  return -(errno = ENOTSUP); // TODO
}

const map_vtable_t treemap = {
  .super   = NULL,
  .name    = "treemap",
  .options = 0,
  .init    = treemap_init,
  .reset   = treemap_reset,
  .clear   = treemap_clear,
  .count   = treemap_count,
  .lookup  = treemap_lookup,
  .insert  = treemap_insert,
  .remove  = treemap_remove,
};

#ifdef __cplusplus
}
#endif

#endif /* _CPRIME_TREEMAP_H */
