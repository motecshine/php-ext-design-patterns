#ifndef RECEVIER_H
#define RECEVIER_H
zend_class_entry * receiver_ce;
PHP_METHOD(receiver, write);
PHP_METHOD(receiver, getOutput);
PHP_METHOD(receiver, enableDate);
PHP_METHOD(receiver, disableDate);
PHP_DESIGN_STARTUP_FUNCTION(receiver);
#endif
