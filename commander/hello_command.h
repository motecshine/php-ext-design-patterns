#ifndef HELLO_COMMAND_H
#define HELLO_COMMAND_H
zend_class_entry * hello_command_ce;
PHP_METHOD(hello_command, __construct);
PHP_METHOD(hello_command, execute);
PHP_DESIGN_STARTUP_FUNCTION(hello_command);
#endif
