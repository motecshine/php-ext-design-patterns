#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "dependencyInjection/database_connection.h"

ZEND_BEGIN_ARG_INFO(database_connection_arg_info, 0)
    ZEND_ARG_INFO(0, configuration)
ZEND_END_ARG_INFO()


PHP_METHOD(database_connection, __construct)
{

}

PHP_METHOD(database_connection, getDsn)
{

}

zend_function_entry database_connection_methods[] = {
    PHP_ME(database_connection, __construct, database_connection_arg_info, ZEND_ACC_CTOR | ZEND_ACC_PUBLIC)
    PHP_ME(database_connection, getDsn, NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(database_connection)
{
    zend_class_entry database_connection_container_ce;
    /* register class */
    INIT_CLASS_ENTRY(database_connection_container_ce, "PHPDesign\\DI\\DatabaseConnection", database_connection_methods);
    database_connection_ce =  zend_register_internal_class(&database_connection_container_ce TSRMLS_CC);

    /* declare class member */
    zend_declare_property_null(database_connection_ce, ZEND_STRL("configuration"), ZEND_ACC_PRIVATE);
}
