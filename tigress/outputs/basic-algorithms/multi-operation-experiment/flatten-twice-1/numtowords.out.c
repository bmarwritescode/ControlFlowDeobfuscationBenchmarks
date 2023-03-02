typedef void *__builtin_va_list;
struct __pthread_internal_list;
union __anonunion___value_771759453;
struct _G_fpos_t;
union pthread_attr_t;
struct timeval;
struct __anonstruct___g1_start32_961093919;
struct timespec;
union __anonunion_pthread_condattr_t_488594145;
struct _G_fpos64_t;
struct __anonstruct_lldiv_t_103911545;
struct __anonstruct_ldiv_t_790849867;
union __anonunion_pthread_mutex_t_335460617;
struct __anonstruct___fsid_t_109580352;
enum __anonenum_idtype_t_558242672;
union __anonunion_pthread_mutexattr_t_488594144;
struct __pthread_mutex_s;
struct __pthread_cond_s;
union __anonunion_pthread_cond_t_951761805;
union __anonunion_pthread_barrier_t_145707746;
union __anonunion_pthread_rwlock_t_656928968;
struct _IO_codecvt;
union __anonunion____missing_field_name_560222071;
struct __anonstruct___sigset_t_973126068;
struct drand48_data;
union __anonunion____missing_field_name_926429417;
struct _IO_FILE;
struct __anonstruct___mbstate_t_332484833;
struct __pthread_rwlock_arch_t;
struct __anonstruct___wseq32_961093918;
struct __pthread_internal_slist;
struct random_data;
struct _IO_marker;
struct _IO_wide_data;
union __anonunion_pthread_rwlockattr_t_145707745;
struct __anonstruct_fd_set_356711149;
struct __anonstruct_div_t_773697287;
union __anonunion_pthread_barrierattr_t_951761806;
typedef unsigned long __u_quad_t;
typedef unsigned int __mode_t;
typedef unsigned int __u_int;
typedef __u_int u_int;
extern int putchar_unlocked(int __c);
extern long(mrand48)(void);
typedef unsigned long __ino_t;
typedef __ino_t ino_t;
typedef struct _IO_FILE FILE;
extern int putc(int __c, FILE *__stream);
typedef long __blksize_t;
typedef __blksize_t blksize_t;
typedef int __daddr_t;
typedef __daddr_t daddr_t;
typedef unsigned long size_t;
extern size_t fread_unlocked(void *__ptr, size_t __size, size_t __n, FILE *__stream);
typedef unsigned long __fsfilcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
extern char *(ctermid)(char *__s);
extern int fputs(char const *__s, FILE *__stream);
extern void(funlockfile)(FILE *__stream);
typedef unsigned long __nlink_t;
typedef __nlink_t nlink_t;
extern size_t(__ctype_get_mb_cur_max)(void);
extern size_t fread(void *__ptr, size_t __size, size_t __n, FILE *__stream);
typedef unsigned long __uint64_t;
typedef __uint64_t u_int64_t;
extern FILE *tmpfile(void);
extern void(abort)(void);
extern int(getloadavg)(double *__loadavg, int __nelem);
typedef long __off64_t;
typedef long __fd_mask;
typedef unsigned char __uint8_t;
typedef __uint8_t __uint_least8_t;
extern char *(tempnam)(char const *__dir, char const *__pfx);
extern int(at_quick_exit)(void (*__func)(void));
typedef long __ssize_t;
extern __ssize_t getline(char **__lineptr, size_t *__n, FILE *__stream);
typedef int __clockid_t;
typedef unsigned short __uint16_t;
typedef __builtin_va_list __gnuc_va_list;
extern int vsprintf(char *__s, char const *__format, __gnuc_va_list __arg);
extern int(fileno)(FILE *__stream);
extern int vprintf(char const *__format, __gnuc_va_list __arg);
typedef int __key_t;
typedef __key_t key_t;
typedef unsigned long __fsblkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef struct __anonstruct_fd_set_356711149 fd_set;
typedef int volatile pthread_spinlock_t;
struct __anonstruct_ldiv_t_790849867 {
  long quot;
  long rem;
};
extern int(rand_r)(unsigned int *__seed);
union __anonunion___value_771759453 {
  unsigned int __wch;
  char __wchb[4];
};
struct __anonstruct___mbstate_t_332484833 {
  int __count;
  union __anonunion___value_771759453 __value;
};
typedef struct __anonstruct___mbstate_t_332484833 __mbstate_t;
typedef long __off_t;
struct _G_fpos_t {
  __off_t __pos;
  __mbstate_t __state;
};
typedef struct _G_fpos_t __fpos_t;
typedef __fpos_t fpos_t;
extern int(srand48_r)(long __seedval, struct drand48_data *__buffer);
typedef __fd_mask fd_mask;
extern void *(malloc)(size_t __size);
extern long long(atoll)(char const *__nptr);
typedef int register_t;
extern int getw(FILE *__stream);
extern char *(realpath)(char const *__name, char *__resolved);
typedef struct __anonstruct_ldiv_t_790849867 ldiv_t;
struct drand48_data {
  unsigned short __x[3];
  unsigned short __old_x[3];
  unsigned short __c;
  unsigned short __init;
  unsigned long long __a;
};
typedef struct __anonstruct_lldiv_t_103911545 lldiv_t;
struct __anonstruct___g1_start32_961093919 {
  unsigned int __low;
  unsigned int __high;
};
union __anonunion____missing_field_name_926429417 {
  unsigned long long __g1_start;
  struct __anonstruct___g1_start32_961093919 __g1_start32;
};
extern char *(getenv)(char const *__name);
struct __anonstruct_fd_set_356711149 {
  __fd_mask __fds_bits[1024 / (8 * (int)sizeof(__fd_mask))];
};
typedef unsigned int __id_t;
typedef short __int16_t;
typedef __int16_t int16_t;
typedef union __anonunion_pthread_mutexattr_t_488594144 pthread_mutexattr_t;
typedef signed char __int8_t;
extern int(clearenv)(void);
extern int vsnprintf(char *__s, size_t __maxlen, char const *__format, __gnuc_va_list __arg);
typedef __clockid_t clockid_t;
extern double(erand48)(unsigned short *__xsubi);
extern int sprintf(char *__s, char const *__format, ...);
extern FILE *stdout;
typedef __id_t id_t;
typedef int (*__compar_fn_t)(void const *, void const *);
extern void(exit)(int __status);
extern int putc_unlocked(int __c, FILE *__stream);
extern int vscanf(char const *__format, __gnuc_va_list __arg);
typedef __int16_t __int_least16_t;
extern int(abs)(int __x);
typedef int wchar_t;
extern int(mbtowc)(wchar_t *__pwc, char const *__s, size_t __n);
typedef struct __anonstruct___sigset_t_973126068 __sigset_t;
typedef __ssize_t ssize_t;
extern long(labs)(long __x);
extern int(nrand48_r)(unsigned short *__xsubi, struct drand48_data *__buffer, long *__result);
typedef unsigned long __rlim64_t;
struct __pthread_internal_list {
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
};
typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_mutex_s {
  int __lock;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
  short __spins;
  short __elision;
  __pthread_list_t __list;
};
union __anonunion_pthread_mutex_t_335460617 {
  struct __pthread_mutex_s __data;
  char __size[40];
  long __align;
};
typedef long __blkcnt64_t;
extern int(setstate_r)(char *__statebuf, struct random_data *__buf);
extern char *(qfcvt)(long double __value, int __ndigit, int *__decpt, int *__sign);
extern char *(qgcvt)(long double __value, int __ndigit, char *__buf);
extern int system(char const *__command);
extern int(feof_unlocked)(FILE *__stream);
extern float(strtof)(char const *__nptr, char **__endptr);
typedef long __suseconds_t;
typedef long __time_t;
struct timeval {
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
extern size_t fwrite(void const *__ptr, size_t __size, size_t __n, FILE *__s);
extern char *(fcvt)(double __value, int __ndigit, int *__decpt, int *__sign);
extern int pselect(int __nfds, fd_set *__readfds, fd_set *__writefds, fd_set *__exceptfds, struct timespec const *__timeout, __sigset_t const *__sigmask);
typedef long __int64_t;
typedef __int64_t int64_t;
extern int pclose(FILE *__stream);
typedef void _IO_lock_t;
struct _IO_FILE {
  int _flags;
  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;
  struct _IO_FILE *_freeres_list;
  void *_freeres_buf;
  size_t __pad5;
  int _mode;
  char _unused2[(15UL * sizeof(int) - 4UL * sizeof(void *)) - sizeof(size_t)];
};
typedef long __syscall_slong_t;
typedef int pthread_once_t;
typedef unsigned int __uint32_t;
extern void(clearerr)(FILE *__stream);
typedef unsigned char __u_char;
typedef __u_char u_char;
extern long long(strtoll)(char const *__nptr, char **__endptr, int __base);
typedef __off_t off_t;
extern __ssize_t getdelim(char **__lineptr, size_t *__n, int __delimiter, FILE *__stream);
char **_global_argv;
extern int(ftrylockfile)(FILE *__stream);
extern int(posix_memalign)(void **__memptr, size_t __alignment, size_t __size);
typedef union __anonunion_pthread_rwlockattr_t_145707745 pthread_rwlockattr_t;
extern long(random)(void);
typedef __uint16_t u_int16_t;
extern int fgetpos(FILE *__stream, fpos_t *__pos);
extern int fgetc(FILE *__stream);
extern void(flockfile)(FILE *__stream);
extern int(feof)(FILE *__stream);
extern int putchar(int __c);
extern int(putenv)(char *__string);
typedef int __int32_t;
typedef __int32_t int32_t;
struct random_data {
  int32_t *fptr;
  int32_t *rptr;
  int32_t *state;
  int rand_type;
  int rand_deg;
  int rand_sep;
  int32_t *end_ptr;
};
extern int scanf(char const *__format, ...);
typedef unsigned long __rlim_t;
typedef unsigned long __uintmax_t;
extern int(getsubopt)(char **__optionp, char *const *__tokens, char **__valuep);
extern int puts(char const *__s);
extern int fflush(FILE *__stream);
extern int(qfcvt_r)(long double __value, int __ndigit, int *__decpt, int *__sign, char *__buf, size_t __len);
typedef long __clock_t;
typedef union __anonunion_pthread_barrierattr_t_951761806 pthread_barrierattr_t;
extern FILE *(fmemopen)(void *__s, size_t __len, char const *__modes);
typedef void *__timer_t;
typedef __timer_t timer_t;
extern char *(setstate)(char *__statebuf);
struct __pthread_rwlock_arch_t {
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  signed char __rwelision;
  unsigned char __pad1[7];
  unsigned long __pad2;
  unsigned int __flags;
};
union __anonunion_pthread_rwlock_t_656928968 {
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long __align;
};
extern void rewind(FILE *__stream);
typedef int __pid_t;
extern long long(llabs)(long long __x);
typedef unsigned int __uid_t;
typedef __uid_t uid_t;
struct __anonstruct___wseq32_961093918 {
  unsigned int __low;
  unsigned int __high;
};
union __anonunion____missing_field_name_560222071 {
  unsigned long long __wseq;
  struct __anonstruct___wseq32_961093918 __wseq32;
};
struct __pthread_internal_slist {
  struct __pthread_internal_slist *__next;
};
extern unsigned long long(strtoull)(char const *__nptr, char **__endptr, int __base);
typedef union __anonunion_pthread_cond_t_951761805 pthread_cond_t;
extern FILE *stderr;
struct __pthread_cond_s {
  union __anonunion____missing_field_name_560222071 __annonCompField1;
  union __anonunion____missing_field_name_926429417 __annonCompField2;
  unsigned int __g_refs[2];
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
extern lldiv_t(lldiv)(long long __numer, long long __denom);
typedef __suseconds_t suseconds_t;
extern int(srandom_r)(unsigned int __seed, struct random_data *__buf);
extern int fputc_unlocked(int __c, FILE *__stream);
typedef union __anonunion_pthread_rwlock_t_656928968 pthread_rwlock_t;
struct __anonstruct___fsid_t_109580352 {
  int __val[2];
};
typedef struct __anonstruct___fsid_t_109580352 __fsid_t;
typedef __fsid_t fsid_t;
typedef __uint32_t __uint_least32_t;
typedef unsigned int __gid_t;
typedef __gid_t gid_t;
typedef char *__caddr_t;
typedef __caddr_t caddr_t;
typedef struct __anonstruct_div_t_773697287 div_t;
union __anonunion_pthread_rwlockattr_t_145707745 {
  char __size[8];
  long __align;
};
extern int printf(char const *__format, ...);
extern void(clearerr_unlocked)(FILE *__stream);
extern int(renameat)(int __oldfd, char const *__old, int __newfd, char const *__new);
typedef struct _IO_FILE __FILE;
extern long(lrand48)(void);
enum __anonenum_idtype_t_558242672 { P_ALL = 0, P_PID = 1, P_PGID = 2 };
typedef unsigned long __u_long;
extern unsigned long(strtoul)(char const *__nptr, char **__endptr, int __base);
typedef __clock_t clock_t;
extern FILE *popen(char const *__command, char const *__modes);
extern char *(mktemp)(char *__template);
extern long(nrand48)(unsigned short *__xsubi);
extern char *(initstate)(unsigned int __seed, char *__statebuf, size_t __statelen);
void OBF_FUNC(int n);
typedef struct __pthread_internal_slist __pthread_slist_t;
extern void(quick_exit)(int __status);
typedef __uint8_t u_int8_t;
typedef unsigned short __u_short;
typedef __u_short u_short;
extern int(mrand48_r)(struct drand48_data *__buffer, long *__result);
extern int fgetc_unlocked(FILE *__stream);
extern void(_Exit)(int __status);
typedef long __quad_t;
typedef __quad_t quad_t;
extern void(srand48)(long __seedval);
extern __off_t ftello(FILE *__stream);
extern int sys_nerr;
union __anonunion_pthread_mutexattr_t_488594144 {
  char __size[4];
  int __align;
};
typedef unsigned short ushort;
extern int(initstate_r)(unsigned int __seed, char *__statebuf, size_t __statelen, struct random_data *__buf);
extern int(atoi)(char const *__nptr);
extern int fscanf(FILE *__stream, char const *__format, ...);
extern int fputc(int __c, FILE *__stream);
typedef __uint16_t __uint_least16_t;
extern int __overflow(FILE *, int);
extern int dprintf(int __fd, char const *__fmt, ...);
extern void(lcong48)(unsigned short *__param);
extern int(rename)(char const *__old, char const *__new);
struct timespec {
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
extern int(ferror_unlocked)(FILE *__stream);
int _global_argc;
extern char *(tmpnam_r)(char *__s);
extern int(mkstemp)(char *__template);
extern char *(qecvt)(long double __value, int __ndigit, int *__decpt, int *__sign);
extern int putw(int __w, FILE *__stream);
extern long(a64l)(char const *__s);
union __anonunion_pthread_barrierattr_t_951761806 {
  char __size[4];
  int __align;
};
extern int fprintf(FILE *__stream, char const *__format, ...);
extern int __uflow(FILE *);
typedef long __blkcnt_t;
extern int(setenv)(char const *__name, char const *__value, int __replace);
extern double(strtod)(char const *__nptr, char **__endptr);
typedef int __sig_atomic_t;
extern int(sscanf)(char const *__s, char const *__format, ...);
typedef unsigned long __ino64_t;
extern long long(strtoq)(char const *__nptr, char **__endptr, int __base);
extern int getchar(void);
extern int(unsetenv)(char const *__name);
typedef __mode_t mode_t;
extern size_t(wcstombs)(char *__s, wchar_t const *__pwcs, size_t __n);
typedef unsigned long ulong;
typedef union __anonunion_pthread_condattr_t_488594145 pthread_condattr_t;
extern long(atol)(char const *__nptr);
extern size_t(mbstowcs)(wchar_t *__pwcs, char const *__s, size_t __n);
extern int(seed48_r)(unsigned short *__seed16v, struct drand48_data *__buffer);
extern int(mkstemps)(char *__template, int __suffixlen);
struct __anonstruct___sigset_t_973126068 {
  unsigned long __val[1024UL / (8UL * sizeof(unsigned long))];
};
extern int(qecvt_r)(long double __value, int __ndigit, int *__decpt, int *__sign, char *__buf, size_t __len);
extern int fseeko(FILE *__stream, __off_t __off, int __whence);
extern size_t fwrite_unlocked(void const *__ptr, size_t __size, size_t __n, FILE *__stream);
extern char *(l64a)(long __n);
typedef __off64_t __loff_t;
typedef unsigned long __dev_t;
typedef __dev_t dev_t;
typedef unsigned int uint;
struct _G_fpos64_t {
  __off64_t __pos;
  __mbstate_t __state;
};
extern char *(ecvt)(double __value, int __ndigit, int *__decpt, int *__sign);
extern void *(realloc)(void *__ptr, size_t __size);
extern int(fileno_unlocked)(FILE *__stream);
typedef unsigned int pthread_key_t;
typedef union __anonunion_pthread_barrier_t_145707746 pthread_barrier_t;
extern long(jrand48)(unsigned short *__xsubi);
extern int(fcvt_r)(double __value, int __ndigit, int *__decpt, int *__sign, char *__buf, size_t __len);
typedef __loff_t loff_t;
extern int vfscanf(FILE *__s, char const *__format, __gnuc_va_list __arg);
extern void(srand)(unsigned int __seed);
typedef __int32_t __int_least32_t;
extern int(atexit)(void (*__func)(void));
typedef __u_quad_t u_quad_t;
extern int fclose(FILE *__stream);
union pthread_attr_t {
  char __size[56];
  long __align;
};
extern FILE *(open_memstream)(char **__bufloc, size_t *__sizeloc);
typedef unsigned int __useconds_t;
extern void(qsort)(void *__base, size_t __nmemb, size_t __size, int (*__compar)(void const *, void const *));
typedef __uint32_t u_int32_t;
extern FILE *fopen(char const *__filename, char const *__modes);
extern long(strtol)(char const *__nptr, char **__endptr, int __base);
extern char *(mkdtemp)(char *__template);
typedef unsigned long __fsblkcnt64_t;
extern int fseek(FILE *__stream, long __off, int __whence);
extern double(atof)(char const *__nptr);
typedef __sigset_t sigset_t;
typedef __gnuc_va_list va_list;
union __anonunion_pthread_cond_t_951761805 {
  struct __pthread_cond_s __data;
  char __size[48];
  long long __align;
};
typedef unsigned int __socklen_t;
extern int getchar_unlocked(void);
extern long ftell(FILE *__stream);
extern void(setlinebuf)(FILE *__stream);
typedef union pthread_attr_t pthread_attr_t;
extern FILE *freopen(char const *__filename, char const *__modes, FILE *__stream);
extern int getc(FILE *__stream);
extern void *(reallocarray)(void *__ptr, size_t __nmemb, size_t __size);
extern FILE *(fdopen)(int __fd, char const *__modes);
extern unsigned short *(seed48)(unsigned short *__seed16v);
extern int vdprintf(int __fd, char const *__fmt, __gnuc_va_list __arg);
extern char *fgets(char *__s, int __n, FILE *__stream);
extern int ungetc(int __c, FILE *__stream);
typedef union __anonunion_pthread_mutex_t_335460617 pthread_mutex_t;
extern char const *const sys_errlist[];
extern long double(strtold)(char const *__nptr, char **__endptr);
extern void *(bsearch)(void const *__key, void const *__base, size_t __nmemb, size_t __size, int (*__compar)(void const *, void const *));
extern div_t(div)(int __numer, int __denom);
extern int getc_unlocked(FILE *__stream);
extern int(remove)(char const *__filename);
typedef __uint64_t __uint_least64_t;
extern char *(gcvt)(double __value, int __ndigit, char *__buf);
typedef __time_t time_t;
typedef enum __anonenum_idtype_t_558242672 idtype_t;
typedef __int64_t __int_least64_t;
typedef __int8_t int8_t;
extern int snprintf(char *__s, size_t __maxlen, char const *__format, ...);
extern int(lcong48_r)(unsigned short *__param, struct drand48_data *__buffer);
extern int fsetpos(FILE *__stream, fpos_t const *__pos);
typedef unsigned long __fsfilcnt64_t;
extern int(mblen)(char const *__s, size_t __n);
extern int(setvbuf)(FILE *__stream, char *__buf, int __modes, size_t __n);
typedef struct _G_fpos64_t __fpos64_t;
extern char *(tmpnam)(char *__s);
typedef __blkcnt_t blkcnt_t;
extern void *(aligned_alloc)(size_t __alignment, size_t __size);
extern int(rpmatch)(char const *__response);
extern ldiv_t(ldiv)(long __numer, long __denom);
typedef long __intmax_t;
typedef __u_long u_long;
union __anonunion_pthread_barrier_t_145707746 {
  char __size[32];
  long __align;
};
extern void *(calloc)(size_t __nmemb, size_t __size);
extern int(drand48_r)(struct drand48_data *__buffer, double *__result);
char **_global_envp;
extern int vfprintf(FILE *__s, char const *__format, __gnuc_va_list __arg);
extern void *(valloc)(size_t __size);
extern int(random_r)(struct random_data *__buf, int32_t *__result);
extern int select(int __nfds, fd_set *__readfds, fd_set *__writefds, fd_set *__exceptfds, struct timeval *__timeout);
typedef unsigned long __syscall_ulong_t;
extern int(ecvt_r)(double __value, int __ndigit, int *__decpt, int *__sign, char *__buf, size_t __len);
typedef __int8_t __int_least8_t;
extern void *(alloca)(size_t __size);
extern void(free)(void *__ptr);
int main(int argc, char **argv, char **_formal_envp);
extern int(lrand48_r)(struct drand48_data *__buffer, long *__result);
extern int(jrand48_r)(unsigned short *__xsubi, struct drand48_data *__buffer, long *__result);
extern void(setbuf)(FILE *__stream, char *__buf);
extern int(wctomb)(char *__s, wchar_t __wchar);
extern int(erand48_r)(unsigned short *__xsubi, struct drand48_data *__buffer, double *__result);
extern FILE *stdin;
typedef long __intptr_t;
extern __ssize_t __getdelim(char **__lineptr, size_t *__n, int __delimiter, FILE *__stream);
extern int(vsscanf)(char const *__s, char const *__format, __gnuc_va_list __arg);
typedef __pid_t pid_t;
struct __anonstruct_lldiv_t_103911545 {
  long long quot;
  long long rem;
};
typedef long __fsword_t;
union __anonunion_pthread_condattr_t_488594145 {
  char __size[4];
  int __align;
};
extern void perror(char const *__s);
extern int fflush_unlocked(FILE *__stream);
extern void(srandom)(unsigned int __seed);
extern int(rand)(void);
typedef unsigned long pthread_t;
extern int(on_exit)(void (*__func)(int __status, void *__arg), void *__arg);
extern double(drand48)(void);
extern unsigned long long(strtouq)(char const *__nptr, char **__endptr, int __base);
extern int(ferror)(FILE *__stream);
extern void(setbuffer)(FILE *__stream, char *__buf, size_t __size);
struct __anonstruct_div_t_773697287 {
  int quot;
  int rem;
};
void OBF_FUNC(int n) {
  int i;
  int j;
  int digit;
  char *word[1000];
  int tmp;
  int tmp___0;
  int tmp___1;
  int tmp___2;
  int tmp___3;
  int tmp___4;
  int tmp___5;
  int tmp___6;
  int tmp___7;
  int tmp___8;
  unsigned long _1_OBF_FUNC_next;
  void *_1_OBF_FUNC_jumpTab[53];
  unsigned long _1_OBF_FUNC_next___0;
  {
    { _1_OBF_FUNC_next___0 = 88UL; }
    while (1) {
      switch (_1_OBF_FUNC_next___0) {
      case 0:
        _1_OBF_FUNC_jumpTab[4] = (void *)162UL;
        { _1_OBF_FUNC_next___0 = 58UL; }
        break;
      case 91:
        _1_OBF_FUNC_jumpTab[39] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 37UL; }
        break;
      case 84:
        _1_OBF_FUNC_jumpTab[45] = (void *)12UL;
        { _1_OBF_FUNC_next___0 = 30UL; }
        break;
      case 159:
        _1_OBF_FUNC_jumpTab[51] = (void *)143UL;
        { _1_OBF_FUNC_next___0 = 129UL; }
        break;
      case 3:
        _1_OBF_FUNC_jumpTab[29] = (void *)70UL;
        { _1_OBF_FUNC_next___0 = 59UL; }
        break;
      case 114:
        _1_OBF_FUNC_jumpTab[25] = (void *)60UL;
        { _1_OBF_FUNC_next___0 = 148UL; }
        break;
      case 36:
      _1_OBF_FUNC_lab16:
        n /= 10;
        { _1_OBF_FUNC_next___0 = 122UL; }
        break;
      case 6:
      _1_OBF_FUNC_lab30:
        i++;
        { _1_OBF_FUNC_next___0 = 60UL; }
        break;
      case 148:
        _1_OBF_FUNC_jumpTab[26] = (void *)7UL;
        { _1_OBF_FUNC_next___0 = 89UL; }
        break;
      case 38:
        _1_OBF_FUNC_jumpTab[16] = (void *)16UL;
        { _1_OBF_FUNC_next___0 = 131UL; }
        break;
      case 18:
      _1_OBF_FUNC_lab54:
        j--;
        { _1_OBF_FUNC_next___0 = 10UL; }
        break;
      case 66:
      _1_OBF_FUNC_lab23:
        word[tmp___7] = (char *)"eight";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 108:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 128:;
        {
          _1_OBF_FUNC_next___0 = 32UL;
        }
        break;
      case 77:
      _1_OBF_FUNC_lab24:
        i++;
        { _1_OBF_FUNC_next___0 = 8UL; }
        break;
      case 65:
        _1_OBF_FUNC_jumpTab[7] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 139UL; }
        break;
      case 54:
      _1_OBF_FUNC_lab34:
        i++;
        { _1_OBF_FUNC_next___0 = 93UL; }
        break;
      case 95:
      _1_OBF_FUNC_lab50:
        word[tmp___5] = (char *)"six";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 120:;
        {
          _1_OBF_FUNC_next___0 = 54UL;
        }
        break;
      case 7:
      _1_OBF_FUNC_lab28:
        i = 0;
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 47:;
        {
          _1_OBF_FUNC_next___0 = 5UL;
        }
        break;
      case 73:;
        {
          _1_OBF_FUNC_next___0 = 6UL;
        }
        break;
      case 29:
        _1_OBF_FUNC_jumpTab[38] = (void *)115UL;
        { _1_OBF_FUNC_next___0 = 91UL; }
        break;
      case 98:;
        if (j >= 0) {
          { _1_OBF_FUNC_next___0 = 102UL; }
        } else {
          { _1_OBF_FUNC_next___0 = 12UL; }
        }
        break;
      case 50:;
        {
          _1_OBF_FUNC_next___0 = 11UL;
        }
        break;
      case 80:;
        {
          _1_OBF_FUNC_next___0 = 57UL;
        }
        break;
      case 42:;
        {
          _1_OBF_FUNC_next___0 = 10UL;
        }
        break;
      case 86:;
        {
          _1_OBF_FUNC_next___0 = 102UL;
        }
        break;
      case 138:
        _1_OBF_FUNC_jumpTab[3] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 0UL; }
        break;
      case 69:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 22:;
        if (n) {
          { _1_OBF_FUNC_next___0 = 31UL; }
        } else {
          { _1_OBF_FUNC_next___0 = 32UL; }
        }
        break;
      case 1:
        _1_OBF_FUNC_jumpTab[32] = (void *)54UL;
        { _1_OBF_FUNC_next___0 = 27UL; }
        break;
      case 158:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 62:
        _1_OBF_FUNC_jumpTab[31] = (void *)150UL;
        { _1_OBF_FUNC_next___0 = 1UL; }
        break;
      case 115:
      _1_OBF_FUNC_lab40:
        word[tmp___4] = (char *)"five";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 56:;
        {
          _1_OBF_FUNC_next___0 = 143UL;
        }
        break;
      case 25:
      _1_OBF_FUNC_lab51:
        i++;
        { _1_OBF_FUNC_next___0 = 95UL; }
        break;
      case 44:
      _1_OBF_FUNC_lab26:
        i++;
        { _1_OBF_FUNC_next___0 = 107UL; }
        break;
      case 152:
      _1_OBF_FUNC_lab29:
        i++;
        { _1_OBF_FUNC_next___0 = 11UL; }
        break;
      case 121:;
        {
          _1_OBF_FUNC_next___0 = 8UL;
        }
        break;
      case 49:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 85:;
        {
          _1_OBF_FUNC_next___0 = 150UL;
        }
        break;
      case 79:;
        {
          _1_OBF_FUNC_next___0 = 70UL;
        }
        break;
      case 119:
        _1_OBF_FUNC_jumpTab[12] = (void *)57UL;
        { _1_OBF_FUNC_next___0 = 109UL; }
        break;
      case 162:
      _1_OBF_FUNC_lab6:
        i++;
        { _1_OBF_FUNC_next___0 = 115UL; }
        break;
      case 53:;
        {
          _1_OBF_FUNC_next___0 = 87UL;
        }
        break;
      case 111:
        _1_OBF_FUNC_jumpTab[23] = (void *)82UL;
        { _1_OBF_FUNC_next___0 = 39UL; }
        break;
      case 123:;
        {
          _1_OBF_FUNC_next___0 = 26UL;
        }
        break;
      case 15:
        _1_OBF_FUNC_jumpTab[14] = (void *)36UL;
        { _1_OBF_FUNC_next___0 = 113UL; }
        break;
      case 161:
      _1_OBF_FUNC_lab38:
        tmp___6 = i;
        { _1_OBF_FUNC_next___0 = 54UL; }
        break;
      case 63:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 109:
        _1_OBF_FUNC_jumpTab[13] = (void *)32UL;
        { _1_OBF_FUNC_next___0 = 15UL; }
        break;
      case 5:
      _1_OBF_FUNC_lab32:
        word[tmp___2] = (char *)"three";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 12:
      _1_OBF_FUNC_lab47:
        printf((char const *)"\n");
        { _1_OBF_FUNC_next___0 = 103UL; }
        break;
      case 68:;
        {
          _1_OBF_FUNC_next___0 = 12UL;
        }
        break;
      case 97:;
        {
          _1_OBF_FUNC_next___0 = 43UL;
        }
        break;
      case 118:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 99:
      _1_OBF_FUNC_lab43:
        word[tmp___3] = (char *)"four";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 51:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 137:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 142:;
        {
          _1_OBF_FUNC_next___0 = 95UL;
        }
        break;
      case 64:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 28:;
        {
          _1_OBF_FUNC_next___0 = 99UL;
        }
        break;
      case 144:;
        {
          _1_OBF_FUNC_next___0 = 60UL;
        }
        break;
      case 52:;
        {
          _1_OBF_FUNC_next___0 = 25UL;
        }
        break;
      case 34:;
        {
          _1_OBF_FUNC_next___0 = 44UL;
        }
        break;
      case 117:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 139:
        _1_OBF_FUNC_jumpTab[8] = (void *)133UL;
        { _1_OBF_FUNC_next___0 = 151UL; }
        break;
      case 58:
        _1_OBF_FUNC_jumpTab[5] = (void *)87UL;
        { _1_OBF_FUNC_next___0 = 83UL; }
        break;
      case 45:;
        {
          _1_OBF_FUNC_next___0 = 107UL;
        }
        break;
      case 26:
      _1_OBF_FUNC_lab42:
        tmp___0 = i;
        { _1_OBF_FUNC_next___0 = 6UL; }
        break;
      case 81:
        _1_OBF_FUNC_jumpTab[37] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 29UL; }
        break;
      case 136:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 140:;
        {
          _1_OBF_FUNC_next___0 = 122UL;
        }
        break;
      case 104:;
        return;
        break;
      case 74:;
        {
          _1_OBF_FUNC_next___0 = 77UL;
        }
        break;
      case 11:
      _1_OBF_FUNC_lab12:
        word[tmp] = (char *)"zero";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 132:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 72:
      _1_OBF_FUNC_lab8:
        tmp___8 = i;
        { _1_OBF_FUNC_next___0 = 44UL; }
        break;
      case 75:
        _1_OBF_FUNC_jumpTab[18] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 127UL; }
        break;
      case 133:
      _1_OBF_FUNC_lab10:;
        { _1_OBF_FUNC_next___0 = 22UL; }
        break;
      case 131:
        _1_OBF_FUNC_jumpTab[17] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 75UL; }
        break;
      case 70:
      _1_OBF_FUNC_lab31:
        tmp___1 = i;
        { _1_OBF_FUNC_next___0 = 77UL; }
        break;
      case 31:
      _1_OBF_FUNC_lab37:
        digit = n % 10;
        { _1_OBF_FUNC_next___0 = 36UL; }
        break;
      case 67:
        _1_OBF_FUNC_jumpTab[34] = (void *)8UL;
        { _1_OBF_FUNC_next___0 = 24UL; }
        break;
      case 30:
        _1_OBF_FUNC_jumpTab[46] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 94UL; }
        break;
      case 153:;
        {
          _1_OBF_FUNC_next___0 = 10UL;
        }
        break;
      case 76:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 32:
      _1_OBF_FUNC_lab15:
        j = i - 1;
        { _1_OBF_FUNC_next___0 = 10UL; }
        break;
      case 19:
        _1_OBF_FUNC_jumpTab[1] = (void *)35UL;
        { _1_OBF_FUNC_next___0 = 126UL; }
        break;
      case 46:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 134:;
        {
          _1_OBF_FUNC_next___0 = 93UL;
        }
        break;
      case 59:
        _1_OBF_FUNC_jumpTab[30] = (void *)5UL;
        { _1_OBF_FUNC_next___0 = 62UL; }
        break;
      case 16:
      _1_OBF_FUNC_lab18:
        i++;
        { _1_OBF_FUNC_next___0 = 99UL; }
        break;
      case 14:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 33:;
        {
          _1_OBF_FUNC_next___0 = 35UL;
        }
        break;
      case 125:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 154:;
        {
          _1_OBF_FUNC_next___0 = 161UL;
        }
        break;
      case 112:
        _1_OBF_FUNC_jumpTab[42] = (void *)103UL;
        { _1_OBF_FUNC_next___0 = 90UL; }
        break;
      case 135:
        _1_OBF_FUNC_jumpTab[28] = (void *)6UL;
        { _1_OBF_FUNC_next___0 = 3UL; }
        break;
      case 101:
        _1_OBF_FUNC_jumpTab[41] = (void *)99UL;
        { _1_OBF_FUNC_next___0 = 112UL; }
        break;
      case 102:
      _1_OBF_FUNC_lab11:
        printf((char const *)"%s ", word[j]);
        { _1_OBF_FUNC_next___0 = 18UL; }
        break;
      case 106:
        _1_OBF_FUNC_jumpTab[49] = (void *)25UL;
        { _1_OBF_FUNC_next___0 = 23UL; }
        break;
      case 9:
        _1_OBF_FUNC_jumpTab[11] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 119UL; }
        break;
      case 105:
        _1_OBF_FUNC_jumpTab[21] = (void *)66UL;
        { _1_OBF_FUNC_next___0 = 149UL; }
        break;
      case 89:
        _1_OBF_FUNC_jumpTab[27] = (void *)152UL;
        { _1_OBF_FUNC_next___0 = 135UL; }
        break;
      case 103:
      _1_OBF_FUNC_lab44:;
        { _1_OBF_FUNC_next___0 = 104UL; }
        break;
      case 24:
        _1_OBF_FUNC_jumpTab[35] = (void *)31UL;
        { _1_OBF_FUNC_next___0 = 141UL; }
        break;
      case 61:;
        {
          _1_OBF_FUNC_next___0 = 162UL;
        }
        break;
      case 4:;
        return;
        break;
      case 2:;
        switch (digit) {
        case 0: {
          _1_OBF_FUNC_next___0 = 143UL;
        } break;
        case 1: {
          _1_OBF_FUNC_next___0 = 26UL;
        } break;
        case 2: {
          _1_OBF_FUNC_next___0 = 70UL;
        } break;
        case 3: {
          _1_OBF_FUNC_next___0 = 43UL;
        } break;
        case 4: {
          _1_OBF_FUNC_next___0 = 87UL;
        } break;
        case 5: {
          _1_OBF_FUNC_next___0 = 78UL;
        } break;
        case 6: {
          _1_OBF_FUNC_next___0 = 57UL;
        } break;
        case 7: {
          _1_OBF_FUNC_next___0 = 161UL;
        } break;
        case 8: {
          _1_OBF_FUNC_next___0 = 82UL;
        } break;
        case 9: {
          _1_OBF_FUNC_next___0 = 72UL;
        } break;
        default: {
          _1_OBF_FUNC_next___0 = 133UL;
        } break;
        }
        break;
      case 27:
        _1_OBF_FUNC_jumpTab[33] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 67UL; }
        break;
      case 87:
      _1_OBF_FUNC_lab7:
        tmp___3 = i;
        { _1_OBF_FUNC_next___0 = 16UL; }
        break;
      case 78:
      _1_OBF_FUNC_lab2:
        tmp___4 = i;
        { _1_OBF_FUNC_next___0 = 162UL; }
        break;
      case 8:
      _1_OBF_FUNC_lab36:
        word[tmp___1] = (char *)"two";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 55:
        _1_OBF_FUNC_jumpTab[10] = (void *)11UL;
        { _1_OBF_FUNC_next___0 = 9UL; }
        break;
      case 146:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 113:
        _1_OBF_FUNC_jumpTab[15] = (void *)43UL;
        { _1_OBF_FUNC_next___0 = 38UL; }
        break;
      case 23:
        _1_OBF_FUNC_jumpTab[50] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 159UL; }
        break;
      case 129:
        _1_OBF_FUNC_jumpTab[52] = (void *)18UL;
        { _1_OBF_FUNC_next___0 = 71UL; }
        break;
      case 107:
      _1_OBF_FUNC_lab46:
        word[tmp___8] = (char *)"nine";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 17:
        _1_OBF_FUNC_jumpTab[48] = (void *)95UL;
        { _1_OBF_FUNC_next___0 = 106UL; }
        break;
      case 40:;
        {
          _1_OBF_FUNC_next___0 = 31UL;
        }
        break;
      case 160:;
        {
          _1_OBF_FUNC_next___0 = 18UL;
        }
        break;
      case 155:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 41:;
        {
          _1_OBF_FUNC_next___0 = 78UL;
        }
        break;
      case 57:
      _1_OBF_FUNC_lab14:
        tmp___5 = i;
        { _1_OBF_FUNC_next___0 = 25UL; }
        break;
      case 149:
        _1_OBF_FUNC_jumpTab[22] = (void *)77UL;
        { _1_OBF_FUNC_next___0 = 111UL; }
        break;
      case 130:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 96:;
        {
          _1_OBF_FUNC_next___0 = 115UL;
        }
        break;
      case 60:
      _1_OBF_FUNC_lab27:
        word[tmp___0] = (char *)"one";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 124:;
        {
          _1_OBF_FUNC_next___0 = 103UL;
        }
        break;
      case 92:
        _1_OBF_FUNC_jumpTab[44] = (void *)107UL;
        { _1_OBF_FUNC_next___0 = 84UL; }
        break;
      case 21:;
        {
          _1_OBF_FUNC_next___0 = 36UL;
        }
        break;
      case 71:
        _1_OBF_FUNC_next = 28UL;
        { _1_OBF_FUNC_next___0 = 147UL; }
        break;
      case 147:;
        {
          _1_OBF_FUNC_next___0 = (unsigned long)_1_OBF_FUNC_jumpTab[_1_OBF_FUNC_next - 2UL];
        }
        break;
      case 150:
      _1_OBF_FUNC_lab33:
        i++;
        { _1_OBF_FUNC_next___0 = 66UL; }
        break;
      case 116:
        _1_OBF_FUNC_jumpTab[20] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 105UL; }
        break;
      case 83:
        _1_OBF_FUNC_jumpTab[6] = (void *)72UL;
        { _1_OBF_FUNC_next___0 = 65UL; }
        break;
      case 13:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 39:
        _1_OBF_FUNC_jumpTab[24] = (void *)44UL;
        { _1_OBF_FUNC_next___0 = 114UL; }
        break;
      case 35:
      _1_OBF_FUNC_lab3:
        i++;
        { _1_OBF_FUNC_next___0 = 5UL; }
        break;
      case 10:
      _1_OBF_FUNC_lab4:;
        { _1_OBF_FUNC_next___0 = 98UL; }
        break;
      case 93:
      _1_OBF_FUNC_lab21:
        word[tmp___6] = (char *)"seven";
        { _1_OBF_FUNC_next___0 = 133UL; }
        break;
      case 90:
        _1_OBF_FUNC_jumpTab[43] = (void *)122UL;
        { _1_OBF_FUNC_next___0 = 92UL; }
        break;
      case 110:;
        {
          _1_OBF_FUNC_next___0 = 72UL;
        }
        break;
      case 43:
      _1_OBF_FUNC_lab17:
        tmp___2 = i;
        { _1_OBF_FUNC_next___0 = 35UL; }
        break;
      case 145:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 37:
        _1_OBF_FUNC_jumpTab[40] = (void *)26UL;
        { _1_OBF_FUNC_next___0 = 101UL; }
        break;
      case 122:
      _1_OBF_FUNC_lab45:;
        { _1_OBF_FUNC_next___0 = 2UL; }
        break;
      case 88:
        _1_OBF_FUNC_jumpTab[0] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 19UL; }
        break;
      case 157:;
        {
          _1_OBF_FUNC_next___0 = 82UL;
        }
        break;
      case 141:
        _1_OBF_FUNC_jumpTab[36] = (void *)161UL;
        { _1_OBF_FUNC_next___0 = 81UL; }
        break;
      case 48:;
        {
          _1_OBF_FUNC_next___0 = 133UL;
        }
        break;
      case 82:
      _1_OBF_FUNC_lab25:
        tmp___7 = i;
        { _1_OBF_FUNC_next___0 = 150UL; }
        break;
      case 151:
        _1_OBF_FUNC_jumpTab[9] = (void *)102UL;
        { _1_OBF_FUNC_next___0 = 55UL; }
        break;
      case 100:;
        {
          _1_OBF_FUNC_next___0 = 66UL;
        }
        break;
      case 94:
        _1_OBF_FUNC_jumpTab[47] = (void *)78UL;
        { _1_OBF_FUNC_next___0 = 17UL; }
        break;
      case 127:
        _1_OBF_FUNC_jumpTab[19] = (void *)93UL;
        { _1_OBF_FUNC_next___0 = 116UL; }
        break;
      case 143:
      _1_OBF_FUNC_lab53:
        tmp = i;
        { _1_OBF_FUNC_next___0 = 152UL; }
        break;
      case 156:;
        {
          _1_OBF_FUNC_next___0 = 16UL;
        }
        break;
      case 20:;
        {
          _1_OBF_FUNC_next___0 = 152UL;
        }
        break;
      case 126:
        _1_OBF_FUNC_jumpTab[2] = (void *)10UL;
        { _1_OBF_FUNC_next___0 = 138UL; }
        break;
      }
    }
  }
}
int main(int argc, char **argv, char **_formal_envp) {
  int tmp;
  int _BARRIER_0;
  int _BARRIER_0___0;
  {
    {
      {
        {
          { goto _global_envp_i$nit_INLINE__global_envp_i$nit___0; }
        _global_envp_i$nit_INLINE__global_envp_i$nit___0:;
        }
        {
          { goto _global_argv_i$nit_INLINE__global_argv_i$nit___0; }
        _global_argv_i$nit_INLINE__global_argv_i$nit___0:;
        }
        {
          { goto _global_argc_i$nit_INLINE__global_argc_i$nit___0; }
        _global_argc_i$nit_INLINE__global_argc_i$nit___0:;
        }
        goto megaInit_INLINE_megaInit___0;
      }
    megaInit_INLINE_megaInit___0:;
    }
    _global_argc = argc;
    _global_argv = argv;
    _global_envp = _formal_envp;
    _BARRIER_0___0 = 1;
    goto _global_envp_i$nit_INLINE__global_envp_i$nit;
  _global_envp_i$nit_INLINE__global_envp_i$nit:;
    goto _global_argv_i$nit_INLINE__global_argv_i$nit;
  _global_argv_i$nit_INLINE__global_argv_i$nit:;
    goto _global_argc_i$nit_INLINE__global_argc_i$nit;
  _global_argc_i$nit_INLINE__global_argc_i$nit:;
    goto megaInit_INLINE_megaInit;
  megaInit_INLINE_megaInit:
    _global_argc = argc;
    _global_argv = argv;
    _global_envp = _formal_envp;
    _BARRIER_0 = 1;
    tmp = atoi((char const *)*(argv + 1));
    OBF_FUNC(tmp);
    return (0);
  }
}