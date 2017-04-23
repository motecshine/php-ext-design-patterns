#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/book_interface.h"
zend_class_entry *ebook_adapter_ce;

PHP_METHOD(ebook_adapter, construct)
{

}

PHP_METHOD(ebook_adapter, open)
{

}

PHP_METHOD(ebook_adapter, turnPage)
{

}

PHP_METHOD(ebook_adapter, getPage)
{

}

static zend_function_entry ebook_adapter_methods[] = {
    PHP_ME(ebook_adapter, construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(ebook_adapter, open,      NULL, ZEND_ACC_PUBLIC)
    PHP_ME(ebook_adapter, turnPage,  NULL, ZEND_ACC_PUBLIC)
    PHP_ME(ebook_adapter, getPage,   NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(ebook_adapter)
{
    zend_string *book_interface_name;
    zend_class_entry ebook_adapter_container_ce;

    book_interface_name = strpprintf(0, "PHPDesign\\BookInterface");

    INIT_CLASS_ENTRY(ebook_adapter_container_ce, "PHPDesign\\EBookAdapter", ebook_interface_methods);
    ebook_adapter_ce = zend_register_internal_class(&ebook_adapter_container_ce TSRMLS_CC);

    if ((book_interface_ce = zend_hash_find_ptr(CG(class_table), book_interface_name)) == NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not implement book_interface");
        return FAILURE;
    }

    zend_class_implements(ebook_adapter_ce TSRMLS_CC, 1, book_interface_ce);
    zend_string_release(book_interface_name);
    return SUCCESS;
}
