/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_NULLSEQ_H
#define CPRIME_NULLSEQ_H

#ifdef __cplusplus
extern "C" {
#endif

const class_t nullseq_class = {
  .name    = "nullseq",
  .super   = &seq_class,
  .vtable  = &nullseq_vtable.base,
};

static int
nullseq_init(nullseq_t* const seq, va_list args) {
  (void)seq, (void)args;
  return SUCCESS;
}

static int
nullseq_dispose(nullseq_t* const seq) {
  (void)seq;
  return SUCCESS;
}

static int
nullseq_clear(nullseq_t* const seq) {
  (void)seq;
  return SUCCESS;
}

static long
nullseq_count(nullseq_t* const restrict seq,
              const void* const restrict elt) {
  (void)seq, (void)elt;
  return 0; // the sequence is empty
}

static bool
nullseq_lookup(nullseq_t* const restrict seq,
               const void* const restrict elt) {
  (void)seq, (void)elt;
  return FALSE; // element not found
}

static int
nullseq_insert(nullseq_t* const restrict seq,
               const void* const restrict elt) {
  (void)seq, (void)elt;
  return FAILURE(ENOTSUP); // operation not supported
}

static int
nullseq_remove(nullseq_t* const restrict seq,
               const void* const restrict elt) {
  (void)seq, (void)elt;
  return FAILURE(ENOTSUP); // operation not supported
}

static int
nullseq_replace(nullseq_t* const restrict seq,
                const void* const restrict elt1,
                const void* const restrict elt2) {
  (void)seq, (void)elt1, (void)elt2;
  return FAILURE(ENOTSUP); // operation not supported
}

/**
 * The canonical immutable empty sequence.
 */
const seq_vtable_t nullseq_vtable = {
  .base    = {.klass = &nullseq_class},
  .init    = nullseq_init,
  .dispose = nullseq_dispose,
  .clear   = nullseq_clear,
  .length  = NULL,
  .count   = nullseq_count,
  .lookup  = nullseq_lookup,
  .insert  = nullseq_insert,
  .remove  = nullseq_remove,
  .replace = nullseq_replace,
  .reverse = NULL,
  .sort    = NULL,
};

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_NULLSEQ_H */
