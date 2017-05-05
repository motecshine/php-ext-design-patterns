#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "commander/undoable_command_interface.h"
#include "commander/receiver.h"

ZEND_BEGIN_ARG_INFO(receiver_arg_info, 0)
    ZEND_ARG_INFO(0, string)
ZEND_END_ARG_INFO()

PHP_METHOD(receiver, write)
{
    zval * enableDate, * output;
    zend_string * string;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(string)
    ZEND_PARSE_PARAMETERS_END();

    /* get $enableDate */
    enableDate = zend_read_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("enableDate"), 0, NULL TSRMLS_CC);
    output = zend_read_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("output"), 0, NULL TSRMLS_CC);
    if (Z_TYPE_P(enableDate) == IS_TRUE) {
        string =  strpprintf(0, "%s %s", ZSTR_VAL(string), "1993-04-01");
    }
    array_init(output);
    add_index_str(output, 0, string);
    zend_string_release(string);
}

PHP_METHOD(receiver, getOutput)
{
    zval * retval;
    retval = zend_read_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("output"), 0, NULL TSRMLS_CC);
    RETVAL_ZVAL(retval, 0, 1);
}

PHP_METHOD(receiver, enableDate)
{
    ZVAL_BOOL(return_value, IS_TRUE);
    zend_update_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("enableDate"), return_value);
    zval_ptr_dtor(return_value);
}

PHP_METHOD(receiver, disableDate)
{
    ZVAL_BOOL(return_value, IS_FALSE);
    zend_update_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("enableDate"), return_value);
    zval_ptr_dtor(return_value);
}

zend_function_entry receiver_methods[] = {
    PHP_ME(receiver, write, receiver_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(receiver, getOutput, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(receiver, enableDate, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(receiver, disableDate, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(receiver)
{
    zend_class_entry receiver_container_ce;
    INIT_CLASS_ENTRY(receiver_container_ce, "PHPDesign\\Commander\\Receiver", receiver_methods);
    receiver_ce = zend_register_internal_class(&receiver_container_ce);

    /* declare property */
    zend_declare_property_bool(receiver_ce, ZEND_STRL("enableDate"), (zend_long) 0, ZEND_ACC_PRIVATE);
    zend_declare_property_null(receiver_ce, ZEND_STRL("output"), ZEND_ACC_PRIVATE);
}
