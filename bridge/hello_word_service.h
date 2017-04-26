#ifndef HELLO_WORLD_SERVICE_H
#define HELLO_WORLD_SERVICE_H
zend_class_entry *hello_world_service_ce;
PHP_METHOD(hello_world_service, get);
PHP_DESIGN_STARTUP_FUNCTION(hello_world_service);
#endif

