#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "commander/command_interface.h"
#include "commander/hello_command.h"

ZEND_BEGIN_ARG_INFO(hello_command_arg_info, 0)
    ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

PHP_METHOD(hello_command, __construct)
{
    zval * output;
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(output)
    ZEND_PARSE_PARAMETERS_END();
    /* update cmd */
    hello_command_ce = Z_OBJCE_P(getThis());
    zend_update_property(hello_command_ce, getThis(), ZEND_STRL("output"), output);
}

PHP_METHOD(hello_command, execute)
{

    zval * object;
    zval function_name;
    ZVAL_STRING(&function_name, "execute");
    object = zend_read_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("output"), 0, 0 TSRMLS_CC);
    /* execute function */
    if (call_user_function(CG(function_table), object, &function_name, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "can not execute execute() function");
        return;
    }
    /* release zval */
    zval_dtor(&function_name);
    zval_ptr_dtor(return_value);
}

zend_function_entry hello_command_methods[] = {
    PHP_ME(hello_command, __construct, hello_command_arg_info, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(hello_command, execute, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(hello_command)
{
    zend_class_entry hello_command_container_ce;
    zend_string * command_interface_name, * command_interface_name_tolower;
    INIT_CLASS_ENTRY(hello_command_container_ce, "PHPDesign\\Commander\\HelloCommand", hello_command_methods);
    hello_command_ce = zend_register_internal_class(&hello_command_container_ce);
    command_interface_name = strpprintf(0, "PHPDesign\\Commander\\CommandInterface");
    command_interface_name_tolower = zend_string_tolower(command_interface_name);
    /* get command_interface_ce */
    if ((command_interface_ce = zend_hash_find_ptr(CG(class_table), command_interface_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not Find PHPDesign\\Commander\\CommandInterface HC");
        return FAILURE;
    }
    zend_class_implements(hello_command_ce, 1, command_interface_ce);
    zend_declare_property_null(hello_command_ce, ZEND_STRL("output"), ZEND_ACC_PRIVATE);
    zend_string_release(command_interface_name);
    zend_string_release(command_interface_name_tolower);
    return SUCCESS;
}
