/*
  +----------------------------------------------------------------------+
  | PHP Version 7                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2017 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_DESIGN_PATTERNS_H
#define PHP_DESIGN_PATTERNS_H

extern zend_module_entry php_design_patterns_module_entry;
#define phpext_php_design_patterns_ptr &php_design_patterns_module_entry

#define PHP_DESIGN_PATTERNS_VERSION "0.1.0" /* Replace with version number for your extension */

#ifdef PHP_WIN32
#	define PHP_PHP_DESIGN_PATTERNS_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_DESIGN_PATTERNS_API __attribute__ ((visibility("default")))
#else
#	define PHP_DESIGN_PATTERNS_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:

ZEND_BEGIN_MODULE_GLOBALS(php_design_patterns)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(php_design_patterns)
*/
#define PHP_DESIGN_STARTUP(module)               ZEND_MODULE_STARTUP_N(php_design_patterns_##module)(INIT_FUNC_ARGS_PASSTHRU)
#define PHP_DESIGN_STARTUP_FUNCTION(module)      ZEND_MINIT_FUNCTION(php_design_patterns_##module)
/* Always refer to the globals in your function as PHP_DESIGN_PATTERNS_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define PHP_DESIGN_PATTERNS_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(php_design_patterns, v)

#if defined(ZTS) && defined(COMPILE_DL_PHP_DESIGN_PATTERNS)
#endif
#endif	/* PHP_PHP_DESIGN_PATTERNS_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
