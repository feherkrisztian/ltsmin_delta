#ifndef SET_LL_H
#define SET_LL_H

/**
\file dbs-ll.h
\brief Lockless hash set for strings with internal allocation.
 This class maintains a set of strings and projects this down to a dense range
 of integers. The operations are thread-safe. The quality of the density is
 dependent on an equal workload (number of inserts) among the different threads.
*/


/**
\typedef The string set.
*/
typedef struct set_ll_s set_ll_t;

/**
\typedef The global allocator for the set.
*/
typedef struct set_ll_allocator_s set_ll_allocator_t;

/**
 \brief Initializes internal allocator. Call once. Uses HRE.
 */
extern set_ll_allocator_t *set_ll_init_allocator (bool shared);

extern size_t              set_ll_print_alloc_stats(log_t log, set_ll_allocator_t *);

extern char        *set_ll_get      (set_ll_t *set, int idx, int *len);

extern int          set_ll_put      (set_ll_t *set, char *str, int len);

extern int          set_ll_count    (set_ll_t *set);

/**
\Brief binds a key to a specific value. NOT THREAD-SAFE!
 */
void                set_ll_install (set_ll_t *set, char *name, int len, int idx);

extern set_ll_t    *set_ll_create   ();

/**
\brief Fill-in all indices in the set with bogus values to create a continuous
        range as required by LTS io library.
 */
extern double       set_ll_finalize (set_ll_t *set, char *bogus);

extern size_t       set_ll_print_stats(log_t log, set_ll_t *set, char *name);

extern void         set_ll_destroy  (set_ll_t *set);

#endif
