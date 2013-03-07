AUTOMAKE_OPTIONS=foreign

lib_LTLIBRARIES=liblruqueue.la
liblruqueue_la_SOURCES=lruqueue.c\
                       lrunode.c\
                       lruhash.c

liblruqueue_la_CPPFLAGS=`pkg-config --libs --cflags glib-2.0`
