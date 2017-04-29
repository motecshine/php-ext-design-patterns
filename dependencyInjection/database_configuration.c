#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "dependencyInjection/database_configuration.h"

ZEND_BEGIN_ARG_INFO(database_configuration_arg_info, 0)
    ZEND_ARG_INFO(0, host)
    ZEND_ARG_INFO(0, port)
    ZEND_ARG_INFO(0, username)
    ZEND_ARG_INFO(0, password)
ZEND_END_ARG_INFO()


PHP_METHOD(database_configuration, __construct)
{

}

PHP_METHOD(database_configuration, getHost)
{

}

PHP_METHOD(database_configuration, getPort)
{

}

PHP_METHOD(database_configuration, getUsername)
{

}

PHP_METHOD(database_configuration, getPassword)
{

}

zend_function_entry database_configuration_methods[] = {
    PHP_ME(database_configuration, __construct, database_configuration_arg_info, ZEND_ACC_CTOR | ZEND_ACC_PUBLIC)
    PHP_ME(database_configuration, getHost, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(database_configuration, getPort, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(database_configuration, getPassword, NULL, ZEND_ACC_PUBLIC)
    PHP_ME(database_configuration, getUsername, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(database_configuration)
{
    zend_class_entry database_configuration_container_ce;
    /* register class */
    INIT_CLASS_ENTRY(database_configuration_container_ce, "PHPDesign\\DI\\DatabaseConfiguration", database_configuration_methods);
    database_configuration_ce =  zend_register_internal_class(&database_configuration_container_ce TSRMLS_CC);

    /* declare class member */
    zend_declare_property_null(database_configuration_ce, ZEND_STRL("host"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(database_configuration_ce, ZEND_STRL("port"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(database_configuration_ce, ZEND_STRL("usrname"), ZEND_ACC_PRIVATE);
    zend_declare_property_null(database_configuration_ce, ZEND_STRL("password"), ZEND_ACC_PRIVATE);
}
