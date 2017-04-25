--TEST--
Check for php_design_patterns presence
--SKIPIF--
<?php if (!extension_loaded("php_design_patterns")) print "skip"; ?>
--FILE--
<?php
    use PHPDesign\Book;
    use PHPDesign\Kindle;
    use PHPDesign\EbookAdapter;
    $bookObj = new Book();
    $bookObj->open();
    $bookObj->turnPage();
    var_dump($bookObj->getPage());

    $kindle = new Kindle();
    $kindle->unlock();
    $kindle->pressNext();
    var_dump($kindle->getPage());

    $ebookAdapter = new EbookAdapter(new Kindle());

    $ebookAdapter->open();
    $ebookAdapter->turnPage();
    var_dump($ebookAdapter->getPage());
?>
--EXPECT--
int(2)
array(2) {
  [0]=>
  int(1)
  [1]=>
  int(100)
}
array(2) {
  [0]=>
  int(1)
  [1]=>
  int(100)
}

