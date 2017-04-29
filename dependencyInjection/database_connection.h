#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H
zend_class_entry * database_configuration_ce;
PHP_METHOD(database_configuration, __construct);
PHP_METHOD(database_configuration, getDsn);
PHP_DESIGN_STARTUP_FUNCTION(database_configuration);
#endif
