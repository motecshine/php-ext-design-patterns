#ifndef FACADE_H
#define FACADE_H
extern zend_class_entry * facade_ce;
PHP_METHOD(facade, __construct);
PHP_METHOD(facade, turnOn);
PHP_METHOD(facade, turnOff);
PHP_DESIGN_STARTUP_FUNCTION(facade);
#endif
