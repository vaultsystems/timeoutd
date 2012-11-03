#ifdef DEBUG

#include <syslog.h>

#define OPENLOG_FLAGS	LOG_CONS|LOG_PID
#define SYSLOG_DEBUG	LOG_DEBUG

void
trace (void *funptr, char *funname, char *filename, int line)
{
  openlog ("timeoutd", OPENLOG_FLAGS, LOG_DAEMON);
  syslog (LOG_DEBUG, "%s:%d: %s() %p", filename, line, funname, funptr);
  closelog ();
}

#define min(x,y)	(x)<=(y) ? (x) : (y)

void
dump (long long n, char *varname, char *filename, int line)
{
  openlog ("timeoutd", OPENLOG_FLAGS, LOG_DAEMON);
  syslog (LOG_DEBUG, "%s:%d: %s %lld", filename, line, varname, n);
  closelog ();
}

void dumps(const char *var, const char *varname, const char *filename,
	   int line)
{
  openlog ("timeoutd", OPENLOG_FLAGS, LOG_DAEMON);
  syslog (LOG_DEBUG, "%s:%d: %s %s", filename, line, varname, var);
  closelog ();
}

#endif /* DEBUG */
