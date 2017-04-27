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

    ZEND_PARSE_PARAMS_START(2, 2)
        Z_PARAM_ZVAL(0, os)
        Z_PARAM_ZVAL(0, bios)
    ZEND_PARSE_PARAMS_END();

    facade_ce = Z_OBJCE_P(getThis());
    /* Update Facade Property*/
    zend_update_property(facade_ce, getThis, ZEND_STRL("os"), os);
    zend_update_property(facade_ce, getThis, ZEND_STRL("bios"), bios);
}

PHP_METHOD(facade, turnOn)
{

}

PHP_METHOD(facade, turnOff)
{

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
