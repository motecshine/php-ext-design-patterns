#ifndef UNDOABLE_COMMAND_INTERFACE_H
#define UNDOABLE_COMMAND_INTERFACE_H
zend_class_entry * ud_command_interface_ce;
PHP_DESIGN_STARTUP_FUNCTION(ud_command_interface, undo);
#endif
