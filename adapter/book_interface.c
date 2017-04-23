#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/book_interface.h"

static zend_function_entry book_interface_methods[] = {
    PHP_ABSTRACT_ME(book_interface, turnPage, NULL)
    PHP_ABSTRACT_ME(book_interface, open,     NULL)
    PHP_ABSTRACT_ME(book_interface, getPage,  NULL)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(book_interface)
{
    zend_class_entry book_interface_container_ce;
    INIT_CLASS_ENTRY(book_interface_container_ce, "PHPDesign\\BookInterface", book_interface_methods);
    zend_register_internal_interface(&book_interface_container_ce);
    return SUCCESS;
}
