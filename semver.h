/*
 * semver.h
 *
 * Copyright (c) 2015-2017 Tomas Aparicio
 * MIT licensed
 */

#ifndef __SEMVER_H
#define __SEMVER_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SEMVER_VERSION
#define SEMVER_VERSION "0.2.0"
#endif

#define SEMVER_MAX_VERSION_LENGTH 32
#define SEMVER_MAX_PRERELEASE_LENGTH 10
#define SEMVER_MAX_METADATA_LENGTH 10

/**
 * semver_t struct
 */

typedef struct semver_version_s {
  int major;
  int minor;
  int patch;
  char metadata[SEMVER_MAX_METADATA_LENGTH];
  char prerelease[SEMVER_MAX_PRERELEASE_LENGTH];
} semver_t;

/**
 * Set prototypes
 */

int
semver_satisfies (semver_t x, semver_t y, const char *op);

int
semver_satisfies_caret (semver_t x, semver_t y);

int
semver_satisfies_patch (semver_t x, semver_t y);

int
semver_compare (semver_t x, semver_t y);

int
semver_compare_version (semver_t x, semver_t y);

int
semver_compare_prerelease (semver_t x, semver_t y);

int
semver_gt (semver_t x, semver_t y);

int
semver_gte (semver_t x, semver_t y);

int
semver_lt (semver_t x, semver_t y);

int
semver_lte (semver_t x, semver_t y);

int
semver_eq (semver_t x, semver_t y);

int
semver_neq (semver_t x, semver_t y);

int
semver_parse (const char *str, semver_t *ver);

int
semver_parse_version (const char *str, semver_t *ver);

void
semver_render (semver_t *x, char *dest);

int
semver_numeric (semver_t *x);

void
semver_bump (semver_t *x);

void
semver_bump_minor (semver_t *x);

void
semver_bump_patch (semver_t *x);

int
semver_is_valid (const char *s);

int
semver_clean (char *s);

#ifdef __cplusplus
}
#endif

#endif
