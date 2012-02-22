/* This is free and unencumbered software released into the public domain. */

#ifndef CPRIME_DIR_H
#define CPRIME_DIR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <dirent.h> /* for DIR, dirent */

#define DIRENT_SIZE \
  offsetof(struct dirent, d_name) + \
  pathconf(".", _PC_NAME_MAX) + 1

typedef struct dir_t {
  DIR* stream;
  struct dirent* entry;
  char path[PATH_MAX];
} dir_t;

extern bool dir_exists(const char* path);

#define DIR_INIT {.stream = NULL, .entry = NULL, .path = "\0"}

#define dir_init1(dir) dir_init_empty(dir)
#define dir_init2(dir, arg1) \
  DISPATCH_BEGIN(arg1) \
    DISPATCH(dir_init_with_path, dir, char*, arg1, NULL) \
  DISPATCH_END(dir_init_with_path, dir)
#define dir_init(...) \
  CONCAT(dir_init, ARITY(__VA_ARGS__))(__VA_ARGS__)

extern int dir_init_empty(dir_t* dir);
extern int dir_init_with_path(dir_t* dir, const char* const restrict path);

extern int dir_open(dir_t* dir);
extern int dir_close(dir_t* dir);

extern int dir_read(dir_t* dir);

extern long dir_size(dir_t* dir);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* CPRIME_DIR_H */
