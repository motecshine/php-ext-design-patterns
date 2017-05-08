#ifndef ADD_MESSAGE_DATE_COMMAND_H
#define ADD_MESSAGE_DATE_COMMAND_H
zend_class_entry * add_msg_date_cmd_ce;
PHP_METHOD(add_msg_date_cmd, __construct);
PHP_METHOD(add_msg_date_cmd, execute);
PHP_METHOD(add_msg_date_cmd, undo);
PHP_DESIGN_STARTUP_FUNCTION(add_msg_date_cmd);
#endif
