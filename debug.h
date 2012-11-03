#ifdef DEBUG

#define TRACE(fn)	trace(fn, #fn, __FILE__, __LINE__)
void trace(void *funptr, char *funname, char *filename, int line);
#define DUMP(num)	dump(num, #num, __FILE__, __LINE__)
void dump(long long n, char *varname, char *filename, int line);
#define DUMPS(str)	dumps(str, #str, __FILE__, __LINE__)
void dumps(const char *var, const char *varname, const char *filename,
	   int line);

#else  /* not DEBUG */

#define TRACE(fn)
#define DUMP(var)
#define DUMPS(var)

#endif
