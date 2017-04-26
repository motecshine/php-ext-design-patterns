#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "bridge/formatter_interface.h"
#include "bridge/html_formatter.h"

ZEND_BEGIN_ARG_INFO(html_formatter_arg_info, 0)
    ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

PHP_METHOD(html_formatter, format)
{
    zval *text;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(text)
    ZEND_PARSE_PARAMETERS_END();

    php_printf("<p>%s</p>", Z_STR_P(text));
}

static zend_function_entry  html_formatter_methods[] = {
    PHP_ME(html_formatter, format, html_formatter_arg_info, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(html_formatter)
{
    zend_class_entry html_formatter_conatainer_ce;
    zend_string *formatter_interface_name, *formatter_interface_name_tolower;
    INIT_CLASS_ENTRY(html_formatter_conatainer_ce, "PHPDesign\\HtmlFormatter", html_formatter_methods);
    html_formatter_ce = zend_register_internal_class(&html_formatter_conatainer_ce TSRMLS_CC);
    formatter_interface_name = strpprintf(0, "PHPDesign\\FormatterInterface");
    formatter_interface_name_tolower = zend_string_tolower(formatter_interface_name);
    if ((formatter_interface_ce = zend_hash_find_ptr(CG(class_table), formatter_interface_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not implement PHPDesign\\FormatterInterface");
        return FAILURE;
    }
    zend_class_implements(html_formatter_ce TSRMLS_CC, 1, formatter_interface_ce);
    zend_string_release(formatter_interface_name);
    zend_string_release(formatter_interface_name_tolower);
    return SUCCESS;
}
