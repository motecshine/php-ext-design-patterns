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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_design_patterns.h"


/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(php_design_patterns)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	PHP_DESIGN_STARTUP(abstract_factory);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(php_design_patterns)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php_design_patterns)
{
#if defined(COMPILE_DL_PHP_DESIGN_PATTERNS) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(php_design_patterns)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php_design_patterns)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "php_design_patterns support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* {{{ php_design_patterns_functions[]
 *
 * Every user visible function must have an entry in php_design_patterns_functions[].
 */
const zend_function_entry php_design_patterns_functions[] = {
	PHP_FE_END	/* Must be the last line in php_design_patterns_functions[] */
};
/* }}} */

/* {{{ php_design_patterns_module_entry
 */
zend_module_entry php_design_patterns_module_entry = {
	STANDARD_MODULE_HEADER,
	"php_design_patterns",
	php_design_patterns_functions,
	PHP_MINIT(php_design_patterns),
	PHP_MSHUTDOWN(php_design_patterns),
	PHP_RINIT(php_design_patterns),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(php_design_patterns),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(php_design_patterns),
	PHP_PHP_DESIGN_PATTERNS_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP_DESIGN_PATTERNS
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(php_design_patterns)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
