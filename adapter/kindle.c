#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/ebook_interface.h"

zend_class_entry *kindle_ce;

PHP_METHOD(kindle, pressNext)
{

}

PHP_METHOD(kindle, unlock)
{

}

PHP_METHOD(kindle, getPage)
{

}

static zend_function_entry kindle_methods[] = {
    PHP_ME(kindle, pressNext, NULL, ZEND_ACC_PUBLIC);
    PHP_ME(kindle, unlock,    NULL, ZEND_ACC_PUBLIC);
    PHP_ME(kindle, getPage,   NULL, ZEND_ACC_PUBLIC);
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(kindle)
{
    zend_string *ebook_interface_name;
    zend_class_entry kindle_container_ce;

    ebook_interface_name = strpprintf(0, "PHPDesign\\EBookInterface");

    INIT_CLASS_ENTRY(kindle_container_ce, "PHPDesign\\Kindle", kindle_methods);
    kindle_ce = zend_register_internal_class(&kindle_container_ce TSRMLS_CC);

    if ((ebook_interface_ce = zend_hash_find_ptr(CG(class_table), ebook_interface_name)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can note implement ebook interface");
        return FAILURE;
    }

    zend_class_implements(kindle_ce TSRMLS_CC, 1, ebook_interface_ce);
    zend_string_release(ebook_interface_name);
    return SUCCESS;
}

