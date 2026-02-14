#ifdef NDEBUG
#  define VERIFY(expr) ((void)(expr))
#else
#  include <assert.h>
#  define VERIFY(expr) assert(expr)
#endif
