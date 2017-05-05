#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "commander/undoable_command_interface.h"
#include "commander/command_interface.h"
#include "commander/add_message_date_command.h"

ZEND_BEGIN_ARG_INFO(add_msg_date_cmd_arg_info, 0)
    ZEND_ARG_INFO(0, output)
ZEND_END_ARG_INFO()

PHP_METHOD(add_msg_date_cmd, __construct)
{
	zval * output;
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(output)
    ZEND_PARSE_PARAMETERS_END();
    zend_update_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("output"), output);
	zval_ptr_dtor(output);
}

PHP_METHOD(add_msg_date_cmd, execute)
{
    zval * object;
    zval function_name;
    ZVAL_STRING(&function_name, "enableDate");
    object = zend_read_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("output"), 0, 0 TSRMLS_CC);
    /* execute function */
    if (call_user_function(CG(function_table), object, &function_name, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "can not execute enableDate() function");
        return;
    }
    /* release zval */
    zval_dtor(&function_name);
    zval_ptr_dtor(return_value);
}

PHP_METHOD(add_msg_date_cmd, undo)
{
    zval * object;
    zval function_name;
    ZVAL_STRING(&function_name, "disableDate");
    object = zend_read_property(Z_OBJCE_P(getThis()), getThis(), ZEND_STRL("output"), 0, 0 TSRMLS_CC);
    /* execute function */
    if (call_user_function(CG(function_table), object, &function_name, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC) == FAILURE) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "can not execute disableDate() function");
        return;
    }
    /* release zval */
    zval_dtor(&function_name);
    zval_ptr_dtor(return_value);
}

zend_function_entry add_msg_date_cmd_methods[] = {
    PHP_ME(add_msg_date_cmd, __construct, add_msg_date_cmd_arg_info, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(add_msg_date_cmd, execute, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(add_msg_date_cmd, undo, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(add_msg_date_cmd)
{
    zend_class_entry add_msg_date_cmd_container_ce;
    zend_string * ud_command_interface_name, * ud_command_interface_name_tolower;
    zend_string * command_interface_name, * command_interface_name_tolower;
    command_interface_name = strpprintf(0, "PHPDesign\\Commander\\CommandInterface");
    command_interface_name_tolower = zend_string_tolower(command_interface_name);
    ud_command_interface_name = strpprintf(0, "PHPDesign\\Commander\\UndoableCommandInterface");
    ud_command_interface_name_tolower = zend_string_tolower(ud_command_interface_name);

    INIT_CLASS_ENTRY(add_msg_date_cmd_container_ce, "PHPDesign\\Commander\\AddMessageDateCommand", add_msg_date_cmd_methods);
    add_msg_date_cmd_ce = zend_register_internal_class(&add_msg_date_cmd_container_ce);

    if ((ud_command_interface_ce = zend_hash_find_ptr(CG(class_table), ud_command_interface_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not Find PHPDesign\\Commander\\UndoableCommandInterface");
        return FAILURE;
    }

    /* get command_interface_ce */
    if ((command_interface_ce = zend_hash_find_ptr(CG(class_table), command_interface_name_tolower)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not Find PHPDesign\\Commander\\CommandInterface");
        return FAILURE;
    }
    zend_class_implements(add_msg_date_cmd_ce, 2, ud_command_interface_ce, command_interface_ce);
    zend_declare_property_null(add_msg_date_cmd_ce, ZEND_STRL("output"), ZEND_ACC_PRIVATE);
    /* release zend string */
    zend_string_release(command_interface_name);
    zend_string_release(command_interface_name_tolower);
    zend_string_release(ud_command_interface_name);
    zend_string_release(ud_command_interface_name_tolower);
    return SUCCESS;
}
