#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H
extern zend_class_entry * database_connection_ce;
PHP_METHOD(database_connection, __construct);
PHP_METHOD(database_connection, getDsn);
PHP_DESIGN_STARTUP_FUNCTION(database_connection);
#endif
