#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

/* include global headers*/
#include "php_design_patterns.h"
#include "adapter/book_interface.h"
#include "adapter/book.h"
zend_class_entry *book_ce;

PHP_METHOD(book, __construct)
{
    book_ce = Z_OBJCE_P(getThis());
    zend_update_property_long(book_ce, getThis(), ZEND_STRL("page"), 0 TSRMLS_CC);
}

PHP_METHOD(book, open)
{
    book_ce = Z_OBJCE_P(getThis());
    zend_update_property_long(book_ce, getThis(), ZEND_STRL("page"), 1 TSRMLS_CC);
}

PHP_METHOD(book, turnPage)
{
    zend_long  pageNum;
    book_ce = Z_OBJCE_P(getThis());
    pageNum += Z_LVAL_P(zend_read_property(book_ce, getThis(), ZEND_STRL("page"), 0, 0 TSRMLS_CC));
    zend_update_property_long(book_ce, getThis(), ZEND_STRL("page"), pageNum TSRMLS_CC);
}

PHP_METHOD(book, getPage)
{
    zend_long pageNum;
    pageNum = Z_LVAL_P(zend_read_property(book_ce, getThis(), ZEND_STRL("page"), 0, 0 TSRMLS_CC));
    RETURN_LONG(pageNum);
}

static zend_function_entry book_methods[] = {
    PHP_ME(book, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
    PHP_ME(book, open,        NULL, ZEND_ACC_PUBLIC)
    PHP_ME(book, turnPage,    NULL, ZEND_ACC_PUBLIC)
    PHP_ME(book, getPage,     NULL, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

PHP_DESIGN_STARTUP_FUNCTION(book)
{
    zend_string *book_interface_name;
    zend_class_entry book_container_ce;

    book_interface_name = strpprintf(0, "PHPDesign\\BookInterface");

    INIT_CLASS_ENTRY(book_container_ce, "PHPDesign\\Book", book_methods);
    book_ce = zend_register_internal_class(&book_container_ce TSRMLS_CC);

    if ((book_interface_ce = zend_hash_find_ptr(CG(class_table), zend_string_tolower(book_interface_name))) ==  NULL) {
        php_error_docref(NULL TSRMLS_CC, E_ERROR, "Can not implement book interface");
        return FAILURE;
    }

    zend_class_implements(book_ce TSRMLS_CC, 1, book_interface_ce);
    zend_string_release(book_interface_name);
    return SUCCESS;
}
