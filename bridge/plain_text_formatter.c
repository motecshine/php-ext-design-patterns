#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "bridge/formatter_interface.h"
#include "bridge/plain_text_formatter.h"

ZEND_BEGIN_ARG_INFO(plain_text_formatter_arg_info, 0)
    ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

PHP_METHOD(plain_text_formatter, format)
{
    zend_string *text;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(text)
    ZEND_PARSE_PARAMETERS_END();

    php_printf("%s\n", ZSTR_VAL(text));
}

static zend_function_entry  plain_text_formatter_methods[] = {
    PHP_ME(plain_text_formatter, format, plain_text_formatter_arg_info, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(plain_text_formatter)
{
    zend_class_entry plain_text_formatter_conatainer_ce;
    zend_string *formatter_interface_name, *formatter_interface_name_tolower;
    INIT_CLASS_ENTRY(plain_text_formatter_conatainer_ce, "PHPDesign\\PlainTextFormatter", plain_text_formatter_methods);
    plain_text_formatter_ce = zend_register_internal_class(&plain_text_formatter_conatainer_ce TSRMLS_CC);
    formatter_interface_name = strpprintf(0, "PHPDesign\\FormatterInterface");
    formatter_interface_name_tolower = zend_string_tolower(formatter_interface_name);
    if ((formatter_interface_ce = zend_hash_find_ptr(CG(class_table), formatter_interface_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not implement PHPDesign\\FormatterInterface");
        return FAILURE;
    }
    zend_class_implements(plain_text_formatter_ce TSRMLS_CC, 1, formatter_interface_ce);
    zend_string_release(formatter_interface_name);
    zend_string_release(formatter_interface_name_tolower);
    return SUCCESS;
}
