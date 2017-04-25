#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/service.h"

ZEND_BEGIN_ARG_INFO(service_arg_info, 0)
    ZEND_ARG_INFO(0, printer)
ZEND_END_ARG_INFO()

PHP_METHOD(service, __construct)
{
    zval *printer;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(printer)
    ZEND_PARSE_PARAMETERS_END();

    service_ce = Z_OBJCE_P(getThis());
    zend_update_property(service_ce, getThis(), ZEND_STRL("implementation"), printer);
}

PHP_METHOD(service, setImplementation)
{
    zval *printer;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(printer)
    ZEND_PARSE_PARAMETERS_END();

    service_ce = Z_OBJCE_P(getThis());
    zend_update_property(service_ce, getThis(), ZEND_STRL("implementation"), printer);
}


zend_function_entry service_methods[] = {
    PHP_ME(service, __construct, service_arg_info, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(service, setImplementation, service_arg_info, ZEND_ACC_PUBLIC)
    PHP_ABSTRACT_ME(service, get)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(service)
{
    zend_class_entry service_container_ce;
    INIT_CLASS_ENTRY(service_container_ce, "PHPDesign\\Service", service_methods);
    service_ce = zend_register_internal_class(&service_container_ce TSRMLS_CC);
    /* Declare $implementation*/
    zend_declare_property_null(service_ce, ZEND_STRL("implementation"), ZEND_ACC_PROTECTED);
    return SUCCESS;
}
