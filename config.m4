dnl $Id$
dnl config.m4 for extension php_design_patterns

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(php_design_patterns, for php_design_patterns support,
dnl Make sure that the comment is aligned:
[  --with-php_design_patterns             Include php_design_patterns support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(php_design_patterns, whether to enable php_design_patterns support,
dnl Make sure that the comment is aligned:
dnl [  --enable-php_design_patterns           Enable php_design_patterns support])

if test "$PHP_PHP_DESIGN_PATTERNS" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-php_design_patterns -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/php_design_patterns.h"  # you most likely want to change this
  dnl if test -r $PHP_PHP_DESIGN_PATTERNS/$SEARCH_FOR; then # path given as parameter
  dnl   PHP_DESIGN_PATTERNS_DIR=$PHP_PHP_DESIGN_PATTERNS
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for php_design_patterns files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PHP_DESIGN_PATTERNS_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PHP_DESIGN_PATTERNS_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the php_design_patterns distribution])
  dnl fi

  dnl # --with-php_design_patterns -> add include path
  dnl PHP_ADD_INCLUDE($PHP_DESIGN_PATTERNS_DIR/include)

  dnl # --with-php_design_patterns -> check for lib and symbol presence
  dnl LIBNAME=php_design_patterns # you may want to change this
  dnl LIBSYMBOL=php_design_patterns # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PHP_DESIGN_PATTERNS_DIR/$PHP_LIBDIR, PHP_DESIGN_PATTERNS_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_PHP_DESIGN_PATTERNSLIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong php_design_patterns lib version or lib not found])
  dnl ],[
  dnl   -L$PHP_DESIGN_PATTERNS_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(PHP_DESIGN_PATTERNS_SHARED_LIBADD)

  PHP_NEW_EXTENSION(
  php_design_patterns,
  abstract_factory/mac_factory.c                \
  abstract_factory/win_factory.c                \
  abstract_factory/abstract_factory.c           \
  adapter/book.c                                \
  adapter/book_interface.c                      \
  adapter/ebook_adapter.c                       \
  adapter/ebook_interface.c                     \
  adapter/kindle.c                              \
  bridge/formatter_interface.c                  \
  bridge/hello_world_service.c                  \
  bridge/html_formatter.c                       \
  bridge/plain_text_formatter.c                 \
  bridge/service.c                              \
  facade/bios.c                                 \
  facade/bios_interface.c                       \
  facade/facade.c                               \
  facade/linux_os.c                             \
  facade/os_interface.c                         \
  dependencyInjection/database_configuration.c  \
  dependencyInjection/database_connection.c     \
  php_design_patterns.c,
  $ext_shared,
  )
  PHP_ADD_BUILD_DIR([$ext_builddir/abstract_factory])
fi
