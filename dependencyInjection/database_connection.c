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
    zval *config;
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_ZVAL(config)
    ZEND_PARSE_PARAMETERS_END();
    database_connection_ce = Z_OBJCE_P(getThis());
    /* update $configuration */
    zend_update_property(database_connection_ce, getThis(), ZEND_STRL("configuration"), config TSRMLS_CC);
}

PHP_METHOD(database_connection, getDsn)
{
    zval *object;
    zval getUsername, getPassword, getHost, getPort;
    zval username, password, host, port;
    /* set function name */
    ZVAL_STRING(&getUsername, "getUsername");
    ZVAL_STRING(&getPassword, "getPassword");
    ZVAL_STRING(&getHost, "getHost");
    ZVAL_STRING(&getPort, "getPort");
    /* get class ce */
    database_connection_ce = Z_OBJCE_P(getThis());

    /* get class object */
    object = zend_read_property(database_connection_ce, getThis(), ZEND_STRL("configuration"), 0, 0 TSRMLS_CC);

    call_user_function(CG(function_table), object, &getUsername, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC);
    ZVAL_STRING(&username, Z_STRVAL_P(return_value));

    call_user_function(CG(function_table), object, &getPassword, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC);
    ZVAL_STRING(&password, Z_STRVAL_P(return_value));

    call_user_function(CG(function_table), object, &getHost, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC);
    ZVAL_STRING(&host, Z_STRVAL_P(return_value));

    call_user_function(CG(function_table), object, &getPort, return_value, ZEND_NUM_ARGS(), NULL TSRMLS_CC);
    ZVAL_STRING(&port, Z_STRVAL_P(return_value));

    php_printf(
        "%s:%s@:%s:%s\n",
        Z_STRVAL(username),
        Z_STRVAL(password),
        Z_STRVAL(host),
        Z_STRVAL(port)
    );
    zval_dtor(&getPassword);
    zval_dtor(&getUsername);
    zval_dtor(&getPort);
    zval_dtor(&getHost);
    zval_dtor(&username);
    zval_dtor(&password);
    zval_dtor(&host);
    zval_dtor(&port);
    zval_ptr_dtor(return_value);
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
