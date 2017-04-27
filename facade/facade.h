#ifndef FACADE_H
#define FACADE_H
zend_class_entry *facade_ce;
PHP_METHOD(facade, __construct);
PHP_METHOD(facade, __turnOn);
PHP_METHOD(facade, __turnOff);
PHP_DESIGN_STARTUP_FUNCTION(facade);
#endif
