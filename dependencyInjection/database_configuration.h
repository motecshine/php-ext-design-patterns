#ifndef DATABASE_CONFIGURATION_H
#define DATABASE_CONFIGURATION_H
static zend_class_entry * database_configuration_ce;
PHP_METHOD(database_configuration, __construct);
PHP_METHOD(database_configuration, getHost);
PHP_METHOD(database_configuration, getPort);
PHP_METHOD(database_configuration, getUsername);
PHP_METHOD(database_configuration, getPassword);
PHP_DESIGN_STARTUP_FUNCTION(database_configuration);
#endif
