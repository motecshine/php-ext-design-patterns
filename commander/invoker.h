#ifndef INVOKER_H
#define INVOKER_H
zend_class_entry * invoker_ce;
PHP_METHOD(invoker, setCommand);
PHP_METHOD(invoker, run);
PHP_DESIGN_STARTUP_FUNCTION(invoker);
#endif
