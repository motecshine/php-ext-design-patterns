#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

ZEND_BEGIN_ARG_INFO(facade_arg_info, 0)
    ZEND_ARG_INFO(0, os)
    ZEND_ARG_INFO(0, bios)
ZEND_END_ARG_INFO()

/* include global headers*/
#include "php_design_patterns.h"
#include "facade/facade.h"


PHP_METHOD(facade, __construct)
{
    zval *bios, *os;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_ZVAL(os)
        Z_PARAM_ZVAL(bios)
    ZEND_PARSE_PARAMETERS_END();

    facade_ce = Z_OBJCE_P(getThis());
    /* Update Facade Property*/
    zend_update_property(facade_ce, getThis(), ZEND_STRL("os"), os);
    zend_update_property(facade_ce, getThis(), ZEND_STRL("bios"), bios);
}

PHP_METHOD(facade, turnOn)
{
    zval *bios_object, *os_object;
    zval execute_name, wait_for_key_press_name, launch_name;

    /* Set Function Name */
    ZVAL_STRING(&execute_name, "execute");
    ZVAL_STRING(&wait_for_key_press_name, "waitForKeyPress");
    ZVAL_STRING(&launch_name, "launch");

    facade_ce = Z_OBJCE_P(getThis());

    os_object = zend_read_property(facade_ce , getThis(), ZEND_STRL("os"), 0, 0 TSRMLS_CC);
    /* Get $this->bios */
    bios_object = zend_read_property(facade_ce , getThis(), ZEND_STRL("bios"), 0, 0 TSRMLS_CC);
    /* Execute $this->bios->execute() */
    call_user_function(CG(function_table), bios_object, &execute_name,            return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC);
    call_user_function(CG(function_table), bios_object, &wait_for_key_press_name, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC);
    call_user_function(CG(function_table), bios_object, &launch_name,             return_value, ZEND_NUM_ARGS(), os_object TSRMLS_CC);

    zval_dtor(&execute_name);
    zval_dtor(&wait_for_key_press_name);
    zval_dtor(&launch_name);
}


PHP_METHOD(facade, turnOff)
{

    zval *bios_object, *os_object;
    zval halt_name, power_down_name;
    facade_ce = Z_OBJCE_P(getThis());

    ZVAL_STRING(&halt_name, "halt");
    ZVAL_STRING(&power_down_name, "powerDown");

    os_object = zend_read_property(facade_ce , getThis(), ZEND_STRL("os"), 0, 0 TSRMLS_CC);
    /* Get $this->bios */
    bios_object = zend_read_property(facade_ce , getThis(), ZEND_STRL("bios"), 0, 0 TSRMLS_CC);

    call_user_function(CG(function_table), bios_object, &power_down_name, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC);
    call_user_function(CG(function_table), os_object, &halt_name, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC);
    zval_dtor(&halt_name);
    zval_dtor(&power_down_name);
}

static zend_function_entry facade_methods[] = {
    PHP_ME(facade, __construct, facade_arg_info, ZEND_ACC_CTOR | ZEND_ACC_PUBLIC)
    PHP_ME(facade, turnOn, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(facade, turnOff, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(facade)
{
    zend_class_entry facade_container_ce;
    INIT_CLASS_ENTRY(facade_container_ce, "PHPDesign\\Facade\\Facade", facade_methods);
    facade_ce = zend_register_internal_class(&facade_container_ce TSRMLS_CC);

    /* Declare $os */
    zend_declare_property_null(facade_ce, ZEND_STRL("os"), ZEND_ACC_PRIVATE);
    /* Declare $bios */
    zend_declare_property_null(facade_ce, ZEND_STRL("bios"), ZEND_ACC_PRIVATE);

    return SUCCESS;
}
