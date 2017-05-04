#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "commander/command_interface.h"
#include "commander/invoker.h"

ZEND_BEGIN_ARG_INFO(invoker_arg_info, 0)
    ZEND_ARG_INFO(0, command)
ZEND_END_ARG_INFO()

PHP_METHOD(invoker, setCommand)
{
    zval * command;
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(command)
    ZEND_PARSE_PARAMETERS_END();
    /* update cmd */
    zend_update_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("command"), command);
}

PHP_METHOD(invoker, run)
{
    zval * object;
    zval function_name;
    ZVAL_STRING(&function_name, "execute");
    object = zend_read_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("command"), 0, 0 TSRMLS_CC);
    /* execute function */
    if (call_user_function(CG(function_table), object, &function_name, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "can not execute execute() function");
        return;
    }
    /* release zval */
    zval_dtor(&function_name);
    zval_ptr_dtor(return_value);
}

zend_function_entry invoker_methods[] = {
    PHP_ME(invoker, setCommand, invoker_arg_info, ZEND_ACC_PUBLIC)
    PHP_ME(invoker, run, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(invoker)
{
    zend_class_entry invoker_container_ce;
    INIT_CLASS_ENTRY(invoker_container_ce, "PHPDesign\\Commander\\Invoker", invoker_methods);
    invoker_ce = zend_register_internal_class(&invoker_container_ce);
    zend_declare_property_null(invoker_ce, ZEND_STRL("command"), ZEND_ACC_PUBLIC);
    return SUCCESS;
}
