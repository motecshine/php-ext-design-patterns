#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/ebook_interface.h"

static zend_function_entry ebook_interface_methods = {
    PHP_ABSTRACT_ME(ebook_interface, unlock,     NULL)
    PHP_ABSTRACT_ME(ebook_interface, pressNext,  NULL)
    PHP_ABSTRACT_ME(ebook_interface, getPage,    NULL)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(ebook_interface)
{
    zend_class_entry ebook_interface_container_ce;
    INIT_CLASS_ENTRY(ebook_interface_container_ce, "PHPDesign\\EBookInterface", ebook_interface_methods);
    ebook_interface_ce = zend_register_internal_interface(&ebook_interface_container_ce);
    return SUCCESS;
}
